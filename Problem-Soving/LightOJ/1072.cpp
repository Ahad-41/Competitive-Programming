void answer(){
    double R, n; cin >> R >> n;
    double pi =  3.14159265359;
    double r = (sin(pi/n) * R) / (1 + sin(pi/n));
    cout << fixed << setprecision(10) <<  r << endl;
}
