#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
const ll M = 1e9+7;
const ll N = 1e6+5;
ll base = 31, pwr[N], hsh[N];
 
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    pwr[0] = 1;
    for (ll i = 1; i < N; i++) pwr[i] = (pwr[i-1] * base) % M;
    
    string s; cin >> s;
    ll n = s.size();
    s = '#' + s;
 
    for (ll i = 1; i <= n; i++) hsh[i] = ((hsh[i-1] * base) + (s[i] - 'a' + 1)) % M;
 
    for (ll i = 1; i < n; i++) {
        
        
    }
}
