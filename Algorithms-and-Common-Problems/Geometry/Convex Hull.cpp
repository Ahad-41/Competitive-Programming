#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double eps = 1e-9;
ll sign(double x) { return (x > eps) - (x < -eps); }

struct PT {
    double x, y;
    PT() { x = 0, y = 0; }
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y) {}

    PT operator - (const PT &a) const { return PT(x-a.x, y-a.y); }
    bool operator == (PT a) const { return sign(a.x - x) == 0 and sign(a.y - y) == 0; }

    bool operator < (const PT& a) const {
        if (fabs(x - a.x) > eps) return x < a.x;
        return y < a.y;
    }
};


inline double cross(PT a, PT b) { return a.x * b.y - a.y * b.x; }
inline ll orientation(PT a, PT b, PT c) { return sign(cross(b-a, c-a)); }

vector<PT> convexHull(vector<PT> &p) {
	if (p.size() <= 1) return p;
	vector<PT> v = p;
    sort(v.begin(), v.end());
    vector<PT> up, dn;
    for (auto& p : v) {
        while (up.size() > 1 and orientation(up[up.size() - 2], up.back(), p) >= 0) {
            up.pop_back();
        }
        while (dn.size() > 1 and orientation(dn[dn.size() - 2], dn.back(), p) <= 0) {
            dn.pop_back();
        }
        up.push_back(p);
        dn.push_back(p);
    }
    v = dn;
    if (v.size() > 1) v.pop_back();
    reverse(up.begin(), up.end());
    up.pop_back();
    for (auto& p : up) {
        v.push_back(p);
    }
    if (v.size() == 2 and v[0] == v[1]) v.pop_back();
    return v;
}

//checks if convex or not
bool isConvex(vector<PT> &p) {
    bool s[3]; s[0] = s[1] = s[2] = 0;
    ll n = p.size();
    for (ll i = 0; i < n; i++) {
        ll j = (i + 1) % n;
        ll k = (j + 1) % n;
        s[sign(cross(p[j] - p[i], p[k] - p[i])) + 1] = 1;
        if (s[0] and s[2]) return 0;
    }
    return 1;
}

// -1 if strictly inside, 0 if on the polygon, 1 if strictly outside
// it must be strictly convex, otherwise make it strictly convex first
ll isPointInConvex(vector<PT> &p, const PT& x) { // O(log n)
    ll n = p.size(); assert(n >= 3);
    ll a = orientation(p[0], p[1], x), b = orientation(p[0], p[n - 1], x);
    if (a < 0 or b > 0) return 1;
    ll l = 1, r = n - 1;
    while (l+1 < r) {
        ll mid = (l + r) >> 1;
        if (orientation(p[0], p[mid], x) >= 0) l = mid;
        else r = mid;
    }
    ll k = orientation(p[l], p[r], x);
    if (k <= 0) return -k;
    if (l == 1 and a == 0) return 0;
    if (r == n - 1 and b == 0) return 0;
    return -1;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    
    vector<PT> v;
    for (ll i = 1; i <= n; i++) {
        double x, y; cin >> x >> y;
        v.push_back({x, y});
    }

    auto ch = convexHull(v);
    // cout << ch.size() << "\n";
    // for (auto &u : ch) cout << (ll)u.x << " " << (ll)u.y << "\n";

    cin >> n;
    ll ans = 0;
    while (n--) {
        double x, y; cin >> x >> y;
        if (isPointInConvex(ch, {x, y}) < 1) ans++;
    }

    cout << ans;
}
