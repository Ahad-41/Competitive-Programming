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
        map<ll, ll> cnt;
        for (auto &u : arr) {
            cin >> u;
            cnt[u]++;
        }

        ll ans = 0;
        for (auto &[x, y] : cnt) {
            ll repeat = y / (x+1);
            if (y % (x+1)) repeat++; 
            ans += repeat * (x+1);
        }

        
        cout << ans << "\n";
    }
}
