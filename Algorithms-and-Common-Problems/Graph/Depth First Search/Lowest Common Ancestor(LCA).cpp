#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll N = 1e5 + 7;
vector<ll> adjList[N];
ll par[N];

void dfs(ll currNode, ll parent = -1) {
    par[currNode] = parent;
    for (auto &u : adjList[currNode]) {
        if (u == parent) continue;
        dfs(u, currNode);
    }
}

vector<ll> path(ll currNode) {
    vector<ll> ans;

    while (currNode != -1) {
        ans.push_back(currNode);
        currNode = par[currNode];
    }

    reverse(ans.begin(), ans.end());
    return ans;
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

    ll x, y; cin >> x >> y;
    vector<ll> path_x = path(x);
    vector<ll> path_y = path(y);
    ll minLength = min(path_x.size(), path_y.size());

    ll lca = -1;
    for (ll i = 0; i < minLength; i++) {
        if (path_x[i] == path_y[i]) lca = path_x[i];
        else break;
    }

    cout << lca << endl;
}