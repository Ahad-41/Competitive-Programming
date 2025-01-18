#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1e4 + 7;
vector<pair<ll, ll>> adjList[N];
bool alreadyTaken[N];

ll mst(ll currNode) {
    priority_queue<pair<ll, ll>> pq;
    pq.push({0, currNode});
    ll minCost = 0;

    while (!pq.empty()) {
        ll cost = -pq.top().first;
        currNode = pq.top().second;
        pq.pop();
        if (alreadyTaken[currNode] == true) continue;
        
        minCost += cost;
        alreadyTaken[currNode] = true;
        
        for (auto &u : adjList[currNode]) {
            if (alreadyTaken[u.first] == false) {
                pq.push({-u.second, u.first});
            }
        }         
    } 

    return minCost;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc, tt = 1; cin >> tc;

    test:
    while (tc--) {
        cout << "Case " << tt++ << ": ";
        
        ll n, m, a; cin >> n >> m >> a;
        for (ll i = 1; i <= n; i++) {
            adjList[i].clear();
            alreadyTaken[i] = false;
        }

        while (m--) {
            ll u, v, w; cin >> u >> v >> w;
            if (w < a) {
                adjList[u].push_back({v, w});
                adjList[v].push_back({u, w});
            }
        }

        ll ans = 0, cc = 0;
        for (ll i = 1; i <= n; i++) {
            if (alreadyTaken[i]) continue;
            ans += mst(i);
            cc++;
        }

        cout << ans + cc*a << " " << cc << "\n";
    }
}
