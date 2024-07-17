#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 31;
ll n, m, dp[N][N], unq[N][N][N];
string s1, s2;

ll func(ll i, ll j, ll l) {
	if (i == n and j == m) return !l;
	if (unq[i][j][l] != -1) return unq[i][j][l];

    if (i == n and j != m) return func(i, j+1, l-1);
	if (j == m and i != n) return func(i+1, j, l-1);

    ll ans;
	if (s1[i] == s2[j]) ans = func(i+1, j+1, l-1);
	else ans = func(i+1, j, l-1) + func(i, j+1, l-1);
    return unq[i][j][l] = ans;
}

ll lcs(ll i, ll j) {
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
        
    ll ans = lcs(i-1, j);
    ans = max(ans, lcs(i, j-1));
    ans = max(ans, lcs(i-1, j-1) + (s1[i] == s2[j]));
    return dp[i][j] = ans;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll tc, tt = 1; cin >> tc;

    test:
    while (tc--) {
        cout << "Case " << tt++ << ": ";
        
        cin >> s1 >> s2;
        n = s1.size();
        m = s2.size();

        memset(dp, -1, sizeof(dp));
        memset(unq, -1, sizeof(unq));
        ll length = n+m-lcs(n-1, m-1);

        cout << length << " " << func(0, 0, length) << "\n";
    }
}
