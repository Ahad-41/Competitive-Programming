#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
int phi[N];
bool mark[N];

void sievePhi(int n) {
    for (int i = 1; i <= n; i++) phi[i] = i; 

    for (int i = 2; i <= n; i++) {
        if (mark[i] == true) continue;

        for (int j = i; j <= n; j += i) {
            mark[j] = true;
            phi[j] = phi[j] / i * (i-1);
        }
    }
}

int main()
{
    int n; cin >> n;
    sievePhi(n);
    cout << phi[10] << endl;
}
