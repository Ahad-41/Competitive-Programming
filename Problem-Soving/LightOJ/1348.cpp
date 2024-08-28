#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
const ll N = 3e4 + 7;
vector<ll> adjList[N];
ll curr, arr[N], st[N], ending[N], depth[N], parent[N][20];
vector<ll> v;
 
void dfs(ll currNode, ll par = 1) {
    curr++;
    st[currNode] = curr;
    depth[currNode] = depth[par] + 1;
    parent[currNode][0] = par;
     
    v.push_back(arr[currNode]);
    for (auto &u : adjList[currNode]) {
        if (u == par) continue;
        dfs(u, currNode);
    }
    v.push_back(-arr[currNode]);

    curr++;
    ending[currNode] = curr;
}

void preCompute(ll n) {
    for (ll i = 1; i < 20; i++) {
        for (ll node = 1; node <= n; node++) {
            if (parent[node][i-1] != -1) parent[node][i] = parent[parent[node][i-1]][i-1];
        }
    }
}

ll lca(ll u, ll v) {
    if (depth[v] < depth[u]) swap(u, v);
    ll diff = depth[v] - depth[u];
    for (ll i = 0; i < 20; i++) if ((diff >> i) & 1) v = parent[v][i];
    if (u == v) return u;
    for (ll i = 19; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

struct node {
    ll sum, max, min;
};
node tree[N*8];

node merge(node a, node b) {
    node ans;
    ans.sum = a.sum + b.sum;
    ans.max = max(a.max, b.max);
    ans.min = min(a.min, b.min);
    return ans;
}

void segmentTree(ll currNode, ll left, ll right) {
    if (left == right) {
        tree[currNode].sum = tree[currNode].max = tree[currNode].min = v[left];
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
    ll t; cin >> t;
    for (ll j = 1; j <= t; j++) {
        cout << "Case " << j << ":\n";

        ll n; cin >> n;
        for (ll i = 1; i <= n; i++) {
            cin >> arr[i];
            adjList[i].clear();
        }
            
        for (ll i = 1; i < n; i++) {
            ll u, v; cin >> u >> v;
            u++; v++;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        v.clear();
        v.push_back(-1);
        depth[1] = curr = 0;
        dfs(1);
        preCompute(n);

        segmentTree(1, 1, 2*n);

        ll q; cin >> q;
        while (q--) {
            ll type; cin >> type;
            if (type == 0) {
                ll i, j; cin >> i >> j;
                i++; j++;
                ll l = lca(i, j);
                ll ans = query(1, 1, 2*n, st[l], st[i]).sum + query(1, 1, 2*n, st[l], st[j]).sum - v[st[l]];
                cout << ans << "\n";
            }
            else {
                ll i, val; cin >> i >> val;
                i++;
                v[st[i]] = val;
                v[ending[i]] = -val;
                update(1, 1, 2*n, st[i], val);
                update(1, 1, 2*n, ending[i], -val);
            }
        }
    }
}
