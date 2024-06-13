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
    ll d, n; cin >> d >> n;

    ll curr = 0, ans = 0;
    while (true) {
        curr = (curr * 10) + n;
        curr %= d;
        ans++;
        if (curr == 0) break;
    }

    cout << ans << endl;
}
