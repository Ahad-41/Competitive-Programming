#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, lg, dp[32][2][2][31];
string s;

ll func(ll i, ll last, ll valid, ll cnt) {
    if (i == lg) return cnt;
    if (dp[i][last][valid][cnt] != -1) return dp[i][last][valid][cnt];

    ll st = 0, end = s[i]-'0';
    if (valid) end = 1;
    ll ans = 0;
    for (ll j = st; j <= end; j++) {
        ll f = valid | (j < s[i] - '0'), val = cnt + (last & j);
        ans += func(i+1, j, f, val);
    }
    
    return dp[i][last][valid][cnt] =  ans;
}


signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc, tt = 1; cin >> tc;

    test:
    while (tc--) {
        cout << "Case " << tt++ << ": ";
        cin >> n;
        s.clear();
        while (n) {
            if (n & 1) s += '1';
            else s += '0';
            n >>= 1;
        }
        reverse(s.begin(), s.end());

        lg = s.size();
        memset(dp, -1, sizeof(dp));
        cout << func(0, 0, 0, 0) << "\n";
    }
}
