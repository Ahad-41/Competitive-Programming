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

        string m1, m2; 
        ll d1, d2, y1, y2; 
        char ch;
        cin >> m1 >> d1 >> ch >> y1;
        cin >> m2 >> d2 >> ch >> y2;

        if (m1 != "January" and m1 != "February") y1++;
        if (m2 == "January" or (m2 == "February" and d2 < 29)) y2--;
        
        ll ans = y2/4 - (y1-1)/4;
        ans += y2/400 - (y1-1)/400;
        ans -= y2/100 - (y1-1)/100;

        cout << ans << "\n";
    }
}
