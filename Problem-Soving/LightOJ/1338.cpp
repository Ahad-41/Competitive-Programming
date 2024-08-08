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
        
        char ch; cin >> ch;      
        string s, t;
        getline(cin, s);
        s = ch + s;
        getline(cin, t);
        
        ll cnt1[26] = {0}, cnt2[26] = {0};
        for (auto &u : s) if (u != ' ') cnt1[tolower(u)-'a']++;
        for (auto &u : t) if (u != ' ') cnt2[tolower(u)-'a']++;
        
        bool gormil = false;
        // s ki t er moddhe ache?
        for (ll i = 0; i < 26; i++) if (cnt1[i] > cnt2[i]) gormil = true;
        if (!gormil) {
            cout << "Yes\n";
            continue;
        }
        
        // t ki s er moddhe ache?
        gormil = false;
        for (ll i = 0; i < 26; i++) if (cnt1[i] < cnt2[i]) gormil = true;
        if (!gormil) {
            cout << "Yes\n";
            continue;
        }

        cout << "No\n";
    }
}
