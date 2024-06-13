#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll M = 1e9+7;
const ll N = 1e6+5;
ll base1 = 29, base2 = 31, base3 = 37, pwr1[N], pwr2[N], pwr3[N], hsh1[N], hsh2[N], hsh3[N];
 
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    pwr1[0] = 1;
    pwr2[0] = 1;
    pwr3[0] = 1;
    for (ll i = 1; i < N; i++) {
        pwr1[i] = (pwr1[i-1] * base1) % M;
        pwr2[i] = (pwr2[i-1] * base2) % M;
        pwr3[i] = (pwr3[i-1] * base3) % M;
    }
 
    string s, t; cin >> s >> t;
    ll n = s.size(), m = t.size();

    if (m > n) {
        cout << 0 << endl;
        return 0;
    }
 
    ll currHash1 = 0, currHash2 = 0, currHash3 = 0;
    for (ll i = 0; i < n; i++) {
        currHash1 = ((currHash1 * base1) + (s[i] - 'a' + 1)) % M;
        currHash2 = ((currHash2 * base2) + (s[i] - 'a' + 1)) % M;
        currHash3 = ((currHash3 * base3) + (s[i] - 'a' + 1)) % M;
        hsh1[i] = currHash1;
        hsh2[i] = currHash2;
        hsh3[i] = currHash3;
    }
 
    ll targetHash1 = 0, targetHash2 = 0, targetHash3 = 0;
    for (ll i = 0; i < m; i++) {
        targetHash1 = ((targetHash1 * base1) + (t[i] - 'a' + 1)) % M;
        targetHash2 = ((targetHash2 * base2) + (t[i] - 'a' + 1)) % M;
        targetHash3 = ((targetHash3 * base3) + (t[i] - 'a' + 1)) % M;
    }
 
    ll cnt = 0;
    for (ll i = m-1; i < n; i++) {
        ll currHash1 = hsh1[i];
        if (i-m >= 0) currHash1 -= (hsh1[i-m] * pwr1[m]) % M;
        currHash1 = (currHash1 + M) % M;
 
        ll currHash2 = hsh2[i];
        if (i-m >= 0) currHash2 -= (hsh2[i-m] * pwr2[m]) % M;
        currHash2 = (currHash2 + M) % M;

        ll currHash3 = hsh3[i];
        if (i-m >= 0) currHash3 -= (hsh3[i-m] * pwr3[m]) % M;
        currHash3 = (currHash3 + M) % M;

        if (currHash1 == targetHash1 and currHash2 == targetHash2 and currHash3 == targetHash3) cnt++;
    }
    
    cout << cnt << endl;
}
