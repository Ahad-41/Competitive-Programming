void answer(){
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    ll m; cin >> m;
    while(m--){
        ll x, y; cin >> x >> y;
        if(x >= min(x1, x2) and x <= max(x1, x2) and y >= min(y1, y2) and y <= max(y1, y2))
            cout << "Yes" << endl;

        else cout << "No" << endl;
    }
}
