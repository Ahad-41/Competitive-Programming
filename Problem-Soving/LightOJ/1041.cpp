#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, string> Pair;

map<string, vector<pair<string,ll> >> adjList;
map<string, bool> vis, alreadyTaken;

void dfs(string currNode) {
    if (vis[currNode]) return;
    vis[currNode] = true;
    for (auto &u : adjList[currNode]) dfs(u.first);
}

ll mst(string currNode) {
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    pq.push({0, currNode});
    ll minCost = 0;
    alreadyTaken.clear();

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
        
        adjList.clear();
        set<string> city;
        for (ll i = 1; i <= n; i++) {
            string u, v; cin >> u >> v;
            ll cost; cin >> cost;

            adjList[u].push_back({v, cost});
            adjList[v].push_back({u, cost});
            
            city.insert(u);
            city.insert(v);
        }

        ll connectedComponent = 0;
        vis.clear();
        for (auto &u : city) {
            if (vis[u]) continue;
            dfs(u);
            connectedComponent++;
        }

        if (connectedComponent > 1) {
            cout << "Impossible\n";
            continue;
        }

        cout << mst(*city.begin()) << "\n";
    }
}
