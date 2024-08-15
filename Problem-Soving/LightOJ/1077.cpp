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
        ll a, b, c, d; cin >> a >> b >> c >> d;
        cout << __gcd(abs(a-c), abs(b-d)) + 1 << "\n";
    }
}
