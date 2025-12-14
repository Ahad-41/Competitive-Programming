#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 2e5+7;
vector<ll> adjList[N], traverse;
ll arr[N], indx[N], subTreeSize[N], sz[N], newArray[N];

void dfs(ll currNode, ll parent = -1) {
    subTreeSize[currNode] = 1;
    traverse.push_back(currNode);
    for (auto &u : adjList[currNode]) {
        if (u == parent) continue;
        dfs(u, currNode);
        subTreeSize[currNode] += subTreeSize[u];
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ll tt; cin >> tt;

    test:
    while (tt--) {
        ll n; cin >> n;

        for (ll i = 1; i <= n; i++) {
            cin >> arr[i];
            adjList[i].clear();
        }
        
        for (ll i = 1; i < n; i++) {
            ll u, v; cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        traverse.clear();
        traverse.push_back(0);
        dfs(1);

        for (ll i = 1; i <= n; i++) sz[i] = subTreeSize[traverse[i]];
        for (ll i = 1; i <= n; i++) newArray[i] = arr[traverse[i]];
        for (ll i = 1; i <= n; i++) indx[traverse[i]] = i;
        
        /* -------------------------------------------------------
        for (ll i = 1; i <= n; i++) cout << traverse[i] << " ";
        cout << endl;

        for (ll i = 1; i <= n; i++) cout << sz[i] << " ";
        cout << endl;
        
        for (ll i = 1; i <= n; i++) cout << newArray[i] << " ";
        cout << endl;

        for (ll i = 1; i <= n; i++) cout << indx[i] << " ";
        cout << endl;
        -------------------------------------------------------- */
        

        // segmentTree(1, 1, n);
        // query(1, 1, n, indx[i], indx[i]+sz[indx[i]]-1);
    }
}
