#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);
	
	for(int i = 1; i <= t; i++){
		printf("Case %d: ", i);
		
		int n; 
		scanf("%d", &n);
		
    	int setBit = 0;
	    for(int j = 31; j >= 0; j--){
	    	int bit = (n >> j) & 1;
	    	if(bit){
	    		setBit++;
	    	}
	    }
	    
	    if(setBit & 1){
	    	printf("odd\n");
	    }
	    
	    else{
	    	printf("even\n");
	    }
	}
}
