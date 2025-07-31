#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc; cin >> tc;

    test:
    while (tc--) {
        ll n; cin >> n;

        ll arr[n];
        for (auto &u : arr) cin >> u;

        vector<ll> ngei(n, -1);
        stack<ll> st;
        for (ll i = n-1; i >= 0; i--) {
            while (!st.empty() and arr[st.top()] <= arr[i]) st.pop();
            if (!st.empty()) ngei[i] = st.top();
            st.push(i);
        }

        ll sum[n] = {0}, mex[n];
        for (ll i = n-1; i >= 0; i--) {
            sum[i] = i;
            mex[i] = 1;
            if (ngei[i] == -1) continue;
            if (arr[ngei[i]] == arr[i]+1) {
                sum[i] += sum[ngei[i]];
                mex[i] += mex[ngei[i]];
            }
        }

        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            if (arr[i]) continue;
            ans += mex[i]*n - sum[i];
        }

        cout << ans << "\n";
    }
}
