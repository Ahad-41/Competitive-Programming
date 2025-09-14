#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll booths(string s) {
    s += s;
    vector<ll> failure(s.size(), -1);
    ll mnRotationIndx = 0;

    for (ll i = 1; i < s.size(); i++) {
        char currentChar = s[i];
        ll failureIdx = failure[i-mnRotationIndx-1];

        while (failureIdx != -1 and currentChar != s[mnRotationIndx + failureIdx + 1]) {
            if (currentChar < s[mnRotationIndx + failureIdx + 1]) mnRotationIndx = i-failureIdx-1;
            failureIdx = failure[failureIdx];
        }

        if (currentChar != s[mnRotationIndx+failureIdx+1]) {
            if (currentChar < s[mnRotationIndx]) mnRotationIndx = i;
            failure[i-mnRotationIndx] = -1;
        }
        else failure[i - mnRotationIndx] = failureIdx + 1;    
    }

    return mnRotationIndx;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    ll i = booths(s);
    cout << s.substr(i) + s.substr(0, i);
}
