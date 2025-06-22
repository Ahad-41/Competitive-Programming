#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e9;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll tt = 1; cin >> tt;

    test:
    while (tt--) {
        ll n, m; cin >> n >> m;
        
        pair<ll, pair<ll, ll>> p[m];
        for (auto &u : p) cin >> u.second.first >> u.second.second >> u.first;
        sort(p, p+m);

        vector<ll> ans(n+1, -1);
        for (auto &u : p) {
            ll x = u.second.first;
            ll y = u.second.second;
            ll w = u.first;
            if (ans[x] == -1 and ans[y] == -1) {
                ans[x] = w;
                ans[y] = w;
            }
            else if (ans[x] == -1) ans[x] = w;
            else if (ans[y] == -1) ans[y] = w;
            else {
                if (max(ans[x], ans[y]) != w) {
                    cout << "-1\n";
                    goto test;
                }
            }
        }
        for (ll i = 1; i <= n; i++) {
            if (ans[i] == -1) ans[i] = M;
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
