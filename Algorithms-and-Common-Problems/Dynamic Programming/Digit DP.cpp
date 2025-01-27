// https://cses.fi/problemset/task/2220
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
string digit;
ll dp[20][10][2][2];
 
ll func(ll indx, ll last, ll leadingZero, ll tight) {
    if (indx == digit.size()) return 1;
    if (last != -1 and dp[indx][last][leadingZero][tight]!= -1) return dp[indx][last][leadingZero][tight];

    ll ans = 0, limit = (tight ? digit[indx]-'0' : 9);
    for (ll i = 0; i <= limit; i++) {
        if (i and i == last) continue; 
        if (!leadingZero and i == last) continue;
        ans += func(indx+1, i, (leadingZero & (i==0)),  (tight & (i==limit)));
    }
    
    return dp[indx][last][leadingZero][tight]= ans;
}
 
ll uptoN(ll n) {
    digit = to_string(n);
    memset(dp, -1, sizeof(dp));
    return func(0, -1, 1, 1);
}
 
signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll a, b; cin >> a >> b;
 
    if (a == 0) cout << uptoN(b);
    else cout << uptoN(b) - uptoN(a-1);
}
