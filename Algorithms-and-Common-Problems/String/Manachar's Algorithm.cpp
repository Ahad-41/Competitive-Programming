#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
vector<ll> manachar(string s) {
    string temp;
    for (auto &u : s) {
        temp += '#';
        temp += u;
    }
    s = temp + '#';
 
    ll n = s.size();
    vector<ll> P(n);
 
    for (ll i = 1, c = 0, r = 0; i < n-1; i++) {
        ll iMirror = c - (i - c);
 
        if (r > i) P[i] = min(r-i, P[iMirror]);
        while (s[i+1+P[i]] == s[i-1-P[i]]) P[i]++;
        
        if (i+P[i] > r) {
            c = i; 
            r = i+P[i];
        }
    }
 
    return P;
}
 
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    
    string temp = s;
    reverse(s.begin(), s.end());
    if (s == temp) {
        cout << s << endl;
        return 0;
    }

    auto P = manachar(s);
    ll n = P.size(), maxPalindrome = 0, centerIndex = 0;

    for (ll i = 1; i < n-1; i++) {
        if (P[i] > maxPalindrome) {
            maxPalindrome = P[i];
            centerIndex = i;
        }
    }
 
    ll start = (centerIndex/2) - (maxPalindrome/2);
    for (ll i = start; i < start+maxPalindrome; i++) cout << s[i];
}
