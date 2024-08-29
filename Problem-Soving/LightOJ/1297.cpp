#include <bits/stdc++.h>
using namespace std;
typedef double ll;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc, tt = 1; cin >> tc;

    test:
    while (tc--) {
        cout << "Case " << tt++ << ": ";
        ll l, w; cin >> l >> w;
        ll a = 12, b = -4*(l+w), c = l*w;

        ll x = (-b + sqrt(b*b - 4*a*c)) / (2*a);
        ll res1 = (l - 2 * x) * (w - 2 * x) * x;
        
        x = (-b - sqrt(b*b - 4*a*c)) / (2*a);
        ll res2 = (l-2*x) * (w-2*x) * x;

        cout << fixed << setprecision(6) << max(res1, res2) << "\n";
    }
}

/*
   for area lw-4x^2 volume is --> (l-2x) * (w-2x) * x

                                    (l-2x) * (w-2x) * x
   for area    1    volume is -->  ---------------------
                                       lw - 4x^2

                                   (l-2x) * (w-2x)x * lw
   for area   lw    volume is -->  --------------------- = 0  as when lw, hight is 0, so volume is 0.
                                         lw - 4x^2
   so, (l-2x) * (w-2x) * x = 0
   or, 12x^2 - 4(l+w)x + lw = 0
*/
