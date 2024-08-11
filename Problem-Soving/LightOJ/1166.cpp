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
        for (ll i = 0; i < n; i++) {
            if (arr[i] == i+1) continue;
            for (ll j = i+1; j < n; j++) {
                if (arr[j] == i+1) {
                    swap(arr[i], arr[j]);
                    ans++;
                    break;
                }
            }
        }

        cout << ans << "\n";       
    }
}
