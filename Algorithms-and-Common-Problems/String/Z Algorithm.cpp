#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> z_function(string s) {
    ll n = s.size();
    vector<ll> z(n);

    for (ll i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) z[i] = min(z[i - l], r-i+1);

        while (i + z[i] < n and s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    string s; cin >> s;
    ll n = s.size();
    
    vector<ll> z = z_function(s);
    for (auto &u : z) cout << u << " ";  
}