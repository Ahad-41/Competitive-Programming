#include <bits/stdc++.h>
using namespace std;

#define N 5000000
int phi[N+2];
unsigned long long phiSum[N + 2];

void sievePhi() {
    for (int i = 2; i <= N; i++) phi[i] = i;
    for (int i = 2; i <= N; i++) {
        if (phi[i] != i) continue;
        for (int j = i; j <= N; j += i) phi[j] -= phi[j] / i ;
    }
}

int main()
{ 
    sievePhi();
    for(int i=2; i<=N; i++) phiSum[i]= ((unsigned long long)phi[i]* (unsigned long long)phi[i])+phiSum[i-1];

    int testCase; cin >> testCase;

    for (int t = 1; t <= testCase; t++) {
        cout << "Case " << t << ": ";
        int a, b; cin >> a >> b;
        cout << phiSum[b] - phiSum[a-1]  << endl;
    }
}
