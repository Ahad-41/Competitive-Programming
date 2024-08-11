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
        double x, y, c; cin >> x >> y >> c;

        double low = 0, high = min(x, y), d = 0;
        while (high-low >= 0.0000001) {
            double mid = low + (high-low) / 2;
            
            double h1 = sqrt(x*x - mid*mid);
            double h2 = sqrt(y*y - mid*mid);
            double h = (h1*h2) / (h1+h2);

            if (h <= c) {
                d = mid;
                high = mid;
                
            }
            else low = mid;
        }

        cout << fixed << setprecision(6) << d << "\n";
    }
}
