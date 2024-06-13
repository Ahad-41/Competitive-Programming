#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll N = 1e5+5;
ll n, m, timer, disTime[N], low[N], bridgeCount;
vector<ll> adjList[N];
bool visited[N];

void dfs(ll currNode, ll parent) {
    visited[currNode] = true;
    disTime[currNode] = low[currNode] = timer++;
    
    for (auto &u : adjList[currNode]) {
        if (u == parent) continue;
        if (visited[u]) low[currNode] = min(low[currNode], disTime[u]);
        else {
            dfs(u, currNode);
            low[currNode] = min(low[currNode], low[u]);
            if (disTime[currNode] < low[u]) bridgeCount++; 
        }
    }
}

int main()
{
    ll tt; cin >> tt;
    for (ll t = 1; t <= tt; t++) {
        
        cin >> n >> m;
        timer = bridgeCount = 0;
        for (ll i = 1; i <= n; i++) {
            adjList[i].clear();
            visited[i] = false;
            disTime[i] = low[i] = 0;
        }

        for (ll i = 1; i <= m; i++) {
            ll u, v; cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        for (ll i = 1; i <= n; i++) {
            if (visited[i] == false) dfs(i, -1);
        }

        cout <<  bridgeCount << endl;
    }
}