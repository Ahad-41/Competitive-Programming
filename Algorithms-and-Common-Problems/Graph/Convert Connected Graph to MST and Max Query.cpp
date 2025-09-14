#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef pair<ll, ll> Pair;
typedef pair<Pair, ll> Tuple;

const ll N = 5e4+7, M = 19;
vector<pair<ll, ll>> adjList[N];
ll par[N][M+1], depth[N], sz[N], mn[N][M+1], mx[N][M+1];
bool alreadyTaken[N];
vector<Tuple> v;

void mst() {
    v.clear();
    priority_queue<Tuple> pq;
    pq.push({{0, 1}, 1});

    while (!pq.empty()) {
        ll cost = -pq.top().first.first;
        ll currNode = pq.top().first.second;
        ll lastNode = pq.top().second;
        pq.pop();
        if (alreadyTaken[currNode] == true) continue;
        
        alreadyTaken[currNode] = true;
        if (cost) v.push_back({{lastNode, currNode}, cost});

        for (auto &u : adjList[currNode]) {
            if (alreadyTaken[u.first] == false) {
                pq.push({{-u.second, u.first}, currNode});
            }
        }         
    } 
}

void dfs(ll u, ll p = 0, ll w = 0) {
    par[u][0] = p;
    mn[u][0] = w;
    mx[u][0] = w;
    depth[u] = depth[p] + 1;
    sz[u] = 1;
    for (ll i = 1; i <= M; i++) {
        par[u][i] = par[par[u][i-1]][i-1];
        mn[u][i] = min(mn[u][i-1], mn[par[u][i-1]][i-1]);
        mx[u][i] = max(mx[u][i-1], mx[par[u][i-1]][i-1]);
    }
    for (auto v : adjList[u]) if (v.first != p) {
        dfs(v.first, u, v.second);
        sz[u] += sz[v.first];
    }
}

ll lca(ll u, ll v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (ll k = M; k >= 0; k--) if (depth[par[u][k]] >= depth[v]) u = par[u][k];
    if (u == v) return u;
    for (ll k = M; k >= 0; k--) if (par[u][k] != par[v][k]) u = par[u][k], v = par[v][k];
    return par[u][0];
}

ll getMin(ll u, ll lca) {
    ll minWeight = 1e18;
    for (ll k = M; k >= 0; k--) {
        if (depth[par[u][k]] >= depth[lca]) {
            minWeight = min(minWeight, mn[u][k]);
            u = par[u][k];
        }
    }
    return minWeight;
}

ll getMax(ll u, ll lca) {
    ll maxWeight = 0;
    for (ll k = M; k >= 0; k--) {
        if (depth[par[u][k]] >= depth[lca]) {
            maxWeight = max(maxWeight, mx[u][k]);
            u = par[u][k];
        }
    }
    return maxWeight;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll tc; cin >> tc;

    test:
    while (tc--) {
        ll n, m; cin >> n >> m;

        for (ll i = 1; i <= n; i++) {
            adjList[i].clear();
            alreadyTaken[i] = false;
            sz[i] = depth[i] = 0;
            for (ll j = 0; j <= M; j++) {
                par[i][j] = mx[i][j] = 0;
                mn[i][j] = 0;
            }
        }

        for (ll i = 1; i <= m; i++) {
            ll u, v, w; cin >> u >> v >> w;
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }

        mst();
        for (ll i = 1; i <= n; i++) adjList[i].clear();
        for (auto &u : v) {
            adjList[u.first.first].push_back({u.first.second, u.second});
            adjList[u.first.second].push_back({u.first.first, u.second});
        }
        
        dfs(1);
        ll q; cin >> q;
        while (q--) {
            ll u, v; cin >> u >> v;
            ll l = lca(u, v);
            cout << max(getMax(u, l), getMax(v, l)) << "\n";
        }
    }
}
