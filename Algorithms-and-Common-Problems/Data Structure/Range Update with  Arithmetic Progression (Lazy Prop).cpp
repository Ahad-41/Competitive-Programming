#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 2e5+7;
ll arr[N];

struct node {
    ll sum = 0, lazyA = 0, lazyD = 0;
} tree[4*N];

void segmentTree(ll currNode, ll left, ll right) {
    if (left == right) {
        tree[currNode].sum = arr[left];
        return;
    }
    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;

    segmentTree(leftNode, left, mid);
    segmentTree(rightNode, mid+1, right);
    tree[currNode].sum = tree[leftNode].sum + tree[rightNode].sum;
}

void apply(ll currNode, ll left, ll right, ll a, ll d) {
    ll sz = right-left+1;
    tree[currNode].sum += sz*a + (sz*(sz-1)/2)*d;
    tree[currNode].lazyA += a;
    tree[currNode].lazyD += d;
}

void push(ll currNode, ll left, ll right) {
    if (tree[currNode].lazyA == 0 and tree[currNode].lazyD == 0) return;
    
    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;
    ll left_sz = mid-left+1;

    apply(leftNode, left, mid, tree[currNode].lazyA, tree[currNode].lazyD);
    apply(rightNode, mid+1, right, tree[currNode].lazyA + tree[currNode].lazyD * left_sz, tree[currNode].lazyD);

    tree[currNode].lazyA = tree[currNode].lazyD = 0;
}

void update(ll currNode, ll left, ll right, ll i, ll j, ll a, ll d) {
    if (j < left or right < i) return;
    if (i <= left and right <= j) {
        ll sz = left - i;
        apply(currNode, left, right, a + d*sz, d);
        return;
    }
    push(currNode, left, right);

    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;
    update(leftNode, left, mid, i, j, a, d);
    update(rightNode, mid+1, right, i, j, a, d);
    tree[currNode].sum = tree[leftNode].sum + tree[rightNode].sum;
}

ll query(ll currNode, ll left, ll right, ll i, ll j) {
    if (j < left or right < i) return 0;
    if (i <= left and right <= j) return tree[currNode].sum;
    push(currNode, left, right);

    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;
    return query(leftNode, left, mid, i, j) + query(rightNode, mid+1, right, i, j);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, q; cin >> n >> q;
    for (ll i = 1; i <= n; i++) cin >> arr[i];
    segmentTree(1, 1, n);

    while (q--) {
        ll type; cin >> type;
        if (type == 1) {
            ll p, x; cin >> p >> x;
            ll l = max(p-x+1, 1LL), r = p;
            update(1, 1, n, l, r, 1, 1);
        } 
        else {
            ll l, r; cin >> l >> r;
            cout << query(1, 1, n, l, r) << "\n";
        }
    }
}
