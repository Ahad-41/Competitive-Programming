ll lengthOfLongestSubstring(string s) {
    unordered_map <char, ll> cnt;
    
    ll start = 0, mxLength = 0;
    for (ll i = 0; i < s.size(); i++){
        if (cnt.find(s[i]) != cnt.end() and cnt[s[i]] >= start) start = cnt[s[i]]+1;
        cnt[s[i]] = i;
        mxLength = max(mxLength, i-start+1);
    }
    
    return mxLength;
}
