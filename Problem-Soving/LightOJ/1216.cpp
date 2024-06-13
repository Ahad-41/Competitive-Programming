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
        cout << "Case " <<  i << ": ";
        answer();
    }

    return 0;
}

void answer() {
    ll r1, r2, h, p; cin >> r1 >> r2 >> h >> p;

    double r3 = p / (h*1.0) * (r1-r2) + r2;
    double ans = 2.0*acos(0.0) * p * (r3*r3  + r2*r2 + r3*r2) / 3;
    cout << fixed  << setprecision(6) << ans << endl;
}
