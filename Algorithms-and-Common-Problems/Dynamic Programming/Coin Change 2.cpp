ll func(ll i, ll amount) {
    if (amount == 0) return 1;
    if (i < 0) return 0;

    if (dp[i][amount] != -1) return dp[i][amount];

    ll ways = 0;
    for (ll c = 0; c <= amount; c += coins[i]) {
        ways += func(i-1, amount - c);
    }

    return dp[i][amount] = ways; 
}