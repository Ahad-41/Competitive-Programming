#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> Pair;
#define all(a) (a).begin(), (a).end()

const ll M = 1e9+7;
const ll N = 1e5+5;
ll base1 = 31, base2 = 37, p1[N], p2[N], hS1[N], hS2[N], hT1[N], hT2[N];

Pair getS(ll i, ll len) {
    ll ans1 = hS1[i], ans2 = hS2[i];
    if (i-len >= 0) ans1 -= (hS1[i-len] * p1[len]) % M;
    if (i-len >= 0) ans2 -= (hS2[i-len] * p2[len]) % M;
    ans1 = (ans1 + M) % M;
    ans2 = (ans2 + M) % M;
    return {ans1, ans2};
}

Pair getT(ll i, ll len) {
    ll ans1 = hT1[i], ans2 = hT2[i];
    if (i-len >= 0) ans1 -= (hT1[i-len] * p1[len]) % M;
    if (i-len >= 0) ans2 -= (hT2[i-len] * p2[len]) % M;
    ans1 = (ans1 + M) % M;
    ans2 = (ans2 + M) % M;
    return {ans1, ans2};
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    p1[0] = 1;
    p2[0] = 1;
    for (ll i = 1; i < N; i++) p1[i] = (p1[i-1] * base1) % M;
    for (ll i = 1; i < N; i++) p2[i] = (p2[i-1] * base2) % M;
    
    ll n; cin >> n;
    string s, t; cin >> t >> s;

    for (ll i = 0; i < n; i++) {
        if (i == 0) {
            hS1[i] = (s[i]-'A'+1);
            hS2[i] = (s[i]-'A'+1);
            hT1[i] = (t[i]-'A'+1);
            hT2[i] = (t[i]-'A'+1);
        }
        else {
            hS1[i] = ((hS1[i-1] * base1) + (s[i]-'A'+1)) % M;
            hS2[i] = ((hS2[i-1] * base2) + (s[i]-'A'+1)) % M;
            hT1[i] = ((hT1[i-1] * base1) + (t[i]-'A'+1)) % M;
            hT2[i] = ((hT2[i-1] * base2) + (t[i]-'A'+1)) % M;
        }
    } 
    
    ll low = 0, high = n, len = 0;
    while (low <= high) {
        ll mid = low + (high-low) / 2;
        
        bool paichi = false;
        vector<Pair> temp;
        for (ll i = mid-1; i < n; i++) temp.push_back(getS(i, mid));
        sort(all(temp));

        for (ll i = mid-1; i < n; i++) {
            Pair val = getT(i, mid);
            auto it = lower_bound(all(temp), val);
            if (it != temp.end() and *it == val) {
                paichi = true;
                break;
            }
        }

        if (paichi) {
            len = mid;
            low = mid+1;
        }
        else high = mid-1;
    }

    vector<Pair> temp;
    for (ll i = len-1; i < n; i++) temp.push_back(getS(i, len));
    sort(all(temp));

    string ans1;
    for (ll i = len-1; i < n; i++) {
        Pair val = getT(i, len);
        auto it = lower_bound(all(temp), val);
        if (it != temp.end() and *it == val) {
            ans1 = t.substr(i-len+1, len);
            break;
        }
    }

    cout << ans1;
}
