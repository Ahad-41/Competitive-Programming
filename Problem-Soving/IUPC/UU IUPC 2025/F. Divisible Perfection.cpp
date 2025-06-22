#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll tt = 1; cin >> tt;

    test:
    while (tt--) {
        ll n; cin >> n;
        string s; cin >> s;

        if (n >= 5){
            cout << "NO\n";
            goto test;
        }
        
        for (ll i = 0; i < n; i++) {
            string temp;
            for (ll j = i; j < n; j++) {
                temp += s[j];
                ll aa = stoi(temp);
                if (aa % (j-i+1)) {
                    cout << "NO\n";
                    goto test;
                }
            }
        }

        cout << "YES\n";        
    }
}
