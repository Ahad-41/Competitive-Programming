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
        double a, b, c, d; cin >> a >> b >> c >> d;

        double right=(b*b - d*d + (a-c)*(a-c)) / (2*(a-c));
        double area= (a+c) * 0.5 * sqrt(b*b - right*right);
        cout << fixed << setprecision(6) << area << "\n";
    }
}
