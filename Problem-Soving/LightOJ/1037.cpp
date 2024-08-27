#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = (1<<15);
ll n, health[15], arr[15][15], dp[N];

ll func(ll mask) {
    if (mask == (1<<n)-1) return 0;
    if (dp[mask] != -1) return dp[mask];

    ll ans = 1e18;
    for (ll i = 0; i < n; i++) {
        if (mask & (1<<i)) continue; 
        ll mx = 1;
        for (ll j = 0; j < n; j++) if (mask & (1<<j)) mx = max(mx, arr[j][i]); 
        ans = min(ans, ((health[i]+mx-1)/mx) + func(mask|(1<<i)));
    }

    return dp[mask] = ans;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc, tt = 1; cin >> tc;

    while (tc--) {
        cout << "Case " << tt++ << ": ";
        cin >> n;
        for (ll i = 0; i < n; i++) cin >> health[i];
        for (ll i = 0; i < n; i++) {
            string s; cin >> s;
            for (ll j = 0; j < n; j++) arr[i][j] = s[j]-'0';
        }
        
        memset(dp, -1, sizeof(dp));
        cout << func(0) << "\n";
    }
}
