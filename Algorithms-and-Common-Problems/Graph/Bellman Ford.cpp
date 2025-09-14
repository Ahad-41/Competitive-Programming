#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct info {
    ll u, v, w;
};

const ll N = 2e5+7;
vector<info> edge;
ll cost[N];

bool bellmanFord(ll n, ll m) {
    for (ll i = 0; i <= n; i++) cost[i] = 1e18;
    cost[0] = 0;

    bool isCycle = false;
    for (ll i = 1; i <= n; i++) {
        isCycle = false;
        for (auto &e : edge) {
            if (cost[e.u]+e.w < cost[e.v]) {
                cost[e.v] = cost[e.u]+e.w;
                isCycle = true;
            }
        }
        if (isCycle == false) break;
    }

    return isCycle;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll tc; cin >> tc;

    test:
    while (tc--) {
        ll n, m; cin >> n >> m;
        edge.clear();

        for (ll i = 1; i <= m; i++) {
            ll u, v, w; cin >> u >> v >> w;
            edge.push_back({u, v, w});
        }

        bool isCycle = bellmanFord(n, m);
        cout << (isCycle ? "Is Cycle Here" : "No Cycle") << "\n";
    }
}
