void answer(){
    ll w; cin >> w;
    
    if(w & 1){
        cout << "Impossible" << endl;
        return;
    }
    
    ll n = w/2;
    ll m = 2;
    while(!(n % 2)){
        n /= 2;
        m *= 2;
    }
    
    cout << n << " " << m << endl;
}
