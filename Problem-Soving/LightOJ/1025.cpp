// May be I won't be a good programmer, but I will be a good human being.
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> Pair;

string s; 
ll dp[61][61];

ll func(ll i, ll j) {
    if (i >= j) return (i == j);
    if (dp[i][j] != -1) return dp[i][j];

    ll ans = func(i+1, j) + func(i, j-1);
    if (s[i] == s[j]) ans++;
    else ans -= func(i+1, j-1);
    return dp[i][j] = ans;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll tt = 1;
    cin >> tt;

    for (ll t = 1; t <= tt; t++) {
        cout << "Case " << t << ": ";
        cin >> s;
        memset(dp, -1, sizeof(dp));
        cout << func(0, s.size()-1) << "\n";
    }

    return 0;
}
