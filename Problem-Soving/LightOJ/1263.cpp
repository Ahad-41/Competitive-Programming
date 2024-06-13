#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll N = 1e5 + 7;
vector<ll> adjList[N];
bool visited[N];
ll total, cnt, arr[N];

void dfs(ll currNode) {
    if (visited[currNode]) return;
    total += arr[currNode];
    cnt++;
    
    visited[currNode] = true;
    for (auto &u : adjList[currNode]) dfs(u);
}

int main()
{
    ll tt; cin >> tt;
    for (ll t = 1; t <= tt; t++) {
        cout << "Case " << t << ": ";

        ll node, edge; cin >> node >> edge;
        for (ll i = 1; i <= node; i++) {
            visited[i] = false;
            adjList[i].clear();
        }
        for (ll i = 1; i <= node; i++) cin >> arr[i];

        while (edge--) {
            ll u, v; cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        bool check = false;
        ll x = -1;
        for (ll i = 1; i <= node; i++) {
            if (visited[i]) continue;
            total = cnt = 0;
            dfs(i);
            if (total % cnt) {
                cout << "No" << endl;
                check = true;
                break;
            }
            
            if (x == -1) x = total / cnt;
            if (total/cnt != x) {
                cout << "No" << endl;
                check = true;
                break;
            }
        }

        if (check == false) cout << "Yes" << endl;
    }
    
}
