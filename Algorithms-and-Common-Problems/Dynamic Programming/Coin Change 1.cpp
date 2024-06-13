ll func(ll amount) {
    if (amount == 0) return 0;
    if (dp[amount] != -1) return dp[amount];

    ll ans = INT_MAX;
    for (auto &u : coins) {
        if (amount - u >= 0) {
            ans = min(ans + 0LL, func(amount - u, coins) + 1LL);
        }
    }

    return dp[amount] = ans; 
}