#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define all(a) (a).begin(), (a).end()
void answer();

ll n, arr[20][3], dp[20][3];

ll func(ll i, ll last) {
    if (i == n) return 0;
    if (dp[i][last] != -1) return dp[i][last];
    
    ll firstWay, secondWay;
    if (last == 0) {
        firstWay = func(i+1, 1) + arr[i][1];
        secondWay = func(i+1, 2) + arr[i][2];
    }
    else if (last == 1) {
        firstWay = func(i+1, 0) + arr[i][0];
        secondWay = func(i+1, 2) + arr[i][2];
    }
    else {
        firstWay = func(i+1, 0) + arr[i][0];
        secondWay = func(i+1, 1) + arr[i][1];
    }

    return dp[i][last] = min(firstWay, secondWay);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll tt = 1; cin >> tt;

    for (ll i = 1; i <= tt; i++) {
        cout << "Case " << i << ": ";
        answer();
    }

    return 0;
}

void answer() {
    cin >> n;
    for (ll i = 0; i < n; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    memset(dp, -1, sizeof(dp));

    ll first = func(1, 0) + arr[0][0];
    ll second = func(1, 1) + arr[0][1];
    ll third = func(1, 2) + arr[0][2];

    cout << min({first, second, third}) << endl;
}
