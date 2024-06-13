#include <bits/stdc++.h>
using namespace std;

/**
 * Returns  the number of problems stored in each computer.
 * @param n denotes the total number of problems.
 */
vector<int> problemsStored(int n) {
    vector<int> res;

    // Implement this method
    if(n > 10){
        res.push_back(10); res.push_back(n-10);
    }
    else{
        res.push_back(0); res.push_back(n);
    }
    return res;
}

/**
 * Takes care of the problem input and output.
 */
int main() {
    int cases;
    scanf("%d", &cases);
    for (int caseno = 1; caseno <= cases; ++caseno) {
        int n;
        scanf("%d", &n);
        
        vector<int> ans = problemsStored(n);
        printf("%d %d\n", ans[0], ans[1]);
    }
    return 0;
}
