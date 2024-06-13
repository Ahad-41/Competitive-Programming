int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        int sum = 0, count = 0;
        cnt[sum] = 1;
        
        for(auto u : nums){
            sum += u;
            if(cnt.find(sum-k) != cnt.end()) count += cnt[sum-k];
            
            cnt[sum]++;
        }
        
        return count;
}
