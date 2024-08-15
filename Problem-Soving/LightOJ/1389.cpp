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
        ll n; cin >> n;
        string s; cin >> s;

        ll cnt = 0, i = 0;
        while (i < n) {
            if (s[i] == '#') i++;
            else {
                i += 3;
                cnt++;
            }
        }    

        cout << cnt << "\n";   
    }
}
