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
        cout << "Case "  << t << ":\n";
        answer();
    }

    return 0;
}

void answer() {
    ll n, q; cin >> n >> q;
    vector<Pair> v;

    for (ll i = 1; i <= n; i++) {
        ll a, b; cin >> a >> b;
        v.push_back({a, 1});
        v.push_back({b, 2});
    }

    Pair query[q];
    for (ll i = 0; i < q; i++) {
        cin >> query[i].first;
        query[i].second = i;
    }

    sort(all(v));
    sort(query, query+q);

    n *= 2;
    ll ans[q] = {0}, cnt = 0, indx = 0, start = 0, end = 0;
    for (ll i = 0; i < n; i++) {
        v[i].second == 1 ? start++ : end++;
        if (i < n-1 and v[i+1].first == v[i].first) continue;

        while (indx < q and query[indx].first < v[i].first) {
            ans[query[indx].second] = cnt;
            indx++;
        }
        while (indx < q and query[indx].first == v[i].first) {
            ans[query[indx].second] = cnt + start;
            indx++;
        }
        
        cnt += start - end;
        start = 0;
        end = 0;
    }

    if (indx < q and query[indx].first < v.back().first) ans[query[indx].second] = cnt;
    else if (indx < q and query[indx].first == v.back().first) ans[query[indx].second] = cnt + start;

    for (auto &u : ans) cout << u << endl;
}
