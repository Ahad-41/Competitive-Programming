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
        double a, b;
        char ch; 
        cin >> a >> ch >> b;
        
        double r = sqrt(a*a + b*b) / 2;
        double theta = acos((2*r*r - b*b) / (2*r*r));
        double s = r*theta;
        double x = 400.0 / (2*a + 2*s);

        cout << fixed << setprecision(6) << x*a << " " << x*b << "\n";
    }
}
