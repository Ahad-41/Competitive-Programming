#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> Pair;
#define all(a) (a).begin(), (a).end()
void answer();

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

    ll arr[n];
    for (auto &u : arr) cin >> u;
    
    ll left[n], right[n];
    stack<ll> st;
    for (ll i = 0; i < n; i++) {
        if (st.empty()) left[i] = 0;
        else {
            while (!st.empty() and arr[st.top()] >= arr[i]) st.pop();
            if (st.empty()) left[i] = 0;
            else left[i] = st.top()+1;
        }
        st.push(i);
    }

    while (!st.empty()) st.pop();
    for (ll i = n-1; i >= 0; i--) {
        if (st.empty()) right[i] = n-1;
        else {
            while (!st.empty() and arr[st.top()] >= arr[i]) st.pop();
            if (st.empty()) right[i] = n-1;
            else right[i] = st.top()-1;
        }
        st.push(i);
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ans = max(ans, (right[i]-left[i]+1) * arr[i]);
    }

    cout << ans << endl;
}
