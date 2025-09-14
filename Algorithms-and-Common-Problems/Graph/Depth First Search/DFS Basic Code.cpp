#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1}; // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1}; // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2}; // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

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
}
