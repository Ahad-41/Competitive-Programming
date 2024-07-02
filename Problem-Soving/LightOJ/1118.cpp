#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, tt = 1; 
    cin >> t;

    test:
    while (t--) {
        cout << "Case " << tt++ << ": ";
        ll x1, y1, r1; cin >> x1 >> y1 >> r1;
        ll x2, y2, r2; cin >> x2 >> y2 >> r2;

        double dis = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        
        double ans;
        if (dis >= r1+r2) ans = 0; // No intersection
        else if (dis + r1 <= r2) ans = acos(-1)*r1*r1; // First circle totally in the second circle
        else if (dis + r2 <= r1) ans = acos(-1)*r2*r2; // Second circle totally in the first circle
        else {
            double angleA = 2 * acos((r1*r1 + dis*dis - r2*r2) / (2*r1*dis));
            double angleB = 2 *  acos((r2*r2 + dis*dis - r1*r1) / (2*r2*dis));
            ans = 0.5 * (r1*r1*angleA + r2*r2*angleB - r1*r1*sin(angleA) - r2*r2*sin(angleB));
        }
        
        cout << fixed << setprecision(20) << ans << "\n";
    }
}
