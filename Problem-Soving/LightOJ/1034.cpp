#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll N = 1e4 + 7;
vector<ll> adjList[N], topo;
bool visited[N];

void dfs1(ll currNode) {
    if (visited[currNode]) return;
    visited[currNode] = true;
    for (auto &u : adjList[currNode]) dfs1(u);
    topo.push_back(currNode);
}

void dfs2(ll currNode) {
    if (visited[currNode]) return;
    visited[currNode] = true;
    for (auto &u : adjList[currNode]) dfs2(u);
}

int main()
{
    ll tt; cin >> tt;
    for (ll t = 1; t <= tt; t++) {
        ll node, edge; cin >> node >> edge;
        for (ll i = 1; i <= node; i++) {
            visited[i] = false;
            adjList[i].clear();
        }

        while (edge--) {
            ll u, v; cin >> u >> v;
            adjList[u].push_back(v);
        }
        
        topo.clear();
        for (ll i = 1; i <= node; i++) {
            if (visited[i]) continue;
            dfs1(i);
        }

        ll connectedComponent = 0;
        memset(visited, false, sizeof(visited));
        reverse(topo.begin(), topo.end());
        
        for (auto &u : topo) {
            if (visited[u]) continue;
            dfs2(u);
            connectedComponent++;
        }

        cout << "Case " << t << ": " << connectedComponent << endl;
    }
}
