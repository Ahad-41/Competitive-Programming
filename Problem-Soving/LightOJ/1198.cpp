#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[50], b[50], dp[50][50];

ll func(ll i, ll j) {
    if (i == n or j == n) return 0;
    if (dp[i][j]!= -1) return dp[i][j];

    ll ans;
    if (a[i] > b[j]) ans = 2 + func(i+1, j+1);
    else if (a[i] < b[j]) ans = func(i+1, j);
    else ans = max(1+func(i+1, j+1), func(i+1, j));

    return dp[i][j] = ans;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc, tt = 1; cin >> tc;

    test:
    while (tc--) {
        cout << "Case " << tt++ << ": ";
        cin >> n;
        for (ll i = 0; i < n; i++) cin >> a[i];       
        for (ll i = 0; i < n; i++) cin >> b[i];       
        sort(a, a+n);
        sort(b, b+n);

        memset(dp, -1, sizeof(dp));
        cout << func(0, 0) << "\n";
    }
}
