#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll N = 1e5 + 7;
vector<ll> adjList[N];
ll height[N], depth[N];

void dfs(ll currNode, ll parent = -1) {
    for (auto &u : adjList[currNode]) {
        if (u == parent) continue;
        depth[u] = depth[currNode] + 1;

        dfs(u, currNode);
        height[currNode] = max(height[currNode], height[u] + 1);
    }
}

int main()
{
    ll node, edge; cin >> node >> edge;
    while (edge--) {
        ll u, v; cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    dfs(1);
}