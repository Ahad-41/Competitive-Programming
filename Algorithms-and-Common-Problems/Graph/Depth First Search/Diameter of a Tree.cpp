#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll N = 1e5 + 7;
vector<ll> adjList[N];
ll depth[N];

void dfs(ll currNode, ll parent = -1) {
    for (auto &u : adjList[currNode]) {
        if (u == parent) continue;
        depth[u] = depth[currNode] + 1;
        dfs(u, currNode);
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
    ll mxDepth = -1, mxDepthNode;
    for (ll i = 1; i <= node; i++) {
        if (mxDepth < depth[i]) {
            mxDepth = depth[i];
            mxDepthNode = i;
        }
    }

    memset(depth, 0, sizeof(depth));
    dfs(mxDepthNode);
    mxDepth = -1;

    for (ll i = 1; i <= node; i++) {
        if (mxDepth < depth[i]) {
            mxDepth = depth[i];
            mxDepthNode = i;
        }
    }

    cout << mxDepth << endl;
}