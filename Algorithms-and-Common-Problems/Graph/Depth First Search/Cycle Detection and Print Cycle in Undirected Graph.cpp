#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 2e5+7;
ll n, m, startNode, endNode, parent[N];
vector<ll> adjList[N];
bool visited[N];

bool dfs(ll currNode, ll par = -1) { 
    visited[currNode] = true;

    for (auto &u : adjList[currNode]) {
        if(u == par) continue; 
        if (visited[u]) {
            endNode = currNode;
            startNode = u;
            return true;
        }
        parent[u] = currNode;
        if (dfs(u, parent[u])) return true;
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    while (m--) {
        ll u, v; cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
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

    cout << cycle.size() << "\n";
    for (auto &u : cycle) cout << u << " ";
    cout << "\n";
}
