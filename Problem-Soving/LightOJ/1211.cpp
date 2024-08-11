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

        ll mxX1 = 0, mxY1 = 0, mxZ1 = 0, mnX2 = 1e9, mnY2 = 1e9, mnZ2 = 1e9;
        while (n--) {
            ll x1, y1, z1, x2, y2, z2; cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            mxX1 = max(mxX1, x1);
            mxY1 = max(mxY1, y1);
            mxZ1 = max(mxZ1, z1);
            
            mnX2 = min(mnX2, x2);
            mnY2 = min(mnY2, y2);
            mnZ2 = min(mnZ2, z2);
        }

        if (mnX2 > mxX1 and mnY2 > mxY1 and mnZ2 > mxZ1) cout << (mnX2-mxX1) * (mnY2-mxY1) * (mnZ2-mxZ1) << "\n";
        else cout << "0\n";
    }
}
