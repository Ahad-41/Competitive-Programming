#include <bits/stdc++.h>
using namespace std;
const int N = 32000;
vector <int> primes;

void sieve() {
    bool isPrime[N];
    memset(isPrime, true, sizeof(isPrime));

    for (int i = 3; i * i <= N; i += 2) {
        if (isPrime[i]) {
            for (int j = i*i; j <= N; j += i) isPrime[j] = false;
        }   
    } 

    primes.push_back(2);
    for (int i = 3; i <= N; i += 2) {
        if (isPrime[i]) primes.push_back(i);
    }
}

void segmentedSieve (int l, int r) {
    int limit = r-l+1;
    bool isPrime[limit];
    memset(isPrime, true, sizeof(isPrime));
    
    for (int i = 0; primes[i] * primes[i] <= r; i++) {
        int base = (l/primes[i]) * primes[i];
        if (base < l) base += primes[i];

        for (int j = base; j <= r; j += primes[i]) {
            isPrime[j-l] = false;
        }

        if (base == primes[i]) isPrime[base-l] = true;
    }

    for (int i = 0; i < limit; i++) {
        if (isPrime[i]) cout << l+i << endl;
    }
    cout << endl;
}

int main () 
{
    sieve();
    int t;
    scanf("%d", &t);

    while (t--) {
        int m, n;
        scanf("%d %d", &m, &n);
        if (m == 1) m++;
        segmentedSieve(m, n);
    }
}
