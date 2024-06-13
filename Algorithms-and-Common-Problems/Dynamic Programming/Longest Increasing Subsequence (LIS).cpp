ll lis(ll i) {
    if (dp[i] != -1) return dp[i];
    ll ans = 1;
    for (ll j = 0; j < i; j++) {
        if (arr[j] < arr[i]) {
            ans = max(ans, lis(j) + 1);
        }
    }
    return dp[i] = ans;
}


-----------------------------------------------

vector<ll> lis;
for (auto &u : arr) {
    auto it = lower_bound(lis.begin(), lis.end(), u);
    if (it == lis.end()) lis.push_back(u);
    else *it = u;
}
cout << lis.size();

---------------------------------------------
