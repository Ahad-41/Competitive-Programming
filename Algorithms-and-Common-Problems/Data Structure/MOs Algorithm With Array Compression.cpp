#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 2e5+7;
ll blockSize, arr[N], cnt[N], distinct, ans[N], compressed[N];

struct query {
    ll l, r, indx;
    bool operator<(const query &x) const {
        if (l / blockSize == x.l / blockSize) return ((l / blockSize) & 1) ? r > x.r : r < x.r;
        return l / blockSize < x.l / blockSize;
    }
} query[N];

void add(ll i) {
    cnt[compressed[i]]++;
    if (cnt[compressed[i]] == 1) distinct++;
}

void remove(ll i) {
    cnt[compressed[i]]--;
    if (!cnt[compressed[i]]) distinct--;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, q; cin >> n >> q;
    map<ll, ll> already;
    ll assign = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> arr[i];
        if (already.find(arr[i]) == already.end()) already[arr[i]] = assign++;
        compressed[i] = already[arr[i]];
    }

    for (ll i = 1; i <= q; i++) {
        cin >> query[i].l >> query[i].r;
        query[i].indx = i;
    }
    blockSize = sqrt(n);
    sort(query+1, query+q+1);
    
    ll l = 1, r = 0;
    for (ll i = 1; i <= q; i++) {
        ll currL = query[i].l, currR = query[i].r;
        while (l < currL) remove(l++);
        while (l > currL) add(--l);
        while (r < currR) add(++r);
        while (r > currR) remove(r--);

        ans[query[i].indx] = distinct;
    }

    for (ll i = 1; i <= q; i++) cout << ans[i] << '\n';
}
