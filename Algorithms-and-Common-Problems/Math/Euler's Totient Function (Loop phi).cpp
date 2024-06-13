#include <bits/stdc++.h>
using namespace std;

int phi(int n) {
    int totalCoprime = n;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            totalCoprime -= totalCoprime / i;
        }
    }

    if (n > 1) totalCoprime -= totalCoprime / n;
    return totalCoprime;
}

int main()
{
    int n; cin >> n;
    cout << phi(n) << endl; // print the total number of coprime of n -> from 1 to n
}
