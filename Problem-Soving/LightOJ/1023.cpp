// May be I won't be a good programmer, but I will be a good human being.
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> Pair;
#define all(a) (a).begin(), (a).end()
void answer();

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll tt = 1;
    cin >> tt;

    for (ll t = 1; t <= tt; t++) {
        cout << "Case " << t << ":\n";
        answer();
    }

    return 0;
}

void answer() {
    ll n, k; cin >> n >> k;
    string s;
    for (ll i = 0; i < n; i++) s += (char)('A' + i);
    
    string temp = s;
    for (ll i = 1; i <= k; i++) {
        cout << s << endl;
        next_permutation(all(s));
        if (s == temp) break;
    }
}
