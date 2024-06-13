// May be I won't be a good programmer, but I will be a good human being.
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll n;
ll arr[20][20], dp[20][1 << 16];

ll func(ll i, ll mask) {
    if (mask == (1 << n) - 1) return 0;
    if (dp[i][mask] != -1) return dp[i][mask];

    ll ans = 0;
    for (ll j = 1; j <= n; j++) {
        if ((mask & (1 << j))) continue;
        ans = max(ans, arr[i][j]+func(i+1, mask|(1<<j)));
    }
    return dp[i][mask] = ans;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll tt = 1;
    cin >> tt;

    for (ll t = 1; t <= tt; t++) {
        cout << "Case " << t << ": "; 
        
        cin >> n;
        for (ll i = 1; i <= n; i++) for (ll j = 1; j <= n; j++) cin >> arr[i][j];
        memset(dp, -1, sizeof(dp));
        cout << func(1, 0) << endl;
    }
}
