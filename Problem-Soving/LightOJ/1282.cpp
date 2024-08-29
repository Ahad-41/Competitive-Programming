// From Bangladesh 2.0
#include <bits/stdc++.h>
using namespace std;
typedef int ll;

const ll M = 1000;
ll bigMod(ll base, ll power) {
    if (!power) return 1; // base case
    ll result = bigMod(base, power/2);
    result = (result * result) % M;
    if (power & 1) result = (result * base) % M;
    return result;
}

signed main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int tc, tt = 1; cin >> tc;

    test:
    while (tc--) {
        cout << "Case " << tt++ << ": ";
        ll n, k; cin >> n >> k;

        double y = k * log10(n);
        ll first = pow(10, y-(ll)y) * 100;

        printf("%d %03d\n", first, bigMod(n%1000, k));
    }
}
