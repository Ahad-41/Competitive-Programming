vector<pair<ll,ll>> primeFact;
ll num = arr[i];
while (num > 1) {
    ll p = spf[num], j = 0;
    while (num % p == 0) {
        num /= p;
        j++;
    }
    primeFact.push_back({p, j});
}

vector<ll> divisors, temp;
divisors.push_back(1);
for (auto &u : primeFact) {
    temp.clear();
    ll now = 1;
    for (ll k = 0; k <= u.second; k++, now *= u.first) {
        for (auto &v : divisors) temp.push_back(v*now);
    }
    divisors = temp;
}
