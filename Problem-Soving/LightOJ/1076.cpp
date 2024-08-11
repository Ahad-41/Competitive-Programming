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
        ll n, m; cin >> n >> m;
        ll arr[n];
        for (auto &u : arr) cin >> u;

        ll low = 1, high = accumulate(arr, arr+n, 0LL), ans = 0;
        while (low <= high) {
            ll mid = low + (high-low) / 2;
            
            ll lagche = 1, curr = 0;
            for (auto &u : arr) {
                if (u > mid) {
                    lagche = m+1;
                    break;
                }
                if (curr+u > mid) {
                    lagche++;
                    curr = u;
                }
                else curr += u;
            }

            if (lagche <= m) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }


        cout << ans << "\n";
    }
}
