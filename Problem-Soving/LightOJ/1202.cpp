#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void answer();

int main()
{
    ll t; cin >> t;
    for(int i = 1; i <= t; i++)  {
        printf("Case %d: ", i);
        answer();
    }   
}

void answer() {
    ll a, b, c, d; cin >> a >> b >> c >> d;
    a = abs(c-a);
    b = abs(b-d);

    if ((a+b) & 1) cout << "impossible" << endl;
    else if (a == b) cout << "1" << endl;
    else cout << 2 << endl; 
}
