#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll M = 1e9+7;
const ll N = 2;

ll n = 2, m = 2;
struct Matrix {
    ll mat[N][N];
    Matrix(initializer_list<initializer_list<ll>> list) {
        int i = 0, j = 0;
        for (auto row : list) {
            j = 0;
            for (auto val : row) {
                mat[i][j++] = val;
            }
            i++;
        }
    }

    Matrix() {}
} unit;

Matrix matrixMul(Matrix a, Matrix b) {
    Matrix ans;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            ll sum = 0;
            for (ll k = 0; k < n; k++) sum = (sum + ((a.mat[i][k] * b.mat[k][j])% M)) % M;
            ans.mat[i][j] = sum;
        }
    }
    return ans;
}

Matrix matrixExpo(Matrix a, ll p) {
    if (p == 0) return unit;

    Matrix ans = matrixExpo(a, p/2);
    if (p % 2 == 0) return matrixMul(ans, ans);
    else return matrixMul(a, matrixMul(ans, ans));
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;

    if (n <= 1) {
        cout << n;
        return 0;
    }

    unit = Matrix({{1, 0}, {0, 1}});
    Matrix a = {{1, 1}, {1, 0}};
    Matrix b = {{1, 0}, {0, 0}};
    Matrix ans = matrixExpo(a, n-2);
    matrixMul(ans, b);

    cout << (ans.mat[0][0] + ans.mat[1][0]) % M;
 }