#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> Pair;
#define all(a) (a).begin(), (a).end()
void answer();

const ll N = 150005;
ll tree[N];

ll query(ll index) {
    ll sum = 0;
    while (index) {
        sum += tree[index];
        index -= index & (-index); 
    }
    return sum;
}

void update(ll index, ll value) {
    while (index < N) {
        tree[index] += value;
        index += index & (-index);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll tt = 1;
    cin >> tt;

    for (ll t = 1; t <= tt; t++) {
        cout << "Case " << t << ":\n";
        answer();
    }

    return 0;
}

void answer() {
    memset(tree, 0, sizeof(tree));
    ll n, q; cin >> n >> q;

    vector<ll> v(N);
    for (ll i = 1; i <= n; i++) {
        cin >> v[i];
        update(i, 1);
    }

    while (q--) {
        char ch; cin >> ch;
        if (ch == 'a') {
            ll p; cin >> p;
            n++;
            v[n] = p;
            update(n, 1);
        }

        else {
            ll k; cin >> k;

            ll low = 1, high = n, indx = -1;
            while (low <= high) {
                ll mid = low + (high-low)/2;
                ll sum = query(mid);
                if (sum >= k) {
                    if (sum == k) indx = mid;
                    high = mid-1;
                }
                else low = mid+1;
            }

            if (indx == -1) cout << "none" << endl;
            else {
                cout << v[indx] << endl;
                update(indx, -1);
                v[indx] = -1;
            }
        }
    }
}
