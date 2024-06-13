#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define all(x) (x).begin(), (x).end()
#define Pair pair<ll, ll>

struct info
{
    ll u, v, w;
};


const ll N = 1e4+7;
vector<Pair> adjList[2][N];

vector<ll> dijkstra(ll source, ll n, ll type) {
    vector<ll> cost(n+1);
    for (ll i = 0; i <= n; i++) cost[i] = 1e18;
    cost[source] = 0;

    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        ll currNode = pq.top().second;
        ll currNodeCost = pq.top().first;
        pq.pop();
        
        if (currNodeCost > cost[currNode]) continue;

        for (auto &u : adjList[type][currNode]) {
            // Relaxation
            if (cost[u.first] > currNodeCost + u.second) {
                cost[u.first] = currNodeCost + u.second;
                pq.push({cost[u.first], u.first});
            }
        }
    }

    return cost;
}

int main()
{
    ll t; cin >> t;
    for (ll i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";

        for (auto &u : adjList[0]) u.clear();
        for (auto &u : adjList[1]) u.clear();

        ll n, m, s, t, p; 
        cin >> n >> m >> s >> t >> p;

        vector<info> edge;
        while (m--) {
            ll u, v, w;
            cin >> u >> v >> w;
            adjList[0][u].push_back({v, w});
            adjList[1][v].push_back({u, w});
            edge.push_back({u, v, w});
        }

        vector<ll> fromSource = dijkstra(s, n, 0);
        vector<ll> fromDestination = dijkstra(t, n, 1);

        ll ans = -1;
        for (auto &e : edge) {
            ll cost = fromSource[e.u] + fromDestination[e.v] + e.w;
            if (cost <= p) {
                ans = max(ans, e.w);
            }
        }
        
        cout << ans << endl;

    }
}
