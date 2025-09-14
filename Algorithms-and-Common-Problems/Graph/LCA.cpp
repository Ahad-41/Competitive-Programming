#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 2e5+7, M = 20;
vector<ll> adjList[N];
ll par[N][M+1], depth[N], sz[N];

void dfs(ll currNode, ll p = 0) {
    par[currNode][0] = p;
    depth[currNode] = depth[p] + 1;
    sz[currNode] = 1;
    for (ll i = 1; i <= M; i++) par[currNode][i] = par[par[currNode][i - 1]][i - 1];
    for (auto &u: adjList[currNode]) {
        if (u == p) continue;
        dfs(u, currNode);
        sz[currNode] += sz[u];
    }
}

ll lca(ll u, ll v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (ll k = M; k >= 0; k--) if (depth[par[u][k]] >= depth[v]) u = par[u][k];
    if (u == v) return u;
    for (ll k = M; k >= 0; k--) if (par[u][k] != par[v][k]) u = par[u][k], v = par[v][k];
    return par[u][0];
}

ll kth(ll u, ll k) {
    assert(k >= 0);
    for (ll i = 0; i <= M; i++) if (k & (1 << i)) u = par[u][i];
    return u;
}

ll dist(ll u, ll v) {
    ll l = lca(u, v);
    return depth[u] + depth[v] - (depth[l] << 1);
}

//kth node from u to v, 0th node is u
ll go(ll u, ll v, ll k) {
    ll l = lca(u, v);
    ll d = depth[u] + depth[v] - (depth[l] << 1);
    assert(k <= d);
    if (depth[l] + k <= depth[u]) return kth(u, k);
    k -= depth[u] - depth[l];
    return kth(v, depth[v] - depth[l] - k);
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;

    for (ll i = 1; i < n; i++) {
        ll u, v; cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    dfs(1);
    ll q; cin >> q;
    while (q--) {
        ll u, v; cin >> u >> v;
        cout << dist(u, v) << "\n";
    }
}
