#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, w, arr[100], dp[100][100];

ll func(ll i, ll k) {   
    if (i >= n or k <= 0) return 0;
    if (dp[i][k] != -1) return dp[i][k];

    ll ans = func(i+1, k);

    ll j = i, cover = 0;
    while (j < n) {
        if (arr[i]+w < arr[j]) break;
        cover++;
        j++;
    }
    
    ans = max(ans, cover+func(j, k-1));
    return dp[i][k] = ans;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll tc, tt = 1; cin >> tc;

    test:
    while (tc--) {
        cout << "Case " << tt++ << ": ";
        ll k; cin >> n >> w >> k;
        for (ll i = 0; i < n; i++) cin >> arr[i] >> arr[i];
        sort(arr, arr+n);

        memset(dp, -1, sizeof(dp));
        cout << func(0, k) << "\n";
    }
}
