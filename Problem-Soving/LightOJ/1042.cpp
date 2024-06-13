// May be I won't be a good programmer, but I will be a good human being.
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> Pair;
#define all(a) (a).begin(), (a).end()
void answer();

string binaryString(ll n) {
    string s;
    while (n) {
        s += (n & 1 ? '1' : '0');
        n >>= 1;
    }
    reverse(all(s));
    return s;
}

ll binaryNumber(string s) {
    ll n = 0, p = 1;
    reverse(all(s));
    for (auto &u : s) {
        n += p*(u-'0');
        p <<= 1;
    }
    return n;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll tt = 1;
    cin >> tt;

    for (ll t = 1; t <= tt; t++) {
        cout << "Case " << t << ": ";
        answer();
    }

    return 0;
}

void answer() {
    ll n; cin >> n;
    ll setBit = __builtin_popcount(n);

    string s = binaryString(n);
    ll sz = s.size(), indx = -1;
    for (ll i = sz-1; i > 0; i--) {
        if (s[i] == '1' and s[i-1] == '0') {
            s[i] = '0';
            s[i-1] = '1';
            indx = i+1;
            break;
        }
    }

    if (indx == -1) {
        s = '1' + s;
        s[1] = '0';
        indx = 1;
        sz++;
    }

    ll cnt = 0;
    for (ll i = indx; i < sz; i++) if (s[i] == '1') cnt++;
    for (ll i = sz-1; i >= indx; i--) {
        if (cnt) {
            cnt--;
            s[i] = '1';
        }
        else s[i] = '0';
    }

    cout << binaryNumber(s) << "\n";
}
