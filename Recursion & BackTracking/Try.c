#include<stdio.h>
#include<stdarg.h>
    
    int main() {
        int n = 5,i;
        int a[n];
		for(i = 0 ; i<n+5 ;i++)
        	a[i] = i;
		for(i = 0 ; i<n+5 ;i++)
        	printf("%d",a[i]);
       
    }
