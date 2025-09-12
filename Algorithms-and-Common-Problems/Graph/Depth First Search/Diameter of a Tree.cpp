#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1e5+7;
vector<ll> adjList[N];
ll depth[N];

void dfs(ll currNode, ll parent = -1) {
    for (auto &u : adjList[currNode]) {
        if (u == parent) continue;
        depth[u] = depth[currNode]+1;
        dfs(u, currNode);
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ll n, m; cin >> n >> m;

    while (m--) {
        ll u, v; cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    dfs(1);
    ll mxDepthNode = max_element(depth+1, depth+n+1) - depth;

    memset(depth, 0, sizeof(depth));
    dfs(mxDepthNode);
    ll diameter = *max_element(depth+1, depth+n+1);

    cout << diameter;
}
