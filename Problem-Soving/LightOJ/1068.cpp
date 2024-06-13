// May be I won't be a good programmer, but I will be a good human being.
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

string s;
ll k, dp[15][100][100][2];

ll func(ll i, ll num, ll digSum, ll flag) {
    if (i == s.size()) return (num % k == 0) and (digSum % k == 0);
    if (dp[i][num][digSum][flag] != -1) return dp[i][num][digSum][flag];

    ll ans = 0, indx = (s[i]-'0');
    for (ll j = 0; j <= 9; j++) {
        if (flag and j > indx) break;
        ans += func(i+1, (num*10+j)%k, (digSum+j)%k, (j<indx? 0 : flag));
    }

    return dp[i][num][digSum][flag] = ans;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll tt = 1;
    cin >> tt;

    for (ll t = 1; t <= tt; t++) {
        cout << "Case " << t << ": ";

        ll a, b; cin >> a >> b >> k;
        if (k == 1) cout << b-a+1 << "\n";
        else if (k > 82) cout << "0\n";
        else { 
            s = to_string(a-1);
            memset(dp, -1, sizeof(dp));
            ll l = func(0, 0, 0, 1);
        
            s = to_string(b);
            memset(dp, -1, sizeof(dp));
            ll r = func(0, 0, 0, 1);

            cout << r-l << "\n";
        }
    }

    return 0;
}
