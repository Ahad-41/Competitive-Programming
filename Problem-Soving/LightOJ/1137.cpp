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
        double l, n, c; cin >> l >> n >> c;
        double l_ = (1+n*c)*l;

        double low = 0, high = 1e19, ans = 0;
        for (ll i = 1; i <= 100; i++) {
            double r = (low + high) / 2.0;

            double theta = l_ / r;   
            double chord = 2*r*sin(theta/2);

            if (chord < l) {
                low = r;
            }
            else {
                ans = r - r * cos(theta / 2);
                high = r;
            }
        }
        cout << fixed << setprecision(10) << ans << "\n";
    }
}
