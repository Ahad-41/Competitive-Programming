#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> Pair;
#define all(a) (a).begin(), (a).end()
void answer();

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll tt = 1;
    cin >> tt;

    for (ll t = 1; t <= tt; t++) {
        cout << "Case " << t << ": ";
        answer();
    }

    return 0;
}

void answer() {
    ll ox, oy, ax, ay, bx, by; cin >> ox >> oy >> ax >> ay >> bx >> by;
    
    double oa = sqrt((ox-ax)*(ox-ax) + (oy-ay)*(oy-ay));
    double ob = sqrt((ox-bx)*(ox-bx) + (oy-by)*(oy-by));
    double ab = sqrt((ax-bx)*(ax-bx) + (ay-by)*(ay-by));

    double theta = acos((pow(oa, 2) + pow(ob, 2) - pow(ab, 2)) / (2 * oa * ob));

    // double s = (oa+ob+ab) / 3.0;
    // double area = sqrt(s*(s-oa)*(s-ob)*(s-ab));
    // double h = (2*area) / ab;

    // double otivuj = sqrt(h*h + (ab*ab)/4);
    // double theta = atan((ab/2) / h);

    // double ans = (theta/360.0) * 2 * 3.14159265 * oa;
    cout << fixed << setprecision(3) << oa*theta << endl;
}
