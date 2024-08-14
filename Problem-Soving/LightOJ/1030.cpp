#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, arr[100];
double dp[100];

double func(ll i) {
    if (i == n) return 0;
    if (dp[i] != -1) return dp[i];

    double ans = arr[i];
    for (ll j = 1; j <= 6; j++) {
        if (i+j < n) {
            ans += (1.0/min(6LL, n-i-1)) * func(i+j);
        }
    }

    return dp[i] = ans;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc, tt = 1; cin >> tc;

    test:
    while (tc--) {
        cout << "Case " << tt++ << ": ";
        cin >> n;
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
            dp[i] = -1;
        }

        cout << fixed << setprecision(6) << func(0) << "\n";
    }
}
