#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e9+7;

struct Matrix {
    ll mat[52][52];
    ll row, col;
 
    Matrix() {
        memset(mat, 0, sizeof(mat));
    }
    Matrix(ll a, ll b) {
        row = a, col = b; 
        memset(mat, 0, sizeof(mat));
    }
 
    Matrix operator*(const Matrix &p) const {
        assert(col == p.row);
        Matrix temp;
        temp.row = row;
        temp.col = p.col;
        for (ll i = 0; i < temp.row; i++) { 
            for (ll j = 0; j < temp.col; j++) { 
                ll sum = 0;
                for (ll k = 0; k <col;  k++) sum = (sum + ((mat[i][k]) * (p.mat[k][j])) % M) % M;
                temp.mat[i][j] = sum;
            }
        }
        return temp;
    }

    Matrix operator+ (const Matrix &p) const {
        assert(row == p.row and col == p.col);
        Matrix temp;
        temp.row = row;
        temp.col = col;
        for (ll i = 0; i < temp.row; i++) { 
            for (ll j = 0; j < temp.col; j++) temp.mat[i][j] = ((mat[i][j]) + (p.mat[i][j])) % M;
        }
        return temp;
    }
 
    Matrix identity() {
        Matrix temp;
        temp.row = row;
        temp.col = col;
        for (ll i = 0; i < row; i++) temp.mat[i][i] = 1;
        return temp;
    }
 
    Matrix pow(ll pow) {
        Matrix temp = (*this);
        Matrix ans = (*this).identity();
        while (pow) {
            if (pow & 1) ans = ans*temp;
            temp = temp*temp;
            pow /= 2;
        }
        return ans;
    }
 
    void show() {
        cout << "-----------------------------\n";
        for (ll i = 0; i < row; i++) { 
            for (ll j = 0; j < col; j++) cout << mat[i][j] << " ";
            cout << "\n";
        } 
        cout << "-----------------------------\n";
    } 
 
};

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;

    if (n <= 1) {
        cout << n;
        return 0;
    }

    Matrix a(2, 2);
    a.mat[0][0] = a.mat[0][1] = a.mat[1][0] = 1;
    a.mat[1][1] = 0;
    
    Matrix b(2, 2);
    b.mat[0][0] = 1;
    b.mat[0][1] = b.mat[1][0] = b.mat[1][1] = 0;
    
    a = a.pow(n-2);
    a = a*b;

    cout << (a.mat[0][0] + a.mat[1][0]) % M;
}
