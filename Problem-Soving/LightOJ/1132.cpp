#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unsigned int pascal[55][55];

struct Matrix {
    unsigned int mat[52][52];
    ll row,col;
 
    Matrix() {
        memset(mat,0,sizeof mat);
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
                for (ll k = 0; k < col;  k++) sum += ((mat[i][k]) * (p.mat[k][j]));
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
            for (ll j = 0; j < temp.col; j++) temp.mat[i][j] = ((mat[i][j])+(p.mat[i][j]));;
        }
        return temp;
    }
 
    Matrix identity() {
        Matrix temp;
        temp.row = row;
        temp.col = col;
        for(ll i = 0; i < row; i++) temp.mat[i][i] = 1;
        return temp;
    }
 
    Matrix pow(ll pow) {
        Matrix temp = (*this);
        Matrix ans = (*this).identity();
        while (pow) {
            if (pow % 2 == 1) ans = ans*temp;
            temp = temp*temp;
            pow /= 2;
        }
        return ans;
    }
};
 
void computePascal() {
    pascal[0][0] = pascal[1][1] = 1;
    for (ll i = 1; i < 52; i++) {
        pascal[i][0] = 1;
        for (ll j = 1; j < 52; j++) pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll tc, tt = 1; cin >> tc;
    computePascal();

    while (tc--) {
        cout << "Case " << tt++ << ": ";
        ll n, k; cin >> n >> k;

        Matrix a(k+2, k+2);
        a.mat[0][0] = 1;
        for (ll i = 1; i <= k+1; i++) {
            a.mat[0][i] = pascal[k][i-1];
            a.mat[1][i] = pascal[k][i-1];
        }
        for (ll i = 2; i <= k+1; i++) {
            for (ll j = i; j <= k+1; j++) a.mat[i][j]=pascal[k-i+1][j-i];
        }
  
        Matrix b(k+2,1);
        for (ll i = 0; i <= k+1; i++) b.mat[i][0] = 1;
 
        a = a.pow(n-1);
        a = a*b;
        cout << a.mat[0][0] << "\n";
    }
}
