#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 2e5+7;
vector<ll> adjList[N];
ll arr[N];

/*---------------------- Graph Moves ----------------*/
//const int dx[]={+1,-1,+0,+0};
//const int dy[]={+0,+0,+1,-1};
//const int dx[]={+0,+0,+1,-1,-1,+1,-1,+1}; // Kings Move
//const int dy[]={-1,+1,+0,+0,+1,+1,-1,-1}; // Kings Move
//const int dx[]={-2, -2, -1, -1,  1,  1,  2,  2}; // Knights Move
//const int dy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

void dfs(ll currNode, ll parent = -1) {
    for (auto &u : adjList[currNode]) {
        if (u == parent) continue;
        dfs(u, currNode);
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc; cin >> tc;

    test:
    while (tc--) {
        ll n; cin >> n;
        for (ll i = 1; i <= n; i++) {
            adjList[i].clear();
            cin >> arr[i];
        }

        for (ll i = 1; i < n; i++) {
            ll u, v; cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        
    }
}
