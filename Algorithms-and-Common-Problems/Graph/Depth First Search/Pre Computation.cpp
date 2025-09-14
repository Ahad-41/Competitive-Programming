#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 2e5+7;
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

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin >> n >> m;
    
    while (m--) {
        ll u, v; cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    dfs(1);
}
