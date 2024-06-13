#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll N = 1e4+5;
ll n, m, timer, disTime[N], low[N];
vector<ll> adjList[N];
bool visited[N], isPoint[N];

void dfs(ll currNode, ll parent) {
    visited[currNode] = true;
    disTime[currNode] = low[currNode] = timer++;
    ll children = 0;
    
    for (auto &u : adjList[currNode]) {
        if (u == parent) continue;
        if (visited[u]) low[currNode] = min(low[currNode], disTime[u]);
        else {
            children++;
            dfs(u, currNode);
            low[currNode] = min(low[currNode], low[u]);
            if (disTime[currNode] <= low[u] and parent != -1) isPoint[currNode] = true; 
        }
    }
    if (children > 1 and parent == -1) isPoint[currNode] = true;
}

int main()
{
    ll tt; cin >> tt;
    for (ll t = 1; t <= tt; t++) {
        
        cin >> n >> m;
        timer = 0;
        for (ll i = 1; i <= n; i++) {
            adjList[i].clear();
            visited[i] = isPoint[i] = false;
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

        ll totalPoint = 0;
        for (ll i = 1; i <= n; i++) {
            totalPoint +=  (isPoint[i] == true);
        }

        cout << "Case " << t << ": " << totalPoint << endl;
    }
}
