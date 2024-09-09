// From Bangladesh 2.0
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1005;
ll n, dp[N];
string s;

bool isPalindrome(ll l, ll r) {
    ll sz = r-l+1;
    for (ll i = 0; i <= sz/2; i++) {
        if (s[l+i] != s[r-i]) return false;
    }
    return true;
}

ll func(ll l) {
    if (l >= n) return 0;
    if (dp[l] != -1) return dp[l];

    ll ans = 1e18;
    for (ll i = l; i < n; i++) {
        if (isPalindrome(l, i)) ans = min(ans, 1+func(i+1));
    }

    return dp[l] = ans;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc, tt = 1; cin >> tc;

    test:
    while (tc--) {
        cout << "Case " << tt++ << ": ";

        cin >> s;
        n = s.size();
        memset(dp, -1, sizeof(dp));
        cout << func(0) << "\n";
    }
}
