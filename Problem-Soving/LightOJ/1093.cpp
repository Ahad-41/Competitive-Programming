#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> Pair;
#define all(a) (a).begin(), (a).end()
void answer();

struct node {
    ll sum, max, min;
};

const ll N = 1e5 + 7;
ll arr[N];
node tree[N * 4];

node merge(node a, node b) {
    node ans;
    ans.sum = a.sum + b.sum;
    ans.max = max(a.max, b.max);
    ans.min = min(a.min, b.min);
    return ans;
}

void segmentTree(ll currNode, ll left, ll right) {
    if (left == right) {
        tree[currNode].sum = tree[currNode].max = tree[currNode].min = arr[left];
        return;
    }
    ll leftNode = currNode * 2, rightNode = currNode * 2 + 1;
    ll mid = left + (right - left) / 2;

    segmentTree(leftNode, left, mid);
    segmentTree(rightNode, mid + 1, right);
    tree[currNode] = merge(tree[leftNode], tree[rightNode]);
}

// return the sum of i-th index to j-th index ->
node query(ll currNode, ll left, ll right, ll i, ll j) {
    if (i > right || j < left) return {0, 0, (ll)1e18};
    if (left >= i and right <= j) return tree[currNode];

    ll leftNode = currNode * 2, rightNode = currNode * 2 + 1;
    ll mid = left + (right - left) / 2;
    node leftCalc = query(leftNode, left, mid, i, j);
    node rightCalc = query(rightNode, mid + 1, right, i, j);

    return merge(leftCalc, rightCalc);
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
    ll n, d; cin >> n >> d;
    for (ll i = 1; i <= n; i++) cin >> arr[i];

    segmentTree(1, 1, n);
    ll ans = 0;
    for (ll i = 1; i <= n - d + 1; i++) {
        node temp = query(1, 1, n, i, i+d-1);
        ans = max(ans, temp.max - temp.min);
    }

    cout << ans << endl;
}
