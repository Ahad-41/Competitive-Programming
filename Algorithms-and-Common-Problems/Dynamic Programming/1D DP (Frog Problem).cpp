ll func(ll i) {
    if (i == 1) return 0;
    if (dp[i] != -1) return dp[i];
    
    ll mnCost = 1e18;
    for (ll j = 1; j <= k; j++) {
        if (i-j >= 1) mnCost = min(mnCost, func(i-j) + abs(arr[i] - arr[i-j]));
    }
 
    return dp[i] = mnCost;
}