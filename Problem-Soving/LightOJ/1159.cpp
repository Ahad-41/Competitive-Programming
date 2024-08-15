#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string a, b, c; 
ll dp[50][50][50];

ll func(ll i, ll j, ll k) {
    if (i < 0 or j < 0 or k < 0) return 0;
    if (dp[i][j][k] != -1) return dp[i][j][k];

    ll ans;
    if (a[i] == b[j] and a[i] == c[k]) ans = 1 + func(i-1, j-1, k-1);
    else {
        ans = func(i-1, j, k);
        ans = max(ans, func(i, j-1, k));
        ans = max(ans, func(i, j, k-1));
    }

    return dp[i][j][k] = ans;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc, tt = 1; cin >> tc;

    test:
    while (tc--) {
        cout << "Case " << tt++ << ": ";
        cin >> a >> b >> c;

        memset(dp, -1, sizeof(dp));
        cout << func(a.size()-1, b.size()-1, c.size()-1) << "\n";
    }
}
