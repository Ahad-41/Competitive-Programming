#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> Pair;
#define all(a) (a).begin(), (a).end()
void answer();

const ll N = 1e6+7;
bool check[N];
vector<ll> prime;
void sieve() {
    for (ll i = 3; i < N; i += 2) 
        if (!check[i])
            for (ll j = i*i; j < N; j += i) check[j] = true;

    prime.push_back(2);
    for (ll i = 3; i < N; i += 2) 
        if (!check[i]) prime.push_back(i);
}

ll divisorCount(ll n) {
    ll totalDivisor = 1;
    for (ll i = 0; i < N; i++) {
        if (prime[i]*prime[i] > n) break;
        
        if (n % prime[i] == 0) {
            ll curr = 0;
            while (n > 1 and n % prime[i] == 0) {
                curr++;
                n /= prime[i];
            }
            totalDivisor *= (curr+1);
        }
    }
    if (n != 1) totalDivisor *= 2;
    
    return totalDivisor;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sieve();
    ll tt = 1;
    cin >> tt;

    for (ll i = 1; i <= tt; i++) {
        cout << "Case " << i << ": ";
        answer();
    }

    return 0;
}

void answer() {
    ll n; cin >> n;
    cout << divisorCount(n) - 1 << endl;
}
