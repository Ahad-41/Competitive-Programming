#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 5005;
vector<ll> divisor[N];

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc;

    for (ll i = 1; i < N; i++) {
        for (ll j = i; j < N; j += i) divisor[j].push_back(i);
    }

    test:
    while (tc--) {
        ll n, m; cin >> n >> m;

        ll arr[n];
        for (auto &u : arr) {
            cin >> u;
            u = m - (u % m);
        }

        ll blockSize = sqrt(n)+1;
        ll numBlocks = (n+blockSize-1) / blockSize;

        vector<ll> blocks[numBlocks];
        ll cnt[numBlocks][m+1];
        memset(cnt, 0, sizeof(cnt));
        for (ll i = 0; i < n; i++) {
            blocks[i/blockSize].push_back(arr[i]);
            for (auto &u : divisor[arr[i]]) if (u <= m) cnt[i/blockSize][u]++;
        }

        ll q; cin >> q;
        while (q--) {
            ll type; cin >> type;
            if (type == 1) {
                ll i, x; cin >> i >> x;
                i--;
                x = m - (x % m);

                ll b = i / blockSize;
                for (auto &u : divisor[arr[i]]) if (u <= m) cnt[b][u]--;
                for (auto &u : divisor[x]) if (u <= m) cnt[b][u]++;

                arr[i] = x;
                blocks[b][i%blockSize] = x;
            }
            else {
                ll l, r, k; cin >> l >> r >> k;
                l--; r--;
                ll total = r-l+1;
                k = __gcd(k, m);

                ll ans = 0;
                while (l <= r and (l % blockSize)) {
                    if (arr[l] % k == 0) ans++;
                    l++;
                }

                while (l+blockSize-1 <= r) {
                    ll b = l / blockSize;
                    ans += cnt[b][k];
                    l += blockSize;
                }

                while (l <= r) {
                    if (arr[l] % k == 0) ans++;
                    l++;
                }

                cout << total - ans << "\n";
            }
        }
    }
}
