#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// *s.find_by_order(index), s.order_of_key(value)
// erase -> s.erase(s.upper_bound(value));

typedef long long int ll;

const ll N = 1e5+3;
const ll M = 1429431 + 20;
ll lucky[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //-----------------------------------------------
    ordered_set<ll> s;
    s.insert(0);
    for (ll i = 1; i < M; i += 2) s.insert(i);

    lucky[1] = 1;
    for (ll i = 2; i < N; i++) {
        if (s.size() <= i) break;
        ll x = *s.find_by_order(i);
        
        vector<ll> v;
        for (ll j = x; j < M; j += x) {
            if (j >= s.size()) break;
            v.push_back(*s.find_by_order(j));
        }

        for (auto &u : v) s.erase(u);
        lucky[i] = x;
    }
    //----------------------------------------------

    ll tt = 1; cin >> tt;
    for (ll t = 1; t <= tt; t++) {
        cout << "Case " << t << ": ";
        ll n; cin >> n;
        cout << lucky[n] << endl;
    }

    return 0;
}
