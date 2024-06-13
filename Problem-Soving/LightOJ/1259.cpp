#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> Pair;
#define all(a) (a).begin(), (a).end()
void answer();

const ll N = 1e7+5;
bool isPrime[N];
vector<ll> prime;

void sieve() {
    for (ll i = 2; i < N; i++) {
        if (!isPrime[i]) {
            prime.push_back(i);
            for (ll j = i*i; j < N; j += i) isPrime[j] = true;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll tt = 1;
    cin >> tt;

    sieve();
    for (ll i = 1; i <= tt; i++) {
        cout << "Case " << i << ": ";
        answer();
    }

    return 0;
}

void answer() {
    ll n; cin >> n;
    ll count = 0;

    for (auto &u : prime) {
        if (u*2 > n) break;
        if (!isPrime[u] and !isPrime[n-u]) count++;
    }

    cout << count << endl;
}
