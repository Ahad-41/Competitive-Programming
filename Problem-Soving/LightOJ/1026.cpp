#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll N = 1e4+5;
ll n, m, timer, disTime[N], low[N];
vector<ll> adjList[N];
bool visited[N];
vector<pair<ll, ll>> bridges;

void dfs(ll currNode, ll parent) {
    visited[currNode] = true;
    disTime[currNode] = low[currNode] = timer++;
    
    for (auto &u : adjList[currNode]) {
        if (u == parent) continue;
        if (visited[u]) low[currNode] = min(low[currNode], disTime[u]);
        else {
            dfs(u, currNode);
            low[currNode] = min(low[currNode], low[u]);
            if (disTime[currNode] < low[u]) bridges.push_back({min(currNode, u), max(currNode, u)});
        }
    }
}

int main()
{
    ll tt; cin >> tt;
    for (ll t = 1; t <= tt; t++) {
        
        cin >> n;
        timer = 0;
        bridges.clear();
        for (ll i = 0; i < n; i++) {
            adjList[i].clear();
            visited[i] = false;
            disTime[i] = low[i] = 0;
        }

        for (ll i = 0; i < n; i++) {
            ll u, v, e; cin >> u;
            char c;
            scanf("%c%c%lld%c", &c, &c, &e, &c);
            
            for (ll j = 1; j <= e; j++) {
                ll v; cin >> v;
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }

        for (ll i = 0; i < n; i++) {
            if (visited[i] == false) dfs(i, -1);
        }

        sort(bridges.begin(), bridges.end());
        cout << "Case " << t << ":" << endl;
        cout <<  bridges.size();
        cout << " critical links" << endl; 
        for (auto &u : bridges) cout << u.first << " - " << u.second << endl;
    }
}
