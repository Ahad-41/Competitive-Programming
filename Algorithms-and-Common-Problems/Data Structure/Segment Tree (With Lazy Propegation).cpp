#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 2e5+5;
ll arr[N];

struct node {
    ll sum, min, max, lazy;
} tree[N*4];

node merge(node a, node b) {
    node ans;
    ans.sum = a.sum + b.sum;
    ans.min = min(a.min, b.min);
    ans.max = max(a.max, b.max);
    ans.lazy = 0;
    return ans;
}

void apply(ll currNode, ll left, ll right, ll val) {
    tree[currNode].sum += (right-left+1) * val;
    tree[currNode].min += val;
    tree[currNode].max += val;
    tree[currNode].lazy += val;
}

void push(ll currNode, ll left, ll right) {
    if (tree[currNode].lazy == 0) return;
    if (left == right) return;

    ll mid = left + (right-left)/2;
    ll leftNode = currNode*2, rightNode = currNode*2 + 1;

    apply(leftNode, left, mid, tree[currNode].lazy);
    apply(rightNode, mid+1, right, tree[currNode].lazy);

    tree[currNode].lazy = 0;
}

void segmentTree(ll currNode, ll left, ll right) {
    if (left == right) {
        tree[currNode].sum = tree[currNode].min = tree[currNode].max = arr[left];
        tree[currNode].lazy = 0;
        return;
    }

    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;

    segmentTree(leftNode, left, mid);
    segmentTree(rightNode, mid+1, right);

    tree[currNode] = merge(tree[leftNode], tree[rightNode]);
}

void update(ll currNode, ll left, ll right, ll i, ll j, ll val) {
    if (i > right or j < left) return;
    if (left >= i and right <= j) {
        apply(currNode, left, right, val);
        return;
    }

    push(currNode, left, right);

    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;

    update(leftNode, left, mid, i, j, val);
    update(rightNode, mid+1, right, i, j, val);

    tree[currNode] = merge(tree[leftNode], tree[rightNode]);
}

node query(ll currNode, ll left, ll right, ll i, ll j) {
    if (i > right or j < left) return {0, (ll)1e18, (ll)-1e18, 0};
    if (left >= i and right <= j) return tree[currNode];
    
    push(currNode, left, right);

    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;

    node leftCalc = query(leftNode, left, mid, i, j);
    node rightCalc = query(rightNode, mid+1, right, i, j);

    return merge(leftCalc, rightCalc);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, q; cin >> n >> q;
    for (ll i = 1; i <= n; i++) cin >> arr[i];

    segmentTree(1, 1, n);

    while (q--) {
        ll type; cin >> type;
        if (type == 1) {
            ll l, r, v; cin >> l >> r >> v;
            update(1, 1, n, l, r, v);
        }
        else {
            ll l, r; cin >> l >> r;
            node ans = query(1, 1, n, l, r);
            cout << ans.sum << " " << ans.min << " " << ans.max << "\n";
        }
    }
}
