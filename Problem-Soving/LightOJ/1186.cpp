#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc, tt = 1; cin >> tc;

    test:
    while (tc--) {
        cout << "Case " << tt++ << ": ";
        ll n; cin >> n;
        ll arr[n];
        for (auto &u : arr) cin >> u;

        ll x = 0;
        for (ll i = 0; i < n; i++) {
            ll a; cin >> a;
            x ^= (a-arr[i]-1);
        }

        cout << (x ? "white" : "black") << " wins\n";
        
    }
}
