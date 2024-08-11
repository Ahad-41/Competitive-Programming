#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll M = 100000007;
const ll N = 105;
ll n, k, arr[N], dp[N][10001];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc, tt = 1; cin >> tc;

    while (tc--) {
        cout << "Case " << tt++ << ": ";
        cin >> n >> k;
        for (ll i = 1; i <= n; i++) cin >> arr[i];
        sort(arr + 1, arr + n + 1);

        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1; 

        for (ll i = 1; i <= n; i++) {
            for (ll j = 0; j <= k; j++) {
                dp[i][j] = dp[i-1][j];
                if (j >= arr[i]) {
                    dp[i][j] = (dp[i][j] + dp[i][j-arr[i]]) % M;
                }
            }
        }

        cout << dp[n][k] << "\n";
    }
}
