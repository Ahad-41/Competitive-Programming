ll numSubarrayProductLessThanK(vector<ll>& nums, ll k) {
    if (k <= 1) return 0;
    
    ll n = nums.size(), subArray = 0, product = 1, start = 0;
    for (ll i = 0; i < n; i++) {
        product *= nums[i];
        while (product >= k and start < n) product /= nums[start++];
        subArray += i-start+1;
    }
    
    return subArray;
}
