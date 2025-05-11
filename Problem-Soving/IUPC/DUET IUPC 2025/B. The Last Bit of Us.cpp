#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 3e5+7;
vector<ll> adjList[N];
ll arr[N], ans;

ll dfs(ll currNode, ll par) {
    ll cnt = 0;
    for (auto &u : adjList[currNode]) {
        if (u == par) continue;
        cnt += dfs(u, currNode);
    }
    ans += cnt;
    if ((cnt & 1) and arr[currNode]) return 0;
    if (cnt % 2 == 0 and arr[currNode] == 0) return 0;
    return 1;
}

signed main() {
    ios_base::sync_with_stdio(); cin.tie();
    ll tt = 1; cin >> tt;

    test:
    while (tt--) {
        ll n; cin >> n;

        ll one = 0;
        for (ll i = 1; i <= n; i++) {
            cin >> arr[i];
            adjList[i].clear();
            if (arr[i]) one++;
        }

        for (ll i = 1; i < n; i++) {
            ll u, v; cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        if (one & 1) {
            cout << "-1\n";
            goto test;
        }
        
        ans = 0;
        dfs(1, -1);
        cout << ans << "\n";
    }
}
