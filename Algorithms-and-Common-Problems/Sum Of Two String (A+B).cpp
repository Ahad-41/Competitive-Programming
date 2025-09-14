string findSum(string str1, string str2){
    if (str1.length() > str2.length()) swap(str1, str2);
    string str;
    ll n1 = str1.length(), n2 = str2.length();

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    ll carry = 0;
    for (ll i = 0; i < n1; i++) {
        ll sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    for (ll i = n1; i < n2; i++){
        ll sum = ((str2[i] - '0') + carry);
        str += (sum % 10 + '0');
        carry = sum / 10;
    }

    if (carry) str += (carry + '0');
    reverse(str.begin(), str.end());

    return str;
}
