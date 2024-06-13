#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define all(x) (x).begin(), (x).end()
#define Pair pair<ll, ll>

const ll N = 105;
vector<Pair> adjList[N];
ll cost[N];

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
            if (cost[u.first] > currNodeCost + u.second) {
                cost[u.first] = currNodeCost + u.second;
                pq.push({cost[u.first], u.first});
            }
        }
    }
}

int main(){
    ll t; cin >> t;

    for (ll i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        for (auto &u : adjList) u.clear();
        ll node, edge; cin >> node >> edge;

        while (edge--) {
            ll u, v, w;
            cin >> u >> v >> w;
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }

        dijkstra(node);

        if (cost[node] == 1e18) cout << "Impossible" << endl;
        else cout << cost[node] << endl;
    }
}
