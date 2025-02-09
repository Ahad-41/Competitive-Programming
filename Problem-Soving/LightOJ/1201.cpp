#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main() 
{             
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, tt = 1;;
    cin >> t;

    test:
    while (t--) {
        cout << "Case " << tt++ << ": ";
        ll n, m; cin >> n >> m;
        
        set<ll> adjList[n+1];
        ll in[n+1] = {0};
        while (m--) {
            ll u, v; cin >> u >> v;
            adjList[u].insert(v);
            adjList[v].insert(u);
            in[u]++;
            in[v]++;
        }
        
        set<pair<ll, ll>> s;
        for (ll i = 1; i <= n; i++) s.insert({in[i], i});
        ll vis[n+1] = {0};
        
        ll ans = 0;
        while (!s.empty()) {
            ll currNode = (*s.begin()).second;
            s.erase(s.begin());
            if (vis[currNode]) continue;
            vis[currNode] = 1;
            
            for (auto &u : adjList[currNode]) {
                for (auto &v : adjList[u]) {
                    in[v] = max(0LL, in[v]-1);
                    s.insert({in[v], v});
                }
                adjList[u].clear();
                s.erase({in[u], u});
                vis[u] = 1;
            }
            
            adjList[currNode].clear();
            ans++;
        }
        
        cout << ans << "\n";
    }
}
