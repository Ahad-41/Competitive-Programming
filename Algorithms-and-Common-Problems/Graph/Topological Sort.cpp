#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 2e5+7;
vector<ll> adjList[N], topSortArray;
ll n, m, inDegree[N];

void topSort() {
    queue <ll> q;
    for (ll i = 1; i <= n; i++) if (inDegree[i] == 0) q.push(i);
    
    while (!q.empty()) {
        ll currNode = q.front();
        q.pop();
        topSortArray.push_back(currNode);

        for (auto &u : adjList[currNode]) {
            inDegree[u]--;
            if (inDegree[u] == 0) q.push(u); 
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    while (m--) {
        ll u, v; cin >> u >> v;
        adjList[u].push_back(v);
        inDegree[v]++;
    }

    topSort();
    for (auto &u : topSortArray) cout << u << " ";
    cout << "\n";
}
