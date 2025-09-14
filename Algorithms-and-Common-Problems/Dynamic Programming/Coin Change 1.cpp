ll func(ll amount) {
    if (amount == 0) return 0;
    if (dp[amount] != -1) return dp[amount];

    ll ans = 1e18;
    for (auto &u : coins) if (amount - u >= 0) ans = min(ans, func(amount-u)+1);

    return dp[amount] = ans; 
}
