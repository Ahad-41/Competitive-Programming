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
        ll x = 0, one = 0;
        for (ll i = 1; i <= n; i++) {
            ll a; cin >> a;
            x ^= a;
            if (a == 1) one++;
        }

        if (one == n) cout << (one % 2 == 0 ? "Alice\n" : "Bob\n");
        else cout << (x ? "Alice\n" : "Bob\n");
    }
}
