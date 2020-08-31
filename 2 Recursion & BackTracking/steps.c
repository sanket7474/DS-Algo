#include<stdio.h>
    
    int s[5];
    void ways(int x[] , int n , int size) {
        
        int i , sum = 0;
    
        for(i = size - 1 ; i >= n ; i--)
            sum += s[i];
        if(sum == size) {
            for(i = size -1 ; i >= n ; i--)
                printf("%d ",s[i]);
            printf("\n\n");
        }
        if(n < 1)
            return;
        else
        {
            for(i = 0 ; i < 3 ; i++) {
                s[n-1] = x[i];
                ways(x,n-1,size);
            } 
        }
        
    
    }
     
    int main()
    {
    	int x[] = {1,2,3}; 
        
		ways(x,6,6);
		return 0;
    
	}    
