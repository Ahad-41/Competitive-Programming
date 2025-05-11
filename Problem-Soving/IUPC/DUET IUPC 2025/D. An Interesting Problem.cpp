#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main() {
    ios_base::sync_with_stdio(); cin.tie();
    ll tt = 1; cin >> tt;

    test:
    while (tt--) {
        ll n; cin >> n;
        string s; cin >> s;

        set<ll> st;
        for (auto &u : s) st.insert(u);
        
        if (st.size() == n) cout << "YES\n";
        else cout << "NO\n";
    }
}
