#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll N = 1e5+7;
vector<ll> adjList[N], revAdjList[N], order, component;
ll n, m, visited[N];

void dfs1(ll currNode) {
    if (visited[currNode] == 1) return;

    visited[currNode]++;
    for (auto &u : adjList[currNode]) dfs1(u);
    order.push_back(currNode);
}

void dfs2(ll currNode) {
    if (visited[currNode] == 2) return;

    visited[currNode]++;
    component.push_back(currNode);
    for (auto &u : revAdjList[currNode]) dfs2(u);
}

void scc() {
    for (ll i = 1; i <= n; i++) dfs1(i);
    reverse(order.begin(), order.end());

    for (auto &u : order) {
        if (visited[u] == 2) continue; 
        dfs2(u);
        // work on this connected component
        component.clear();
    }
}

int main()
{
    cin >> n >> m;

    while (m--) {
        ll u, v; cin >> u >> v;
        if (u != v) {
            adjList[u].push_back(v);
            revAdjList[v].push_back(u);
        }
    }

    scc();
}