#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll tt = 1; cin >> tt;

    for (ll i = 1; i <= tt; i++) {
        cout << "Case " << i << ": ";
        
        ll m, n; cin >> m >> n;
        if (m == 1 or n == 1) cout << max(m, n) << endl;
        else if (m == 2 or n == 2) {
            ll ans = ((m*n)/8)*4;
            ll temp = (m*n) % 8;
            if (temp >= 4) temp = 4;
            cout << ans+temp << endl;
        }   
        else cout << (n*m+1)/2 << endl;
    }
}
