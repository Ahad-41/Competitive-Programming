// May be I won't be a good programmer, but I wiint be a good human being.
#include <bits/stdc++.h>
using namespace std;
void answer();

int m, n, arr[15];
map<pair<int, int>, int> mp;

int func(int i, int x) {
    if (i > n) return 1;
    if (mp.count({i, x}) == 1) return mp[{i, x}];

    int ans = 0;
    for (int j = 1; j <= m; j++) {
        if (x == 0 || abs(arr[j]-x) <= 2) ans += func(i+1, arr[j]);
    }
    return mp[{i, x}] = ans;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt = 1;
    cin >> tt;

    for (int t = 1; t <= tt; t++) {
        cout << "Case " << t << ": ";
        answer();
    }

    return 0;
}

void answer() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) cin >> arr[i];
    
    mp.clear();
    int ans = func(1, 0);
    cout << ans << endl;
}
