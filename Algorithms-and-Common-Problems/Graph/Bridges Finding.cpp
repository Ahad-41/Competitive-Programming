#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 2e5+7;
ll n, m, timer, disTime[N], low[N], bridgeCount;
vector<ll> adjList[N];
bool visited[N];

void dfs(ll currNode, ll par) {
    visited[currNode] = true;
    disTime[currNode] = low[currNode] = timer++;
    
    for (auto &u : adjList[currNode]) {
        if (u == par) continue;
        if (visited[u]) low[currNode] = min(low[currNode], disTime[u]);
        else {
            dfs(u, currNode);
            low[currNode] = min(low[currNode], low[u]);
            if (disTime[currNode] < low[u]) bridgeCount++; 
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll tc; cin >> tc;

    test:
    while (tc--) {
        cin >> n >> m;

        timer = bridgeCount = 0;
        for (ll i = 1; i <= n; i++) {
            adjList[i].clear();
            visited[i] = false;
            disTime[i] = low[i] = 0;
        }

        for (ll i = 1; i <= m; i++) {
            ll u, v; cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        for (ll i = 1; i <= n; i++) if (visited[i] == false) dfs(i, -1);
        cout <<  bridgeCount << "\n";
    }
}
