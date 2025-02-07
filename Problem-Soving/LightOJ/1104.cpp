#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc, tt = 1; cin >> tc;

    test:
    while (tc--) {
        cout << "Case " << tt++ << ": ";
        ll n; cin >> n;

        double probability = 1.0;
        ll k = 0;
        while (probability > 0.5) {
            k++;
            probability *= (double)(n-k+1) / n;
        }

        cout << k-1 << "\n";
    }
}
