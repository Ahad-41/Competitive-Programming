#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc; cin >> tc;

    test:
    while (tc--) {
        ll n; cin >> n;
        ll arr[n];
        for (auto &u : arr) cin >> u;

        if (n > 20) {
            cout << "0\n";
            goto test;
        }

        ll ans = 1e18;
        for (ll i = 1; i < (1LL << n)-1; i++) {
            ll x = 0, y = 0;
            for (ll j = 0; j < n; j++) {
                if (i & (1LL << j)) x ^= arr[j];
                else y |= arr[j];
            }
            ans = min(ans, x*y);
        }       

        cout << ans << "\n";
    }
}
