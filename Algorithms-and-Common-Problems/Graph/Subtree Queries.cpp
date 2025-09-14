#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 2e5+7;
vector<ll> adjList[N], traverse;
ll arr[N], indx[N], subTreeSize[N], sz[N], value[N];

void dfs(ll currNode, ll parent = -1) {
    subTreeSize[currNode] = 1;
    traverse.push_back(currNode);
    for (auto &u : adjList[currNode]) {
        if (u == parent) continue;
        dfs(u, currNode);
        subTreeSize[currNode] += subTreeSize[u];
    }
}

struct node {
    ll sum, max, min;
} tree[N*4];

node merge(node a, node b) {
    node ans;
    ans.sum = a.sum + b.sum;
    ans.max = max(a.max, b.max);
    ans.min = min(a.min, b.min);
    return ans;
}

void segmentTree(ll currNode, ll left, ll right) {
    if (left == right) {
        tree[currNode].sum = tree[currNode].max = tree[currNode].min = value[left];
        return;
    } 
    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;

    segmentTree(leftNode, left, mid);
    segmentTree(rightNode, mid+1, right);
    tree[currNode] = merge(tree[leftNode], tree[rightNode]);
}

node query(ll currNode, ll left, ll right, ll i, ll j) {
    if (i > right or j < left) return {0, 0, (ll)1e18};
    if (left >= i and right <= j) return tree[currNode];
    
    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;
    node leftCalc = query(leftNode, left, mid, i, j);
    node rightCalc = query(rightNode, mid+1, right, i, j);

    return merge(leftCalc, rightCalc);
}

void update(ll currNode, ll left, ll right, ll i, ll newValue) {
    if (i > right or i < left) return;
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


signed main() {
    ll n, q; cin >> n >> q;
    for (ll i = 1; i <= n; i++) cin >> arr[i];

    for (ll i = 1; i < n; i++) {
        ll u, v; cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    traverse.push_back(0);
    dfs(1);

    for (ll i = 1; i <= n; i++) sz[i] = subTreeSize[traverse[i]];
    for (ll i = 1; i <= n; i++) value[i] = arr[traverse[i]];
    for (ll i = 1; i <= n; i++) indx[traverse[i]] = i;
    // ---------------------------------------------------------
    // for (ll i = 1; i <= n; i++) cout << traverse[i] << " ";
    // cout << endl;
    

    // for (ll i = 1; i <= n; i++) cout << sz[i] << " ";
    // cout << endl;
    
    // for (ll i = 1; i <= n; i++) cout << value[i] << " ";
    // cout << endl;

    // for (ll i = 1; i <= n; i++) cout << indx[i] << " ";
    // cout << endl;
    // --------------------------------------------------------

    segmentTree(1, 1, n);
    while (q--) {
        ll type; cin >> type;
        if (type == 1) {
            ll i, val; cin >> i >> val;
            update(1, 1, n, indx[i], val);
        }
        else {
            ll root; cin >> root;
            cout << query(1, 1, n, indx[root], indx[root]+sz[indx[root]]-1).sum << "\n";
        }
    }
}
