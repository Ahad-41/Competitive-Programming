string multiply(string a, string b) {
    if (a == "0" || b == "0") return "0";
   
    ll m = a.size() - 1, n = b.size() - 1, carry = 0;
    string product;
    for (ll i = 0; i <= m+n || carry; i++) {
        for (ll j = max(0LL, i-n); j <= min(i, m); j++)
            carry += (a[m-j] - '0') * (b[n-i+j] - '0');
        product += carry % 10 + '0';
        carry /= 10;
    }
    reverse(begin(product), end(product));
    return product;
}
