#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
void answer();

int main()
{
    optimize();
    ll t; cin >> t;
    for(ll i = 1; i <= t; i++){
    	cout <<  "Case " << i << ":" << endl;
    	answer();
    }    
}  

void answer(){
	stack <string> forward, backword;
	string currentPage = "http:/";
	currentPage += "/www.lightoj.com/";
	
	while(1){
		string command; cin >> command;
		if(command == "QUIT") return;
	
		else if(command == "VISIT"){
			backword.push(currentPage);
			cin >> currentPage;
			cout << currentPage << endl;
			
			while(!forward.empty()) forward.pop();
		}
		
		else if(command == "BACK"){
			if(backword.empty()) cout << "Ignored" << endl;
			else{
				forward.push(currentPage);
				currentPage = backword.top();
				backword.pop();	
				
				cout << currentPage << endl;
			}
		}
		
		else if(command == "FORWARD"){
			if(forward.empty()) cout << "Ignored" << endl;
			else{
				backword.push(currentPage);
				currentPage = forward.top();
				forward.pop();	
				
				cout << currentPage << endl;
			}
		}
	}
}
