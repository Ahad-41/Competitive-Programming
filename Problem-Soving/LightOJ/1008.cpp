        ll n; cin >> n;
        ll x, y;

        ll root = ceil(sqrt(n * 1.0));
        ll diff = root * root - n;
        if (diff < root){
            y = root;
            x = diff + 1;
        }
        else{
            x = root;
            y = n - (root-1) * (root-1);
        }
        if(root % 2 == 0){
            long long temp = x;
            x = y;
            y = temp;
        }

        cout << "Case " << i << ": " << x << " " << y << endl;
