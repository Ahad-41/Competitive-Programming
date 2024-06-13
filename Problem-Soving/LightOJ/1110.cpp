#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll N = 105;
ll vis[N][N];
string dp[N][N], s1, s2;

string lcs(ll i, ll j) {
    string ans = "";
    if (i < 0 or j < 0) return ans;
    if (vis[i][j] != -1) return dp[i][j];
    vis[i][j]++;

    if (s1[i] == s2[j]) ans = lcs(i-1, j-1) + s1[i];
    else {
        string a = lcs(i-1, j);
        string b = lcs(i, j-1);
        if (a.size() == b.size()) ans = min(a, b);
        else ans = a.size() > b.size() ? a : b;
    }

    return dp[i][j] = ans;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;
    for (ll i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        
        cin >> s1 >> s2;
        ll n = s1.size(), m = s2.size();
        for (ll j = 0; j < n; j++) {
            for (ll k = 0; k < m; k++){
                dp[j][k].clear();
                vis[j][k] = -1;
            }
        }
        
        string ans = lcs(n-1, m-1);
        if (ans.empty()) ans = ":("; 
        cout << ans << "\n";
    }

    return 0;
}
