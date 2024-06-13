const ll N = 1e7 + 5;
int check[N], num[N];
vector<ll> prime;
void sieve()
{
    int primeCount = 0;
    for(ll i = 2; i < N; i++){
        if(!check[i]){
            primeCount++;
            prime.push_back(i);
            for(ll j = i * 2; j < N; j += i) check[j] = 1;
        }
        num[i] = primeCount;
    }
}
