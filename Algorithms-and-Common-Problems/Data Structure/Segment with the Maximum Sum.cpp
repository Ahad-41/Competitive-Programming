#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node {
    ll sum, pref, suff, best;
};

const ll N = 1e5+7;
ll arr[N];
node tree[N*4];

node merge(node a, node b) {
    node ans;
    ans.sum = a.sum + b.sum;
    ans.pref = max(a.pref, a.sum + b.pref);
    ans.suff = max(b.suff, a.suff + b.sum);
    ans.best = max({a.best, b.best, a.suff + b.pref});
    return ans;
}

void segmentTree(ll currNode, ll left, ll right) {
    if (left == right) {
        tree[currNode].sum = arr[left];
        tree[currNode].pref = tree[currNode].suff = tree[currNode].best = max(0LL, arr[left]);
        return;
    } 
    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;

    segmentTree(leftNode, left, mid);
    segmentTree(rightNode, mid+1, right);
    tree[currNode] = merge(tree[leftNode], tree[rightNode]);
}

// update in the i-th index with new value -> 
void update(ll currNode, ll left, ll right, ll i, ll newValue) {
    if (i > right || i < left) return;
    if (left == right) {
        tree[currNode].sum = newValue;
        tree[currNode].pref = tree[currNode].suff = tree[currNode].best = max(0LL, newValue);
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
    ll t = 1; 
    //cin >> t;

    while (t--) {
        ll n, q; cin >> n >> q;
        for (ll i = 1; i <= n; i++) cin >> arr[i];
        
        segmentTree(1, 1, n);
        cout << tree[1].best << endl;


        while (q--) {
            ll i, v; cin >> i >> v;
            i++;
            update(1, 1, n, i, v);
            cout << tree[1].best << endl;
        }
    }

    return 0;
}
