#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int main()
{
    ll t; cin >> t;
    for (ll i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";

        ll a, b, L; cin >> a >> b >> L;

        ll x = (a*b) / __gcd(a, b);
        if (L % x) {
            cout << "impossible\n";
            continue;
        }

        ll c = L / x;
        ll gcd = __gcd(c, x);
        while (gcd != 1) {
            c *= gcd;
            x /= gcd;
            gcd = __gcd(c, x);
        }

        cout << c << endl;
    }   
}  
