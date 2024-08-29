#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll grundy(ll n) {
    if (n == 1) return 0;
    if (n & 1) return grundy((n-1)/2);
    return n;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc, tt = 1; cin >> tc;

    test:
    while (tc--) {
        cout << "Case " << tt++ << ": ";
        ll n; cin >> n;
        ll x = 0;
        while (n--) {
            ll a; cin >> a;
            x ^= grundy(a);
        }       

        cout << (x ? "Alice\n" : "Bob\n");
    }
}
