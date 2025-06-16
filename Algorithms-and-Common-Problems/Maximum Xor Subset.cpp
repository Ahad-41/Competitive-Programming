#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
 
    ll arr[n];
    for (auto &u : arr) cin >> u;
 
    ll indx = 0;
    for (ll i = 31; i >= 0; i--) {
        ll mx = -1e18, mxIndx = indx;
        for (ll j = indx; j < n; j++) {
            if ((arr[j] & (1 << i)) and arr[j] > mx) {
                mxIndx = j;
                mx = arr[j];
            }
        }
        
        if (mx == -1e18) continue;
        swap(arr[indx], arr[mxIndx]);
        mxIndx = indx;
        
        for (ll j = 0; j < n; j++) {
            if ((arr[j] & (1 << i)) && j != mxIndx) arr[j] = arr[j]^mx;
        }
        indx++;
    }
    
    ll ans = 0;
    for (ll i = 0; i < n; i++) ans ^= arr[i];
    cout << ans;
}
