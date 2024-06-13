#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> Pair;
#define all(a) (a).begin(), (a).end()
void answer();

const ll M = 1e9+7;
const ll N = 1e5 + 7;
ll tree[N * 4];

bool cmp(Pair a, Pair b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}

ll query(ll currNode, ll left, ll right, ll i, ll j) {
    if (i > right || j < left) return 0;
    if (left >= i and right <= j) return tree[currNode];

    ll leftNode = currNode * 2, rightNode = currNode * 2 + 1;
    ll mid = left + (right - left) / 2;
    ll leftCalc = query(leftNode, left, mid, i, j);
    ll rightCalc = query(rightNode, mid + 1, right, i, j);

    return (leftCalc + rightCalc) % M;
}

void update(ll currNode, ll left, ll right, ll i, ll newValue) {
    if (i > right || i < left) return;
    if (left == right) {
        tree[currNode] = newValue;
        return;
    }

    ll leftNode = currNode * 2, rightNode = currNode * 2 + 1;
    ll mid = left + (right - left) / 2;

    update(leftNode, left, mid, i, newValue);
    update(rightNode, mid + 1, right, i, newValue);
    tree[currNode] = (tree[leftNode] + tree[rightNode]) % M;
}

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

    vector<Pair> v;
    for (ll i = 1; i <= n; i++) {
        ll a; cin >> a;
        v.push_back({a, i});
    }    

    sort(all(v), cmp);
    memset(tree, 0, sizeof(tree));

    for (auto &u : v) {
        ll x = u.second;
        ll ways = query(1, 1, n, 1, x-1);
        update(1, 1, n, x, ways+1);
    }

    cout << query(1, 1, n, 1, n) << endl;
}
