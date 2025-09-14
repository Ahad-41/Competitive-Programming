#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 2e5+7;
vector<ll> adjList[N];
ll height[N], depth[N];

void dfs(ll currNode, ll parent = -1) {
    for (auto &u : adjList[currNode]) {
        if (u == parent) continue;
        depth[u] = depth[currNode] + 1;

        dfs(u, currNode);
        height[currNode] = max(height[currNode], height[u] + 1);
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin >> n >> m;

    while (m--) {
        ll u, v; cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    dfs(1);
}
