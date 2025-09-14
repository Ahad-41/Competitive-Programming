#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 2e5+7;
ll n, m, startNode, endNode, parent[N], visited[N];
vector<ll> adjList[N];

bool dfs(ll currNode) { 
    visited[currNode] = 1;

    for (auto &u : adjList[currNode]) {
        if (!visited[u]) {
            parent[u] = currNode;
            if (dfs(u)) return true;
        }
        else if (visited[u] == 1) {
            endNode = currNode;
            startNode = u;
            return true;
        }
    }

    visited[currNode] = 2;
    return false;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    while (m--) {
        ll u, v; cin >> u >> v;
        adjList[u].push_back(v);
    }
    
    startNode = -1;
    for (ll i = 1; i <= n; i++) if (!visited[i] and dfs(i)) break;

    if (startNode == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<ll> cycle;
    cycle.push_back(startNode);

    ll currNode = endNode;
    while (currNode != startNode) {
        cycle.push_back(currNode);
        currNode = parent[currNode];
    } 
    cycle.push_back(startNode);
    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << "\n";
    for (auto &u : cycle) cout << u << " ";
    cout << "\n";
}
