#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void answer();

const ll N = 1e5+7;
struct info {
    ll prop, sum;
} tree[N*4];

ll query(ll currNode, ll left, ll right, ll i, ll j, ll carry = 0) {
    if (i > right || j < left) return 0;
    if (left >= i and right <= j) {
        return tree[currNode].sum + carry * (right - left + 1);
    }
    
    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;
    ll leftSum = query(leftNode, left, mid, i, j, carry + tree[currNode].prop);
    ll rightSum = query(rightNode, mid + 1, right, i, j, carry + tree[currNode].prop);

    return leftSum + rightSum;
}

void update(ll currNode, ll left, ll right, ll i, ll j, ll newValue) {
    if (i > right || j < left) return;
    if (left >= i and right <= j) {
        tree[currNode].sum += ((right - left + 1) * newValue);
        tree[currNode].prop += newValue;
        return;
    }

    ll leftNode = currNode*2, rightNode = currNode*2 + 1;
    ll mid = left + (right-left)/2;
    update(leftNode, left, mid, i, j, newValue);
    update(rightNode, mid+1, right, i, j, newValue);
    
    tree[currNode].sum = tree[leftNode].sum + tree[rightNode].sum + (right - left + 1) * tree[currNode].prop;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll tt = 1;
    cin >> tt;

    for (ll t = 1; t <= tt; t++) {
        cout << "Case " << t << ":\n";
        answer();
    }

    return 0;
}

void answer() {
    ll n, q; cin >> n >> q;

    while (q--) {
        ll type; cin >> type;
        if (type == 0) {
            ll x, y, v; cin >> x >> y >> v;
            x++, y++;
            update(1, 1, n, x, y, v);
        }
        else {
            ll x, y; cin >> x >> y;
            x++, y++;
            cout << query(1, 1, n, x, y) << endl;
        }
    }

    for (auto &u : tree) {
        u.prop = 0;
        u.sum = 0;
    }
}
