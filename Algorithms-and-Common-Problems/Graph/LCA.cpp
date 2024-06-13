#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll N = 1e7+7;
ll depth[N], parent[N][20];
vector<ll> adjList[N];

void dfs(ll curr, ll par) {
    depth[curr] = depth[par] + 1;
    parent[curr][0] = par;
    for (auto &u : adjList[curr]) if (u != par) dfs(u, curr);    
}

void preCompute(ll n) {
    for (ll i = 1; i < 20; i++) {
        for (ll node = 1; node <= n; node++) {
            if (parent[node][i-1] != -1) {
                parent[node][i] = parent[parent[node][i-1]][i-1];
            }
        }
    }
}

ll lca(ll u, ll v) {
    if (depth[v] < depth[u]) swap(u, v);
    ll diff = depth[v] - depth[u];
    for (ll i = 0; i < 20; i++) {
        if ((diff >> i) & 1) v = parent[v][i];
    }

    if (u == v) return u;

    for (ll i = 19; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int main()
{
    optimize();
    ll n, q; cin >> n >> q;

    for (ll i = 1; i < n; i++) {
        ll u, v; cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    depth[1] = 0;
    dfs(1, 1);
    preCompute(n);

    while (q--) {
        ll a, b; cin >> a >> b;
        ll lcaNode = lca(a, b);
        cout << lcaNode << endl;
    }
}