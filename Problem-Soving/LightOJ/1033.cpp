#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> Pair;
#define all(a) (a).begin(), (a).end()
void answer();

ll dp[105][105];
string s;

ll func(ll i, ll j) {
    if (i >= j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    ll ans = 1e18;
    if (s[i] != s[j]) {
        ans = min(ans, func(i+1, j)+1);
        ans = min(ans, func(i, j-1)+1);
    } 
    else ans = min(ans, func(i+1, j-1));
    
    return dp[i][j] = ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll tt = 1;
    cin >> tt;

    for (ll i = 1; i <= tt; i++) {
        cout << "Case " << i << ": ";
        answer();
    }

    return 0;
}

void answer() {
    cin >> s;
    memset(dp, -1, sizeof(dp));
    ll n = s.size();
    ll ans = func(0, n-1);
    cout << ans << endl;
}
