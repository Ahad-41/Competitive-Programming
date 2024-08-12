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
        sort(arr, arr+n);

        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            for (ll j = i+1; j < n; j++) {                       
                ll indx = upper_bound(arr, arr+n, arr[i]+arr[j]-1) - arr;
                ans += max(0LL, indx-j-1);                
            }
        }

        cout << ans << "\n";
    }
}
