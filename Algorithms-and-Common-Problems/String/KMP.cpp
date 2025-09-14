#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> calcLPS(string s) {
    ll n = s.length();
    vector<ll> lpsArray(n);
    for (ll i = 1, j = 0; i < n; i++) {
        while (j > 0 and s[j] != s[i]) j = lpsArray[j-1];
        if (s[j] == s[i]) j++;
        lpsArray[i] = j;
    }   

    return lpsArray;
}

ll kmp(string s, string t) {
    vector<ll> lpsArray = calcLPS(t);

    ll n = s.length(), m = t.length();
    ll matches = 0;
    for (ll i = 0, j = 0; i < n; i++) {
        while (j > 0 and t[j] != s[i]) j = lpsArray[j-1];
        if (t[j] == s[i]) j++;
        if (j == m) {
            matches++;
            j = lpsArray[j-1];
        }
    }   

    return matches;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s, t;
    getline(cin, s);
    getline(cin, t);

    cout << (kmp(s, t) ? "Found\n" : "Not Found\n");
}
