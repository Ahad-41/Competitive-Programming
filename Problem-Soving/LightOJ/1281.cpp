#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define all(x) (x).begin(), (x).end()
#define Pair pair<ll, ll>

const ll N = 1e4+7;
vector<vector<ll>> adjList[N];
ll cost[11][N];

void dijkstra(ll node, ll d) {
    for (ll i = 0; i <= d; i++) {
        for (ll j = 0; j < node; j++) cost[i][j] = 1e18;
    }
    cost[0][0] = 0;

    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll> >> pq;
    pq.push({0, 0, 0});

    while (!pq.empty()) {
        auto it = pq.top();
        ll currNodeCost = it[0], currK = it[1], currNode = it[2];
        pq.pop();
        
        if (currNodeCost > cost[currK][currNode]) continue;

        for (auto &u : adjList[currNode]) {
            // Relaxation
            ll tempNode = u[0];
            ll tempCost = u[1];
            ll type = u[2];

            if (currK + type <= d and cost[currK+type][tempNode] > cost[currK][currNode] + tempCost) {
                cost[currK + type][tempNode] = cost[currK][currNode] + tempCost;
                pq.push({cost[currK + type][tempNode], currK + type, tempNode});
            }
        }
    }
}

int main(){
    ll t; cin >> t;

    for (ll i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        for (auto &u : adjList) u.clear();

        ll n, m, k, d; cin >> n >> m >> k >> d;

        while (m--) {
            ll u, v, w; cin >> u >> v >> w;
            adjList[u].push_back({v, w, 0});
        }
        while (k--) {
            ll u, v, w; cin >> u >> v >> w;
            adjList[u].push_back({v, w, 1});
        }

        dijkstra(n, d);

        ll ans = 1e18;
        for (ll i = 0; i <= d; i++) {
            ans = min(ans, cost[i][n-1]);
        }

        if (ans == 1e18) cout << "Impossible" << endl;
        else cout << ans << endl;
    }
}
