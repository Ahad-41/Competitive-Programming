#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
 
    ll arr[n];
    for (auto &u : arr) cin >> u;
 
    stack <ll> st;
    ll ans[n] = {0};
    for (ll i = 0; i < n; i++) {
        while (!st.empty() and arr[st.top()] >= arr[i]) st.pop();
        if (!st.empty()) ans[i] = st.top()+1;
        st.push(i);
    }
 
    for (auto &u : ans) cout << u << " ";
}
