#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
const ll M = 1e9+7;
const ll N = 2e5+7;
ll node[N];
 
ll bigMod(ll base, ll power) {
    if (!power) return 1; // base case
    ll result = bigMod(base, power/2);
    result = (result * result) % M;
    if (power & 1) result = (result * base) % M;
    return result;
}
 
ll query(ll index) {
    ll sum = 0;
    while (index) {
        sum = (sum + node[index]) % M;
        index -= index & (-index); 
    }
    return sum;
}
 
void update(ll index, ll value, ll n) {
    value %= M;
    while (index <= n) {
        node[index] = (node[index] + value) % M;
        index += index & (-index);
    }
}
 
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
	
    unordered_map<ll, ll> cnt;
	ll arr[n];
	for (auto &u : arr) {
		cin >> u;
		cnt[u]++;
	}
	
    ll curr = 1;
    vector<ll> v;
    for (auto &u : cnt) v.push_back(u.first);
    sort(v.rbegin(), v.rend());
 
    unordered_map<ll, ll> numbering;
		for (auto &u : v) {
        numbering[u] = curr;
        curr++;
    }
	
    ordered_set<ll> s;
	for (auto &u : arr) {
		update(numbering[u], u, n);
		s.insert(u);
		
		ll bigCnt = s.size() - s.order_of_key(u);
		cout << (query(numbering[u])*bigMod(bigCnt, M-2)) % M << " ";
	}
}
