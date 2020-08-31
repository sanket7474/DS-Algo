#include<stdio.h>

	int maxSpan(int arr[] , int n) {
		int i,j,max = 0;
		
		for(i = 0 ; i < n ; i++) {
			
			j = 1;
			while(j <= i && arr[i] > arr[i-j]) 
				j += 1;
			
			if(max < j)
				max = j;
		}
			return max;
	}
	int main() {
		
		
		int arr[] = {6,3,4,5,2};
		int max = maxSpan(arr,5);
		
		printf("Max:%d\t",max);
	}
