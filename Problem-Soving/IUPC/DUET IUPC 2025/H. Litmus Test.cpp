#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main() {
    ios_base::sync_with_stdio(); cin.tie();
    ll tt = 1; cin >> tt;

    test:
    while (tt--) {
        ll n; cin >> n;
        string ss; cin >> ss;
        
        ll s = 0, a = 0, b = 0;
        for (auto &u : ss) {
            if (u == 'S') s++;
            else if (u == 'B') b++;
            else a++;
        }

        if (a == n or b == n) cout << n << "\n";
        else if (a and b) cout << "1\n";
        else if (a) cout << a << "\n";
        else if (b) cout << b << "\n";
        else cout << "2\n";
    }
}
