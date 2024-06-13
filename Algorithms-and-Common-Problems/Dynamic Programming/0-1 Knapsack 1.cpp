ll knapsack(ll i, ll weightLeft) {
    if (weightLeft == 0) return 0;
    if (i < 1) return 0;
    if (dp[i][weightLeft] != -1) return dp[i][weightLeft];
 
    ll ans = knapsack(i - 1, weightLeft); // not taken
 
    if (weightLeft - weight[i] >= 0) {
        ans = max(ans, knapsack(i - 1, weightLeft - weight[i]) + cost[i]); // taken
    }
 
    return dp[i][weightLeft] = ans;
}