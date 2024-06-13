#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()

ll zeroCount (ll mid) {
    ll count = 0;
    for (ll i = 5; mid / i >= 1; i *= 5) count += mid / i;
    return count;
}
 
int main()
{
    optimize();
    ll t; cin >> t;
    for (ll i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        ll q; cin >> q;

        ll low = 1, high = 1e18, n = -1;
        while (low <= high) {
            ll mid = low + (high-low) / 2;
            if (zeroCount(mid) == q) {
                n = mid;
                high = mid-1;
            }
            else if (zeroCount(mid) > q) high = mid - 1;
            else low = mid + 1;
        }

        if (n == -1) cout << "impossible\n";
        else cout << n << endl;
    }    
}  
