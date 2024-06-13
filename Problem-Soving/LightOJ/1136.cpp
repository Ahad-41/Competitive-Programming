int main()
{
    optimize();
    for(ll i = 1; i <= N; i++) hsh[i] = log(i) + hsh[i-1];

    ll t; cin >> t;
    for(ll i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        ll a, b; cin >> a >> b;

        ll ans = answer(b) - answer(a-1);
        cout << ans << endl;

    } 
}  

ll answer(ll n){
    if(n == 0) return 0;
    
    ll divisible = n/3;
    divisible += (n % 3 > 0);

    return n - divisible;
}
