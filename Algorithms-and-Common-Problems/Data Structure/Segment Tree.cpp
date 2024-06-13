#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node {
    ll sum, max, min;
};

const ll N = 2e5+7;
ll arr[N];
node tree[N*4];

node merge(node a, node b) {
    node ans;
    ans.sum = a.sum + b.sum;
    ans.max = max(a.max, b.max);
    ans.min = min(a.min, b.min);
    return ans;
}

void segmentTree(ll currNode, ll left, ll right) {
    if (left == right) {
        tree[currNode].sum = tree[currNode].max = tree[currNode].min = arr[left];
        return;
    } 
    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;

    segmentTree(leftNode, left, mid);
    segmentTree(rightNode, mid+1, right);
    tree[currNode] = merge(tree[leftNode], tree[rightNode]);
}

// return the sum of i-th index to j-th index ->
node query(ll currNode, ll left, ll right, ll i, ll j) {
    if (i > right || j < left) return {0, 0, (ll)1e18};
    if (left >= i and right <= j) return tree[currNode];
    
    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;
    node leftCalc = query(leftNode, left, mid, i, j);
    node rightCalc = query(rightNode, mid+1, right, i, j);

    return merge(leftCalc, rightCalc);
}

// update in the i-th index with new value -> 
void update(ll currNode, ll left, ll right, ll i, ll newValue) {
    if (i > right || i < left) return;
    if (left == right) {
        tree[currNode].sum = tree[currNode].max = tree[currNode].min = newValue;
        return;
    }

    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;

    update(leftNode, left, mid, i, newValue);
    update(rightNode, mid+1, right, i, newValue);
    tree[currNode] = merge(tree[leftNode], tree[rightNode]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1; cin >> t;

    while (t--) {
        ll n, q; cin >> n >> q;
        for (ll i = 1; i <= n; i++) cin >> arr[i];
        segmentTree(1, 1, n);

        while (q--) {
            ll type; cin >> type;
            if (type == 1) {
                ll i, v; cin >> i >> v;
                update(1, 1, n, i, v);
            }
            else {
                ll l, r; cin >> l >> r;
                node ans = query(1, 1, n, l, r);
                cout << ans.sum << "\n";
            }
        }
    }

    return 0;
}
