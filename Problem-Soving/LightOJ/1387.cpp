#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> Pair;
#define all(a) (a).begin(), (a).end()
void answer();

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll tt = 1; cin >> tt;

    for (ll i = 1; i <= tt; i++) {
        cout << "Case " <<  i << ":\n";
        answer();
    }

    return 0;
}

void answer() {
    ll n; cin >> n;
    ll curr = 0;
    while (n--) {
        string s; cin >> s;
        if (s == "donate") {
            ll a; cin >>  a;
            curr += a;
        }
        else cout << curr << endl;
    }
}
