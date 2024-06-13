#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()

int main()
{
    optimize();
    ll t; cin >> t;
    
    for(ll k = 1; k <= t; k++){
        ll n; cin >> n;
        ll a[n*2 - 1][n];
        memset(a, 0, sizeof(a));
        
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j <= i; j++) cin >> a[i][j];
        }

        ll x = 1;
        for(ll i = n; i < n*2 - 1 ; i++){
            for(ll j = x; j < n; j++){
                cin >> a[i][j];
            }
            x++;
        }

        ll ans[2*n - 1][n];
        memset(ans, 0, sizeof(ans));
        ans[0][0] = a[0][0];

        for(ll i = 1; i < n; i++){
            for(ll j = 0; j <= i; j++){
                if(j == 0) ans[i][j] = ans[i-1][j] + a[i][j];
                else ans[i][j] = max(ans[i-1][j], ans[i-1][j-1]) + a[i][j]; 
            }
        }
        x = 1;
        for(ll i = n; i < n*2 - 1; i++){
            for(ll j = x; j < n; j++){
                ans[i][j] = max(ans[i-1][j], ans[i-1][j-1]) + a[i][j];
            }
            x++;
        }

        cout << "Case " << k << ": " << ans[2*n-2][n-1] << endl;



              

    }
    
}
