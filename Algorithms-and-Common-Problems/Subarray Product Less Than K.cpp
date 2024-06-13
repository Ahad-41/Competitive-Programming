int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        
        int subArray = 0, product = 1, start = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            product *= nums[i];
            while(product >= k and start < n) product /= nums[start++];
            subArray += i - start + 1;
        }
        
        return subArray;
}
