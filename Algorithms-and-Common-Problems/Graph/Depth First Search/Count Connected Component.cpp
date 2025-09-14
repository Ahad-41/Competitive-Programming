#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 2e5+7;
vector<ll> adjList[N];
bool visited[N];

void dfs(ll currNode) {
    if (visited[currNode]) return;
    visited[currNode] = true;
    for (auto &u : adjList[currNode]) dfs(u);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin >> n >> m;

    while (m--) {
        ll u, v; cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    ll connectedComponent = 0;
    for (ll i = 1; i <= n; i++) {
        if (visited[i]) continue;
        dfs(i);
        connectedComponent++;
    }

    cout << connectedComponent;
}
