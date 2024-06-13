#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, CaseCount = 1; cin >> t;

    while(t--){
        string s, temp; cin >> s;
        if(s[4] != 's'){
            temp.push_back(s[0]); s.erase(s.begin());
            temp.push_back(s[0]); s.erase(s.begin());
            temp.push_back(s[0]); s.erase(s.begin());
            temp.push_back(s[0]); s.erase(s.begin());
            cout << "Case " << CaseCount << ": " << temp << "s" << s << endl;
        }
        else cout << "Case " << CaseCount << ": " << s << endl;
        CaseCount++;
    }
}
