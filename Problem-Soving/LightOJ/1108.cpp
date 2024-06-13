#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct info
{
    ll u, v, w;
};

const ll N = 1e3+7;
vector<ll> adjList[N];
vector<info> edge;
ll cost[N];
bool isRelaxed[N], isVisited[N];

void bellmanFord(ll n) {
    for (ll i = 1; i <= n; i++) cost[i] = 1e18;
    cost[1] = 0;

    for (ll i = 1; i <= n; i++) {
        for (auto &e : edge) {
            if (cost[e.u] + e.w < cost[e.v]) {
                cost[e.v] = cost[e.u] + e.w;
                if (i == n) isRelaxed[e.v] = true;
            }
        }
    }
}

void dfs(ll currNode) {
    isVisited[currNode] = true;
    for (auto &u : adjList[currNode]) {
        if (isVisited[u] == false) dfs(u);
    }
}

int main(){
    ll t; cin >> t;
    for (ll test = 1; test <= t; test++) {
        cout << "Case " << test << ":";

        ll n, m; cin >> n >> m;

        edge.clear();
        for (ll i = 1; i <= n; i++) {
            isVisited[i] = false;
            isRelaxed[i] = false;
            adjList[i].clear();
        }

        for (ll i = 1; i <= m; i++) {
            ll u, v, w; cin >> u >> v >> w;
            u++; v++;
            edge.push_back({v, u, w});
            adjList[v].push_back(u);
        }

        bellmanFord(n);
        
        bool isCycle = false;
        for (ll i = 1; i <= n; i++) {
            if (isRelaxed[i]) {
                dfs(i);
                isCycle = true;
            }
        }
        if (!isCycle) {
            cout << " impossible" << endl;
            continue;
        }

        for (ll i = 1; i <= n; i++) {
            if (isVisited[i]) cout << " " << i-1;
        }
        cout << endl;
    }
}
