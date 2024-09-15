#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m, n, man[50][3], women[50][3], propose[50], husband[50];

bool findWomen(ll currMan) {
    for (ll i = 0; i < n; i++) {
        if (abs(women[i][0]-man[currMan][0]) > 12 or abs(women[i][1]-man[currMan][1]) > 5 or women[i][2] != man[currMan][2]) continue;
        if (propose[i]) continue;
        propose[i] = true;
        if (husband[i] == -1 or findWomen(husband[i])) {
            husband[i] = currMan;
            return true;
        }
    }
    return false;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc, tt = 1; cin >> tc;

    test:
    while (tc--) {
        cout << "Case " << tt++ << ": ";
        cin >> m >> n;
        for (ll i = 0; i < m; i++) cin >> man[i][0] >> man[i][1] >> man[i][2];
        for (ll i = 0; i < n; i++) cin >> women[i][0] >> women[i][1] >> women[i][2];

        memset(husband, -1, sizeof(husband));
        ll ans = 0;
        for (ll i = 0; i < m; i++) {
            memset(propose, false, sizeof(propose));
            ans += findWomen(i);
        }

        cout << ans << "\n";
    }
}
