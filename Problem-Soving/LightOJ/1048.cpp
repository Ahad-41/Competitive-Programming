#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc, tt = 1; cin >> tc;

    test:
    while (tc--) {
        cout << "Case " << tt++ << ": ";
        ll n, k; cin >> n >> k;
        n++; k++;

        ll arr[n];
        for (auto &u : arr) cin >> u;

        ll low = *max_element(arr, arr+n), high = accumulate(arr, arr+n, 0LL), mx;
        while (low <= high) {
            ll mid = low + (high-low) / 2;
            
            ll lagbe = 1, sum = 0;
            for (auto &u : arr) {
                if (sum+u <= mid) sum += u;
                else {
                    lagbe++;
                    sum = u;
                }
            }

            if (lagbe <= k) {
                mx = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        ll curr = 0;
        vector<ll> ans;
        for (ll i = 0; i < n; i++) {
            if (curr + arr[i] > mx or n-i+1 == k) {
                k--;
                ans.push_back(curr);
                curr = arr[i];
            }
            else curr += arr[i];
        }
        ans.push_back(curr);
        
        cout << mx << "\n";
        for (auto &u : ans) cout << u << "\n";
    }
}
