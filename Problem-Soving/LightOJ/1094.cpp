#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct info
{
    ll v, w;
};


const ll N = 3e4 + 7;
vector<info> adjList[N];
ll cost[N];

void dfs(ll currNode, ll parent) {
    for (auto &u : adjList[currNode]) {
        if (u.v == parent) continue;
        cost[u.v] = cost[currNode] + u.w;
        dfs(u.v, currNode);
    }
}

int main()
{
    ll t; cin >> t;
    for (ll j = 1; j <= t; j++) {
        cout << "Case " << j << ": ";

        ll node; cin >> node;
        for (ll i = 0; i < node; i++) {
            adjList[i].clear();
            cost[i] = 0;
        }

        for (ll i = 1; i < node; i++) {
            ll u, v, w; cin >> u >> v >> w;
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }

        dfs(0, -1);
        ll mxcost = -1, mxcostNode;
        for (ll i = 0; i < node; i++) {
            if (mxcost < cost[i]) {
                mxcost = cost[i];
                mxcostNode = i;
            }
        }

        memset(cost, 0, sizeof(cost));
        dfs(mxcostNode, -1);
        mxcost = -1;

        for (ll i = 0; i < node; i++) mxcost = max(mxcost, cost[i]);

        cout << mxcost << endl;
    }
}
