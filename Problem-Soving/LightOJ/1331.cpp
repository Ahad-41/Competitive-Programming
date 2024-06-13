#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> Pair;
#define all(a) (a).begin(), (a).end()
void answer();

double angle(double a, double b, double c) {
    return acos((b*b + c*c - a*a) / (2*b*c));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll tt = 1; cin >> tt;

    for (ll i = 1; i <= tt; i++) {
        cout << "Case " << i << ": ";
        answer();
    }

    return 0;
}

void answer() {
    double r1, r2, r3; cin >> r1 >> r2 >> r3;
    double s = (r1+r2+r2+r3+r3+r1) / 2.0;
    double areaOfTriangle = sqrt(s*(s-r1-r2)*(s-r2-r3)*(s-r3-r1));

    areaOfTriangle -= ((r1 * r1 * angle(r2+r3, r3+r1, r1+r2))) / 2; 
    areaOfTriangle -= ((r2 * r2 * angle(r3+r1, r1+r2, r2+r3))) / 2; 
    areaOfTriangle -= ((r3 * r3 * angle(r1+r2, r2+r3, r3+r1))) / 2;

    cout << fixed << setprecision(6) << areaOfTriangle << endl; 
}
