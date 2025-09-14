ll subarraySum(vector<ll>& nums, ll k) {
    unordered_map<ll,ll> cnt;
    ll sum = 0, count = 0;
    cnt[sum] = 1;

    for (auto &u : nums) {
        sum += u;
        if (cnt.find(sum-k) != cnt.end()) count += cnt[sum-k];
        cnt[sum]++;
    }
    
    return count;
}
