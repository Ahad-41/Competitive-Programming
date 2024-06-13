// print the lcs length
ll lcs(ll i, ll j, string &s1, string &s2) {
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
        
    ll ans = lcs(i-1, j, s1, s2);
    ans = max(ans, lcs(i, j-1, s1, s2));
    ans = max(ans, lcs(i-1, j-1, s1, s2) + (s1[i] == s2[j]));
    return dp[i][j] = ans;
}
