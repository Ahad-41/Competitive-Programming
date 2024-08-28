#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double dp[101][10001];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll tc, tt = 1; cin >> tc;
    
    test:
    while (tc--) {
        cout << "Case " << tt++ << ": ";
        double prob; cin >> prob;
        ll n; cin >> n;

        ll v[n+1];
        double p[n+1];
        for (ll i = 1; i <= n; i++) cin >> v[i] >> p[i];
        ll sum = accumulate(v+1, v+n+1, 0LL);
        
        for (ll i = 1; i <= n; i++) for (ll j = 0; j <= sum; j++) dp[i][j] = 0;
        dp[0][0] = 1;

        for (ll i = 1; i <= n; i++) {
            for (ll j = 0; j <= sum; j++) {
                dp[i][j] = dp[i-1][j];
                if (j < v[i]) continue;
                dp[i][j] = max(dp[i][j], dp[i-1][j-v[i]] * (1-p[i]));
            }
        }

        ll ans = 0;
        for (ll i = sum; i >= 0; i--) {
            if (dp[n][i] >= 1 - prob) {
                cout << i << "\n";
                goto test;
            }        
        }
    }
}
