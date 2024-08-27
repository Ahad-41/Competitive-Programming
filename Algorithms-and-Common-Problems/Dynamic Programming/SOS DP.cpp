// https://codeforces.com/contest/165/problem/E

#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 22)+5;
int dp[N];

signed main()
{
    int n; cin >> n;

    for (int i = 0; i < N; i++) dp[i] = -1;
    int arr[n];
    for (auto &u : arr) {
        cin >> u;
        dp[u] = u;
    }

    for (int mask = 0; mask < N; mask++) {
        for (int i = 0; i < 22; i++) {
            if (mask & (1 << i)) 
                dp[mask] = max(dp[mask], dp[(mask ^ (1<<i))]);
        }
    }

    for (auto &u : arr) {
        cout << dp[((1 << 22) - 1) ^ u] << " ";
    }   
}
