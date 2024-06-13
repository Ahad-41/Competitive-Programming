#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void answer();
double ax, ay, bx, by, cx, cy, dx, dy, rat, firstDis, secondDis;

double distance(double ax, double ay, double bx, double by) {
    double ans = (ax-bx)*(ax-bx) + (ay-by)*(ay-by);
    return sqrt(ans);
}

double ternarySearch(double mid) {
    double m1 = mid;
    double m2 = firstDis - mid;

    double x1 = (ax*m2 + bx*m1) / (m1+m2);
    double y1 = (ay*m2 + by*m1) / (m1+m2);

    mid /= rat;
    m1 = mid;
    m2 = secondDis - mid;
    double x2 = (cx*m2 + dx*m1) / (m1+m2);
    double y2 = (cy*m2 + dy*m1) / (m1+m2);

    return distance(x1, y1, x2, y2);
}

int main()
{
    ll t; cin >> t;
    for(int i = 1; i <= t; i++)  {
        printf("Case %d: ", i);
        answer();
    }
}

void answer() {
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

    firstDis = distance(ax, ay, bx, by);
    secondDis = distance(cx, cy, dx, dy);
    rat = firstDis / secondDis;     
    
    double left = 0, right = firstDis;
    double ans = 1e18;
    for (ll i = 1; i <= 200; i++) {
        double midLeft = (2*left + right) / 3;
        double midRight = (left + 2*right) / 3;

        double leftValue = ternarySearch(midLeft);
        double rightValue = ternarySearch(midRight);

        ans = min(leftValue, rightValue);
        if (leftValue <= rightValue) right = midRight;
        else left = midLeft;
    }

    cout << fixed << setprecision(7) << ans << endl;
}
