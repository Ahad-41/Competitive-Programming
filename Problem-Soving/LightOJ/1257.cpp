#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct info {
    ll v, w;
};

const ll N = 3e4 + 7;
vector<info> adjList[N];
ll cost[N];

void dfs(ll currNode, ll parent) {
    for (auto &u : adjList[currNode]) {
        if (u.v == parent) continue;
        cost[u.v] = max(cost[u.v], cost[currNode] + u.w);
        dfs(u.v, currNode);
    }
}

int main()
{
    ll t; cin >> t;
    for (ll j = 1; j <= t; j++) {
        cout << "Case " << j << ":\n";

        ll node; cin >> node;
        for (ll i = 0; i < node; i++) adjList[i].clear();

        for (ll i = 1; i < node; i++) {
            ll u, v, w; cin >> u >> v >> w;
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }

        // first
        memset(cost, 0, sizeof(cost));
        dfs(0, -1);
        ll mxcost = 0, mxcostNode;
        for (ll i = 0; i < node; i++) {
            if (mxcost < cost[i]) {
                mxcost = cost[i];
                mxcostNode = i;
            }
        }

        // second
        memset(cost, 0, sizeof(cost));
        dfs(mxcostNode, -1);
        mxcost = 0;
        for (ll i = 0; i < node; i++) {
            if (mxcost < cost[i]) {
                mxcost = cost[i];
                mxcostNode = i;
            }
        }
        ll mxDis[node] = {0};
        for (ll i = 0; i < node; i++) mxDis[i] = max(mxDis[i], cost[i]);

        // third
        memset(cost, 0, sizeof(cost));
        dfs(mxcostNode, -1);
        mxcost = 0;
        for (ll i = 0; i < node; i++) mxDis[i] = max(mxDis[i], cost[i]);

        for (ll i = 0; i < node; i++) cout << mxDis[i] << endl;
    }
}
