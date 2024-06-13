#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define all(x) (x).begin(), (x).end()
#define Pair pair<ll, ll>

const ll N = 1e5+7;
vector<Pair> adjList[N];
ll prevNode[N];
ll cost[N];
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

int main(){
    ll node, edge; cin >> node >> edge;
    for (auto &u : adjList) u.clear();

    while (edge--) {
        ll u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    dijkstra(node);

    // path.push_back(node);
    // while (prevNode[node] != 0) {
    //     path.push_back(prevNode[node]);
    //     node = prevNode[node];
    // }
    // reverse(all(path));
    
    // for (ll i = 1; i <= node; i++) cout << cost[i] << " ";
    // cout << endl;
}
