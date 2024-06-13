#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin  >> t;
    for (int i = 1;  i <= t; i++) {
        cout << "Case " << i << ": ";  
        double ab, ac,  bc, r;
        cin >> ab >> ac >> bc >> r;
        
        double ans = sqrt(r / (r+1)) * ab;
        cout << fixed << setprecision(6) << ans  << endl;
    }
}
