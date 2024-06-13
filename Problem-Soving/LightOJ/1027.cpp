#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> Pair;
#define all(a) (a).begin(), (a).end()
void answer();

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
    ll sum = 0, pos = 0;
    while (n--) {
        ll a; cin >> a;
        sum += abs(a);
        if (a > 0) pos++;
    }

    if (!pos) {
        cout << "inf\n";
        return;
    }

    ll gcd = __gcd(sum, pos);
    cout << sum/gcd << "/" << pos/gcd << "\n";
}
