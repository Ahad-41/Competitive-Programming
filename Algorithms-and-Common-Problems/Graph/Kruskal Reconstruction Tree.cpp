// https://codeforces.com/problemset/problem/1706/E
#include <bits/stdc++.h>
using namespace std;
typedef int ll;

const ll N = 6e5+7, M = 20;
ll n, timer, Parent[N], par[N][M+1], depth[N], sz[N], inTime[N], arr[N],  mn[N][M], mx[N][M];
vector<ll> adjList[N];

ll find(ll v) {
    if (Parent[v] == v) return v;
    return Parent[v] = find(Parent[v]);
}

void Union(ll u, ll v) {
    u = find(u);
    v = find(v);
    n++;

    Parent[u] = Parent[v] = n;
    adjList[n].push_back(u);

    if (u != v) adjList[n].push_back(v);
}

void dfs(ll currNode, ll p = 0) {
    timer++;
    arr[timer] = currNode;
    inTime[currNode] = timer;

    par[currNode][0] = p;
    depth[currNode] = depth[p]+1;
    sz[currNode] = 1;
    for (ll i = 1; i <= M; i++) par[currNode][i] = par[par[currNode][i-1]][i-1];
    for (auto &u: adjList[currNode]) {
        if (u == p) continue;
        dfs(u, currNode);
        sz[currNode] += sz[u];
    }
    timer++;
}

ll lca(ll u, ll v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (ll k = M; k >= 0; k--) if (depth[par[u][k]] >= depth[v]) u = par[u][k];
    if (u == v) return u;
    for (ll k = M; k >= 0; k--) if (par[u][k] != par[v][k]) u = par[u][k], v = par[v][k];
    return par[u][0];
}
 
void buildMin(ll n) {
    for (ll i = 1; i <= n; i++) mn[i][0] = inTime[i];
    for (ll k = 1; k < M; k++) {
        for (ll i = 1; i + (1LL << k) - 1 <= n; i++) {
            mn[i][k] = min(mn[i][k-1], mn[i+(1 << (k-1))][k-1]);
        }
    }
}
 
ll queryMin(ll l, ll r) {
    ll k = 31 - __builtin_clz(r-l+1);
    return min(mn[l][k], mn[r-(1LL << k)+1][k]);
}

void buildMax(ll n) {
    for (ll i = 1; i <= n; i++) mx[i][0] = inTime[i];
    for (ll k = 1; k < M; k++) {
        for (ll i = 1; i + (1LL << k) - 1 <= n; i++) {
            mx[i][k] = max(mx[i][k-1], mx[i+(1 << (k-1))][k-1]);
        }
    }
}
 
ll queryMax(ll l, ll r) {
    ll k = 31 - __builtin_clz(r-l+1);
    return max(mx[l][k], mx[r-(1LL << k)+1][k]);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc; cin >> tc;

    test:
    while (tc--) {
        ll m, q; cin >> n >> m >> q;

        for (ll i = 1; i <= n+m; i++) {
            Parent[i] = i;
            adjList[i].clear();
        }

        ll temp = n;
        for (ll i = 1; i <= m; i++) {
            ll u, v; cin >> u >> v;
            Union(u, v);
        }
                
        timer = 0;
        dfs(n);
        buildMin(timer);
        buildMax(timer);

        while (q--) {
            ll l, r; cin >> l >> r;
            if (l == r) cout << "0 ";
            else cout << lca(arr[queryMin(l, r)], arr[queryMax(l, r)]) - temp << " ";
        }
        cout << "\n";
    }
}
