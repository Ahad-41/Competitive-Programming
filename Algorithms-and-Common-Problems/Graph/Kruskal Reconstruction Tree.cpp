// https://codeforces.com/problemset/problem/1706/E
#include <bits/stdc++.h>
using namespace std;
typedef int ll;

const ll N = 5e5+7, M = 20;
ll Parent[N], par[N][M+1], depth[N], arr[N], mx[N][M];
vector<ll> adjList[N];

ll find(ll v) {
    if (Parent[v] == v) return v;
    return Parent[v] = find(Parent[v]);
}

void Union(ll u, ll v, ll newNode) {
    u = find(u);
    v = find(v);

    Parent[u] = Parent[v] = newNode;
    adjList[newNode].push_back(u);
    adjList[newNode].push_back(v);
}

void dfs(ll currNode, ll p = 0) {
    par[currNode][0] = p;
    depth[currNode] = depth[p]+1;
    for (ll i = 1; i <= M; i++) par[currNode][i] = par[par[currNode][i-1]][i-1];
    for (auto &u: adjList[currNode]) {
        if (u == p) continue;
        dfs(u, currNode);
    }
}

ll lca(ll u, ll v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (ll k = M; k >= 0; k--) if (depth[par[u][k]] >= depth[v]) u = par[u][k];
    if (u == v) return u;
    for (ll k = M; k >= 0; k--) if (par[u][k] != par[v][k]) u = par[u][k], v = par[v][k];
    return par[u][0];
}

void build(ll n) {
    for (ll i = 1; i <= n; i++) mx[i][0] = arr[i];
    for (ll k = 1; k < M; k++) {
        for (ll i = 1; i + (1LL << k) - 1 <= n; i++) {
            mx[i][k] = max(mx[i][k-1], mx[i+(1 << (k-1))][k-1]);
        }
    }
}
 
ll query(ll l, ll r) {
    ll k = 31 - __builtin_clz(r-l+1);
    return max(mx[l][k], mx[r-(1LL << k)+1][k]);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc; cin >> tc;

    test:
    while (tc--) {
        ll n, m, q; cin >> n >> m >> q;

        for (ll i = 1; i <= n+m; i++) {
            adjList[i].clear();
            Parent[i] = i;
        }

        ll sz = 1;
        for (ll i = 1; i <= m; i++) {
            ll u, v; cin >> u >> v;
            if (find(u) == find(v)) continue; 
            sz = n+i;
            Union(u, v, sz);
        }

        dfs(sz);
        for (ll i = 2; i <= n; i++) arr[i] = lca(i, i-1);
        build(n);

        while (q--) {
            ll l, r; cin >> l >> r;
            if (l == r) cout << "0 ";
            else cout << query(l+1, r)-n << " ";
        }
        cout << "\n";
    }
}
