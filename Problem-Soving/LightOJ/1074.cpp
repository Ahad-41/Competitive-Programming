#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct info
{
    ll u, v, w;
};

const ll N = 300;
vector<info> edge;
ll cost[N];

bool bellmanFord(ll n) {
    for (ll i = 1; i <= n; i++) cost[i] = 1e18;
    cost[1] = 0;

    for (ll i = 1; i <= n; i++) {
        for (auto &e : edge) {
            if (cost[e.u]+e.w < cost[e.v]) {
                cost[e.v] = cost[e.u]+e.w;
            }
        }
    }
}

int main(){
    ll t; cin >> t;
    for (ll k = 1; k <= t; k++) {
        cout << "Case " << k << ":" << endl;
        
        ll n; cin >> n;
        ll arr[n+1];
        for (ll i = 1; i <= n; i++) cin >> arr[i];

        edge.clear();

        ll m; cin >> m;
        for (ll i = 1; i <= m; i++) {
            ll u, v;
            cin >> u >> v;
            ll w = arr[v]-arr[u];
            edge.push_back({u, v, w*w*w});
        }

        bellmanFord(n);

        ll q; cin >> q;
        while (q--) {
            ll node; cin >> node;
            if (cost[node] < 3 || cost[node] == 1e18) cout << "?" << endl;
            else cout << cost[node] << endl;
        }
    }
}
