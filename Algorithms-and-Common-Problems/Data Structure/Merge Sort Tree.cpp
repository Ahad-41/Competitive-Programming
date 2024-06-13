#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// *s.find_by_order(index), s.order_of_key(value)
// erase -> s.erase(s.upper_bound(value));

const ll N = 1e5 + 7;
ll arr[N];
ordered_set<ll> node[N*4];

void mergeSortTree(ll currNode, ll left, ll right) {
    if (left == right) {
        node[currNode].insert(arr[left]);
        return;
    }
    ll leftNode = currNode * 2, rightNode = currNode * 2 + 1;
    ll mid = left + (right - left) / 2;

    mergeSortTree(leftNode, left, mid);
    mergeSortTree(rightNode, mid + 1, right);
    for (auto &u : node[leftNode]) node[currNode].insert(u);
    for (auto &u : node[rightNode]) node[currNode].insert(u);
}

void update(ll currNode, ll left, ll right, ll i, ll newValue) {
    if (i > right || i < left) return;
    if (left == right) {
        node[currNode].erase(node[currNode].upper_bound(arr[i]));
        node[currNode].insert(newValue);
        return;
    }

    ll leftNode = currNode * 2, rightNode = currNode * 2 + 1;
    ll mid = left + (right - left) / 2;

    update(leftNode, left, mid, i, newValue);
    update(rightNode, mid + 1, right, i, newValue);

    node[currNode].erase(node[currNode].upper_bound(arr[i]));
    node[currNode].insert(newValue);
}

ll query(ll currNode, ll left, ll right, ll i, ll j, ll x) {
    if (i > right || j < left) return 0;
    if (left >= i and right <= j) {
        ll ans = node[currNode].order_of_key(x+1);
        ll total = right-left+1;
        return total - ans;
    }

    ll leftNode = currNode * 2, rightNode = currNode * 2 + 1;
    ll mid = left + (right - left) / 2;
    return query(leftNode, left, mid, i, j, x) + query(rightNode, mid + 1, right, i, j, x);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    ll n; cin >> n;
    for (ll i = 1; i <= n; i++) cin >> arr[i];
    mergeSortTree(1, 1, n);

    ll q; cin >> q;
    while (q--) {
        ll type; cin >> type;
        if (type == 1) {
            ll i, v; cin >> i >> v;
            update(1, 1, n, i, v);
            arr[i] = v;
        }
        else {
            ll i, j, k; cin >> i >> j >> k;
            cout << query(1, 1, n, i, j, k) << "\n";
        }
    }
}