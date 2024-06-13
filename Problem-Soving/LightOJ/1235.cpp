// May be I won't be a good programmer, but I will be a good human being.
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(a) (a).begin(), (a).end()
void answer();

vector<ll> v1, v2, sum1, sum2;

void subSetSum1(ll i, ll sum) {
    sum1.push_back(sum);
    if (i >= v1.size()) return;
    subSetSum1(i+1, sum);
    subSetSum1(i+1, sum+v1[i]);
    subSetSum1(i+1, sum+v1[i]+v1[i]);
}
void subSetSum2(ll i, ll sum) {
    sum2.push_back(sum);
    if (i >= v2.size()) return;
    subSetSum2(i+1, sum);
    subSetSum2(i+1, sum+v2[i]);
    subSetSum2(i+1, sum+v2[i]+v2[i]);
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll tt = 1;
    cin >> tt;

    for (ll t = 1; t <= tt; t++) {
        cout << "Case " << t << ": ";
        answer();
        v1.clear();
        v2.clear();
        sum1.clear();
        sum2.clear();
    }

    return 0;
}

void answer() {
    ll n, k; cin >> n >> k;
    for (ll i = 1; i <= n; i++) {
        ll a; cin >> a;
        if (i & 1) v1.push_back(a);
        else v2.push_back(a);
    }

    subSetSum1(0, 0);
    subSetSum2(0, 0);

    sort(all(sum2));
    for (auto &u : sum1) {
        if (binary_search(all(sum2), k-u)) {
            cout << "Yes\n";
            return;
        }
    }

    cout << "No\n";
}
