#include <bits/stdc++.h>
using namespace std;

vector <int> createFailureTable (string pattern) {
    int M = pattern.size();
    vector <int> failureTable(M);
    int index = 0;
    for (int i = 1; i < M; ) {
        if (pattern[index] == pattern[i]) {
            failureTable[i] = index + 1;
            index++;
            i++;
        }
        else {
            if (index != 0) index = failureTable[index - 1];
            else {
                failureTable[i] = index;
                i++;
            }
        }
    }

    return failureTable;
}

int kmp (string text, string pattern) {
    int N = text.size(), M = pattern.size(), count = 0;
    vector<int> failureTable = createFailureTable(pattern);

    int i = 0, j = 0; // i -> text,  j-> pattern
    while (i < N) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }
        else {
            if (j != 0) j = failureTable[j-1];
            else i++;
        }

        if (j == M) {
            count++;
            j = failureTable[j-1];
        }
    } 

    return count; 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        string text, pattern;
        cin >> text >> pattern;

        cout << kmp(text, pattern) << endl;
    }
}
