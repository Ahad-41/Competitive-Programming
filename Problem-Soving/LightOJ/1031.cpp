#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[101], dp[101][101];

ll func(ll i, ll j) {
    if (i > j) return 0;
    if (i == j) return arr[j]-arr[i-1];
    if (dp[i][j] != -1) return dp[i][j];

    ll ans = arr[j]-arr[i-1];
    for (ll k = i; k <= j; k++) {
        ll temp = arr[k]-arr[i-1]-func(k+1, j);
        ans = max(ans, temp);

        temp = arr[j]-arr[k-1]-func(i, k-1);
        ans = max(ans, temp);
    }

    return dp[i][j] = ans;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc, tt = 1; cin >> tc;

    test:
    while (tc--) {
        cout << "Case " << tt++ << ": ";
        ll n; cin >> n;

        for (ll i = 1; i <= n; i++) {
            cin >> arr[i];
            arr[i] += arr[i-1];
        }

        memset(dp, -1, sizeof(dp));
        cout << func(1, n) << "\n";
    }
}
