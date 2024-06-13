ll func(ll length) {
    if (length == 0) return 0;
    if (dp[length] != -1) return dp[length];
        
    ll ans = 0;
    for (ll lenToCut = 1; lenToCut <= prices.size(); lenToCut++) {
        if (length >= lenToCut) {
            ans = max(ans, func(length - lenToCut) + prices[lenToCut-1]);
        }
    }
        
    return dp[length] = ans;
}