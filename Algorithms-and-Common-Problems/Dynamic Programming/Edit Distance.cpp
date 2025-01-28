#include <bits/stdc++.h>
using namespace std;
typedef int ll;

string s, t;
ll dp[5005][5005];
 
ll func(ll i, ll j) {
    if (i < 0) return j+1;
    if (j < 0) return i+1;
    if (dp[i][j] != -1) return dp[i][j];
 
    ll ans = 1e9;
    ans = min(ans, func(i-1, j)+1);
    ans = min(ans, func(i, j-1)+1);
    ans = min(ans, func(i-1, j-1)+(s[i] != t[j]));
    return dp[i][j] = ans;
}
 
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s >> t;
    
    ll n = s.size(), m = t.size();
    if (n > m) {
        swap(s, t);
        swap(n, m);
    }
 
    memset(dp, -1, sizeof(dp));
    cout << func(n-1, m-1);
}
