#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll N = 1e5 + 7;
vector<ll> adjList[N];
ll subTreeSum[N];

void dfs(ll currNode, ll parent = -1) {
    subTreeSum[currNode] += currNode;
    for (auto &u : adjList[currNode]) {
        if (u == parent) continue;
        dfs(u, currNode);
        subTreeSum[currNode] += subTreeSum[u];
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