#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
// 5e6 range handle korar jonno bitset ba global array
bool used[5000005];
 
int main(int argc, char* argv[]) {
    setName("Checker for distinct odd array sum problem");
    registerTestlibCmd(argc, argv);
 
    long long N = inf.readInt();
 
    if (N % 2 != 0) {
        string out = ouf.readToken();
        if (out != "-1") quitf(_wa, "Wrong Answer");
        if (!ouf.seekEof()) quitf(_wa, "Wrong Answer");
        quitf(_ok, "Accepted");
    }
 
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        if (ouf.seekEof()) quitf(_wa, "Wrong Answer");
        
        long long val = ouf.readLong();
        
        // Range, Parity, and Distinct check
        if (val < 1 || val > 5000000 || val % 2 == 0 || used[val]) {
            quitf(_wa, "Wrong Answer");
        }
        
        used[val] = true;
        sum += val;
    }
 
    if (!ouf.seekEof()) quitf(_wa, "Wrong Answer");
 
    if (sum != 1LL * N * (N + 1)) quitf(_wa, "Wrong Answer");
    quitf(_ok, "Accepted");
}
