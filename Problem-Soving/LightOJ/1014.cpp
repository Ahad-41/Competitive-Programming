#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> Pair;
#define all(a) (a).begin(), (a).end()
void answer();

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll tt = 1;
    cin >> tt;

    for (ll i = 1; i <= tt; i++) {
        cout << "Case " << i << ": ";
        answer();
    }

    return 0;
}

void answer() {
    ll p, l; cin >> p >> l;
    ll diff = p-l;

    if (p <= l*2) {
        cout << "impossible\n";
        return;
    }

    vector<ll> v;
    for (ll i = 1; i*i <= diff; i++) {
        if (diff % i == 0) {
            if (i > l) v.push_back(i);
            if (i*i != diff and diff/i > l) v.push_back(diff/i);
        }  
    }

    sort(all(v));
    for (auto &u : v) cout << u << " ";
    cout << endl;
}
