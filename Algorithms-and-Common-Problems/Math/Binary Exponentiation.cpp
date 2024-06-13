#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+7;

int binExpWithRecursion(int base, int power) {
    if (!power) return 1; // base case
    int result = binExpWithRecursion(base, power/2);
    result = (result * result) % M;
    if (power & 1) result = (result * base) % M;
    return result;
}

int binExp(int base, int power) {
    int result = 1;
    while (power) {
        if (power & 1) result = (result * 1LL * base) % M;
        base = (base * 1LL * base) % M;
        power /=  2;
    }
    return result;
} 
 
int main()
{
    int base, power; cin >> base >> power;
    cout << binExp(base, power) << endl; 
    cout << binExpWithRecursion(base, power) << endl;  
} 
