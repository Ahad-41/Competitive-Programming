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
        double v1, v2, v3, a1, a2; cin >> v1 >> v2 >> v3 >> a1 >> a2;

        double t1 = v1/a1;
        double t2 = v2/a2;

        double dBird = v3 * max(t1, t2);
        double d = (v1*t1) - (0.5*a1*t1*t1);
        d += (v2*t2) - (0.5*a2*t2*t2);
    
        cout << fixed  << setprecision(6) << d << " " << dBird << "\n";
    }
}
