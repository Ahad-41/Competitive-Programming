#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 505;
vector <ll> adjList[N];
ll n, m, parent[N], cost[N];

ll bfs (ll rootNode) {
    for (ll i = 0; i < n; i++) {
        parent[i] = -1;
        cost[i] = 1e18;
    }
   
    queue <ll> q;
    q.push(rootNode);
    cost[rootNode] = 0;

    ll mnCycle = 1e18;
    while (!q.empty()) {
        ll currNode = q.front();
        q.pop();

        for (auto &u : adjList[currNode]) {
            if (cost[u] == 1e18) {
                cost[u] = cost[currNode]+1;
                parent[u] = currNode;
                q.push(u);
            }
            else if (parent[currNode] != u) mnCycle = min(mnCycle, cost[currNode]+cost[u]+1);
        }
    }

    return mnCycle;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc; cin >> tc;

    test:
    while (tc--) {
        cin >> n >> m;
        
        for (ll i = 0; i < n; i++) adjList[i].clear();
        while (m--) {
            ll u, v; cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        ll ans = 1e18;
        for (ll i = 0; i < n; i++) ans = min(ans, bfs(i));

        if (ans == 1e18) cout << "impossible\n";
        else cout << ans << "\n";
    }
}
