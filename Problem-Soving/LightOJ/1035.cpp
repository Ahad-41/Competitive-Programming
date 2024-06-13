#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> Pair;

const ll N = 101;
bool mark[N];
vector<ll> prime;
vector<Pair> primeFactor[N], ans[N];

void sieve() {
    for (ll i = 2; i < N; i++) {
        if (!mark[i]) {
            prime.push_back(i);
            for (ll j = i*i; j < N; j += i) mark[j] = true;
        }
    }
}

void save() {
    for (ll i = 2; i < N; i++) {
        ll n = i;
        for (auto &u : prime) {
            if (u * u > n) break;
            ll cnt = 0;
            while (n % u == 0) {
                cnt++;
                n /= u;
            }
            if (cnt) primeFactor[i].push_back({u, cnt});
        }
        if (n > 1) primeFactor[i].push_back({n, 1});
    }

    ll cnt[N] = {0};
    for (ll i = 0; i < N; i++) {
        for (auto &u : primeFactor[i]) cnt[u.first] += u.second;
        for (ll j = 0; j < N; j++) if (cnt[j]) ans[i].push_back({j, cnt[j]});
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    sieve();
    save();

    ll tt = 1; cin >> tt;
    for (ll i = 1; i <= tt; i++) {
        cout << "Case " << i << ": ";
        ll n; cin >> n;

        cout << n << " = ";
        for (ll j = 0; j < ans[n].size(); j++) {
            cout << ans[n][j].first << " ";
            cout << "(" << ans[n][j].second << ")";
            if (j != ans[n].size()-1) cout << " * ";
        }
        cout << endl;
    }

    return 0;
}
