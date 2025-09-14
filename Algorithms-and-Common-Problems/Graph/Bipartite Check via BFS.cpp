#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const ll N = 2e5+7;
vector<ll> adjList[N];
ll visited[N], color[N];
 
signed main() {
    ll n, m; cin >> n >> m;
    
    while (m--) {
        ll u, v; cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
 
    for (ll i = 1; i <= n; i++) {
        if (visited[i]) continue;
        queue<ll> q;
        q.push(i);
        visited[i] = color[i] = 1;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            
            for (auto &u : adjList[it]) {
                if (visited[u] and color[u] == color[it]) {
                    cout << "IMPOSSIBLE";
                    return 0;
                }
                if (visited[u]) continue;
                q.push(u);
                visited[u] = 1;
                color[u] = (color[it] == 1 ? 2 : 1);
            }
        }
    }
 
    for (ll i = 1; i <= n; i++) cout << color[i] << " ";
}
