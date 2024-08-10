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

        ll arr[n];
        for (auto &u : arr) cin >> u;
        
        ll ans = 0;
        if (arr[0] > 2) ans = (arr[0]-2+4)/5;
        for (ll i = 1;  i < n; i++) {
            if (arr[i] > arr[i-1]) ans += (arr[i]-arr[i-1]+4)/5;
        }

        cout << ans << "\n";       
    }
}
