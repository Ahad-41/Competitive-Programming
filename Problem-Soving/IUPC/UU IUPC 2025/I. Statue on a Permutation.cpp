#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll tt = 1; cin >> tt;

    test:
    while (tt--) {
        ll n; cin >> n;
        string s; cin >> s;
      
        for (ll i = 0; i < n-1; i++) {
            if (s[i] == 'B' and s[i+1] == 'B') {
                cout << "-1\n";
                goto test;
            }
        }

        ll b = count(s.begin(), s.end(), 'B');
        if (b == 0) {
            cout << "-1\n";
            goto test;
        }

        ll ans[n], c = 1;
        for (ll i = 0; i < n; i++) {
            if (s[i] == 'B') {
                ans[i] = c;
                c++;
            }
        }

        for (ll i = 0; i < n; i++) {
            if (s[i] == 'A') {
                ans[i] = c;
                c++;
            }
        }

        if (s[0] != 'B') {
            ll c = 0;
            for (ll i = 0; i < n; i++) {
                if (s[i] == 'A') c++;
                else break;
            }
            reverse(ans, ans+c);
        }
        
        for (auto &u : ans) cout << u << " ";
        cout << "\n";
    }
}
