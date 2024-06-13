#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
void answer();

int main()
{
    optimize(); 
    ll t; cin >> t;
    for(ll i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        answer();
    } 
}  

void answer(){
    ll ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    ll dx = ax+cx-bx;
    ll dy = ay+cy-by;

    ll area = (ax*by + bx*cy + cx*dy + dx*ay - ay*bx - by*cx - cy*dx - dy*ax) / 2;

    cout << dx << " " << dy << " " << abs(area) << endl;
}
