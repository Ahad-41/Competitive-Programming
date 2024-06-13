ll knapsack(ll i, ll valueLeft) {
    if (valueLeft == 0) return 0;
    if (i < 1) return 1e15;
    if (dp[i][valueLeft] != -1) return dp[i][valueLeft];
 
    ll ans = knapsack(i - 1, valueLeft); // not taken
 
    if (valueLeft - cost[i] >= 0) {
        ans = min(ans, knapsack(i - 1, valueLeft - cost[i]) + weight[i]); // taken
    }
 
    return dp[i][valueLeft] = ans;
}