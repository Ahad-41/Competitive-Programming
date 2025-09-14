#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 2e5+7;
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

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin >> n >> m;

    while (m--) {
        ll u, v; cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    dfs(1);

    ll x, y; cin >> x >> y;
    vector<ll> pathX = path(x);
    vector<ll> pathY = path(y);
    ll minLength = min(pathX.size(), pathY.size());

    ll lca = -1;
    for (ll i = 0; i < minLength; i++) {
        if (pathX[i] == pathY[i]) lca = pathX[i];
        else break;
    }

    cout << lca;
}
