#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main() {
    ios_base::sync_with_stdio(); cin.tie();
    ll tt = 1; cin >> tt;

    test:
    while (tt--) {
        ll n, m; cin >> n >> m;

        ll arr[n+1][m+1];
        memset(arr, -1, sizeof(arr));
        if (n >= m) {
            ll curr = 1, currDistinct = 1;
            for (ll currRow = 1; currRow <= m; currRow++) {
                for (ll i = 1; i <= m-currDistinct+1; i++) arr[currRow][i] = curr;
                curr++;
                for (ll i = m-currDistinct+2; i <= m; i++) arr[currRow][i] = curr++;
                currDistinct++;
            }
            
            currDistinct = 1;
            for (ll currCol = 1; currCol <= m; currCol++) {
                for (ll i = m+1; i <= n-currDistinct+1; i++) arr[i][currCol] = curr;
                curr++;
                for (ll i = n-currDistinct+2; i <= n; i++) arr[i][currCol] = curr++;
                currDistinct++;
            }
        }

        if (n < m) {
            ll curr = 1, currDistinct = 1;
            for (ll currCol = 1; currCol <= n; currCol++) {
                for (ll i = 1; i <= n-currDistinct+1; i++) arr[i][currCol] = curr;
                curr++;
                for (ll i = n-currDistinct+2; i <= n; i++) arr[i][currCol] = curr++;
                currDistinct++;
            }
            
            currDistinct = 1;
            for (ll currRow = 1; currRow <= n; currRow++) {
                for (ll i = n+1; i <= m-currDistinct+1; i++) arr[currRow][i] = curr;
                curr++;
                for (ll i = m-currDistinct+2; i <= m; i++) arr[currRow][i] = curr++;
                currDistinct++;
            }
        }

        set<ll> st;
        for (ll i = 1; i <= n; i++) {
            set<ll> s;
            for (ll j = 1; j <= m; j++) s.insert(arr[i][j]);
            st.insert(s.size());
        }
        for (ll i = 1; i <= m; i++) {
            set<ll> s;
            for (ll j = 1; j <= n; j++) s.insert(arr[j][i]);
            st.insert(s.size());
        }
        
        cout << st.size() << "\n";
        for (ll i = 1; i <= n; i++) {
            set<ll> s;
            for (ll j = 1; j <= m; j++) cout << arr[i][j] << " ";
            cout << "\n";
        }
    }
}
