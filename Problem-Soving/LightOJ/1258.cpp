#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(a) (a).begin(), (a).end()

vector <ll> createFailureTable (string revStern) {
    ll M = revStern.size();
    vector <ll> failureTable(M);
    ll index = 0;
    for (ll i = 1; i < M; ) {
        if (revStern[index] == revStern[i]) {
            failureTable[i] = index + 1;
            index++;
            i++;
        }
        else {
            if (index != 0) index = failureTable[index - 1];
            else {
                failureTable[i] = index;
                i++;
            }
        }
    }
    return failureTable;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll tt = 1; cin >> tt;

    for (ll t = 1; t <= tt; t++) {
        cout << "Case " << t << ": ";

        string s; cin >> s;
        string revS = s;
        reverse(all(revS));
        string tempS = revS + '#' + s;
        vector<ll> lps = createFailureTable(tempS);

        ll n = s.size() * 2;
        ll total = n - lps.back();
        cout << total << endl;
    }
}
