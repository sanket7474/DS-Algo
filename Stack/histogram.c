#include<stdio.h>
	
	int findLargest(int arr[] , int n) {
		int max = 0,i,fwd,bck,val;
		
		for(i = 0 ; i < n ; i++) {
			fwd = i + 1;
			bck = i - 1;
			val = arr[i];
			
			while(fwd < n && arr[fwd] >= arr[i]) {
			
				val +=arr[i];
				fwd += 1;
			}
			while(bck >= 0  && arr[bck] >= arr[i]) {
			
				val += arr[i];
				bck -= 1;
 			}
			 if(max < val)
 				max = val;
		
		
	}
	return max;
	}
	int main() {
		
		int arr[] = {3,3,5,4,1,4,4};
		
		int max = findLargest(arr,7);
		
		printf("%d",max);
		return 0;
	}
