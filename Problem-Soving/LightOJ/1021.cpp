#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1e5+7;
ll n, base, k, dp[N][20];
string s;

ll value(char c) {
    if (c >= '0' and c <= '9') return c - '0';
    return c - 'A' + 10;
}

ll func(ll mask, ll rem) {
    if (mask == (1 << n)-1) return (rem == 0);
    if (dp[mask][rem] != -1) return dp[mask][rem];

    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        if (mask & (1<<i)) continue;
        cnt += func((mask | (1<<i)), (rem*base + value(s[i])) % k);
    }

    return dp[mask][rem] = cnt;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc, tt = 1; cin >> tc;

    test:
    while (tc--) {
        cout << "Case " << tt++ << ": ";
        cin >> base >> k >> s;
        n = s.size();

        memset(dp, -1, sizeof(dp));
        cout << func(0, 0) << "\n";
    }
}
