#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll N = 1e5+7;
struct Node {
    ll l, r;
    ll id;
} q[N];
ll n, m, a[N], block, ans, cnt[N*2], res[N];

bool cmp(Node a,Node b){
    return (a.l/block)^(b.l/block)?a.l<b.l:(((a.l/block)&1)?a.r<b.r:a.r>b.r);
}

void add(ll x) {
    if (!cnt[a[x]]) ans++;
    cnt[a[x]]++;
}

void del(ll x) {
    cnt[a[x]]--;
    if (!cnt[a[x]]) ans--;
}

int main(){
    int t; cin >> t;

    int Case = 1;
    while (t--){
        memset(cnt, 0, sizeof(cnt));
        ans = 0;

        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= m; i++) {
            cin >> q[i].l >> q[i].r;
            q[i].id = i;
        }

        block = n / sqrt(m*2/3*1.0);
        sort(q+1, q+m+1, cmp);

        int l = 1, r = 0;
        for (int i = 1; i <= m; i++) {
            int ql = q[i].l, qr = q[i].r;
            while (l > ql) add(--l);
            while (r < qr) add(++r);
            while (l < ql) del(l++);
            while (r > qr) del(r--);
            res[q[i].id] = ans;
        }
        
        cout << "Case " << Case++ << ":\n";
        for (int i = 1; i <= m; i++) cout << res[i] << endl;
    }
}
