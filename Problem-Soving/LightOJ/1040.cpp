#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pair;

const ll N = 55;
vector<pair<ll,ll>> adjList[N];
bool vis[N], alreadyTaken[N];

void dfs(ll currNode) {
    if (vis[currNode]) return;
    vis[currNode] = true;
    for (auto &u : adjList[currNode]) dfs(u.first);
}

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

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll tc, tt = 1; cin >> tc;

    test:
    while (tc--) {
        cout << "Case " << tt++ << ": ";
        ll n; cin >> n;
        for (ll i = 1; i <= n; i++) {
            adjList[i].clear();
            vis[i] = false;
            alreadyTaken[i] = false;
        }
        
        ll total = 0;
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                ll w; cin >> w;
                total += w;
                if (w == 0) continue;
                adjList[i].push_back({j, w});
                adjList[j].push_back({i, w});
            }
        }

        ll connectedComponent = 0;
        for (ll i = 1; i <= n; i++) {
            if (vis[i]) continue;
            dfs(i);
            connectedComponent++;
        }

        if (connectedComponent > 1) {
            cout << "-1\n";
            continue;
        }

        cout << total - mst(1) << "\n";
    }
}
