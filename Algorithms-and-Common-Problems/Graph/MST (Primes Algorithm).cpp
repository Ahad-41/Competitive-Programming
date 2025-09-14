#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pair;

const ll N = 2e5+7;
vector<pair<ll, ll>> adjList[N];
bool alreadyTaken[N];
ll n, m;

ll mst(ll currNode) {
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    pq.push({0, currNode});
    ll minCost = 0;

    while (!pq.empty()) {
        ll cost = pq.top().first;
        currNode = pq.top().second;
        pq.pop();
        if (alreadyTaken[currNode] == true) continue;
        
        minCost += cost;
        alreadyTaken[currNode] = true;
        
        for (auto &u : adjList[currNode]) {
            if (alreadyTaken[u.first] == false) {
                pq.push({u.second, u.first});
            }
        }         
    } 

    return minCost;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    
    while (m--) {
        ll u, v, w; cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    cout << mst(1) << "\n";
}
