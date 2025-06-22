#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e9;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll tt = 1; cin >> tt;

    test:
    while (tt--) {
        ll n; cin >> n;
        
        ll arr[n+2] = {0};
        for (ll i = 1; i <= n; i++) cin >> arr[i];
        
        ll sum = 0, mx = 0;
        for (ll i = 1; i <= n;) {
            if (arr[i] != -1) {
                if (arr[i] >= arr[i-1]) sum += arr[i];
                else sum = arr[i];
                i++;
                mx = max(mx, sum);
                continue;
            }
            
            ll x = arr[i-1], j = i, cnt = 0;
            while (j <= n and arr[j] == -1) {
                cnt++;
                j++;
            }
            
            mx = max(mx, sum + cnt*M);
            ll sum1 = cnt*arr[j];
            if (x <= arr[j]) sum1 += sum;
            i = j;
            sum = sum1;
    
            mx = max(mx, sum);
        }

        cout << mx << "\n";
    }
}
