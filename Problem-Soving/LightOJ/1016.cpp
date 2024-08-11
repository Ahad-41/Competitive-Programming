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
        ll n, w; cin >> n >> w;
        ll arr[n];
        for (auto &u : arr) cin >> u >> u;

        sort(arr, arr+n);
        ll ans = 1, last = arr[0];
        for (ll i = 1; i < n; i++) {
            if (arr[i] > last+w) {
                ans++;
                last = arr[i];
            }
        }     

        cout << ans << "\n";  
    }
}
