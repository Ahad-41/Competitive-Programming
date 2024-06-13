#include <stdio.h>
int hash[20001];

int main()
{
	int t;
	scanf("%d", &t);
	
	for(int i = 1; i <= t; i++){
		printf("Case %d: ", i);
		
		int n; 
		scanf("%d", &n);
		
		int arr[n];
		for(int j = 0; j < n; j++){
			scanf("%d", &arr[j]);
		}

		for(int j = 0; j < 20001; j++){
			hash[j] = 0;
		}

		long long int shadowSum = 0;
    	
	        for(int j = n-1; j >= 0; j--){
			int index = arr[j];
			if(index < 0){
				index = index * -1;
			}
	    	
			if(hash[index] == 0){
				shadowSum = shadowSum + arr[j];
				hash[index] = 1;
			}
	        }
	    
	        printf("%lld\n", shadowSum);
	}
}
