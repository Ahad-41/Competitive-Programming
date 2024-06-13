#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

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

ll kmp(string text, string pattern) {
    vector<ll> lpsArray = calcLPS(pattern);

    ll n = text.length(), m = pattern.length();
    ll matches = 0;
    for (ll i = 0, j = 0; i < n; i++) {
        while (j > 0 and pattern[j] != text[i]) j = lpsArray[j-1];
        if (pattern[j] == text[i]) j++;
        if (j == m) {
            matches++;
            j = lpsArray[j-1];
        }
    }   

    return matches;
}

int main()
{
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);

    cout << (kmp(text, pattern) ? "Found" : "Not Found") << endl;
}
