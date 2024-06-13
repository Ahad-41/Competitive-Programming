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
    string s; cin >> s;

    ll winner;
    if (s == "Alice") { // BAABAAB...
        ll arr[3] = {1, 2, 1};
        winner = arr[n%3];
    }
    else { // BBABBABB...
        ll arr[3] = {1, 2, 2};
        winner = arr[n%3];
    }

    cout << (winner == 1 ? "Alice" : "Bob") << "\n";
}
