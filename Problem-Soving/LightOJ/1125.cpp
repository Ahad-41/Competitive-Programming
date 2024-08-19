#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, d, arr[205], dp[205][15][25];

ll func(ll i, ll cnt, ll mod) {
    if (cnt == m) return (mod == 0);
    if (i == n) return 0;
    if (dp[i][cnt][mod] != -1) return dp[i][cnt][mod];
    ll firstWay = func(i+1, cnt, mod);
    ll secondWay = func(i+1, cnt+1, ((mod+arr[i])%d + d) % d);
    return dp[i][cnt][mod] = (firstWay+secondWay);
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc, tt = 1; cin >> tc;

    test:
    while (tc--) {
        cout << "Case " << tt++ << ": \n";
        ll q; cin >> n >> q;
        for (ll i = 0; i < n; i++) cin >> arr[i];

        while (q--) {
            cin >> d >> m;
            memset(dp, -1, sizeof(dp));
            cout << func(0, 0, 0) << "\n";
        }
    }
}
