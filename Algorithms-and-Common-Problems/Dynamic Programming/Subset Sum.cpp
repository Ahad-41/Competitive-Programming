bool func(ll i, ll sum) {
    if (sum == 0) return true;
    if (i < 0) return false;
    if (dp[i][sum] != -1) return dp[i][sum];

    bool isPossible = func(i-1, sum, arr);
    if (sum - arr[i] >= 0) isPossible |= func(i-1, sum - arr[i]);
    return dp[i][sum] = isPossible;
}