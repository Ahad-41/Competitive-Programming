#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pair;

const ll N = 2e5+7;
vector<Pair> adjList[N];
ll prevNode[N], cost[N];
vector<ll> path;

void dijkstra(ll node) {
    for (ll i = 0; i <= node; i++) cost[i] = 1e18;
    cost[1] = 0;

    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        ll currNode = pq.top().second;
        ll currNodeCost = pq.top().first;
        pq.pop();
        
        if (currNodeCost > cost[currNode]) continue;

        for (auto &u : adjList[currNode]) {
            // Relaxation
            if (cost[u.first] > cost[currNode] + u.second) {
                cost[u.first] = cost[currNode] + u.second;
                // prevNode[u.first] = currNode;
                pq.push({cost[u.first], u.first});
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie();

    ll n, m; cin >> n >> m;
    for (auto &u : adjList) u.clear();

    while (m--) {
        ll u, v, w; cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    dijkstra(n);

    // path.push_back(node);
    // while (prevNode[node] != 0) {
    //     path.push_back(prevNode[node]);
    //     node = prevNode[node];
    // }
    // reverse(all(path));
    
    // for (ll i = 1; i <= node; i++) cout << cost[i] << " ";
    // cout << "\n";
}
