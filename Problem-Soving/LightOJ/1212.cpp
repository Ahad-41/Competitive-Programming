#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, test = 1; cin >> t;
    while(t--){
        cout << "Case " << test++ << ":" << endl;
        
        deque <int> dq;
        int n, m; cin >> n >> m;

        for(int i = 1; i <= m; i++){
            int a;
            string s; cin >> s;

            if(s == "pushLeft"){
                cin >> a;
                if(dq.size() < n){
                    dq.push_front(a);
                    cout << "Pushed in left: " << a << endl;
                }
                else cout << "The queue is full" << endl;
            }

            else if(s == "pushRight"){
                cin >> a;
                if(dq.size() < n){
                    dq.push_back(a);
                    cout << "Pushed in right: " << a << endl;
                }
                else cout << "The queue is full" << endl;

            } 

            else if(s == "popLeft"){
                if(dq.size() != 0){
                    cout << "Popped from left: " << dq.front() << endl;
                    dq.pop_front();
                }
                else cout << "The queue is empty" << endl;
            }

            else if(s == "popRight"){
                if(dq.size() != 0){
                    cout << "Popped from right: " << dq.back() << endl;
                    dq.pop_back();
                } 
                else cout << "The queue is empty" << endl;
            }
        }
    }
}
