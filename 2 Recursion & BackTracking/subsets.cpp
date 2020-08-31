#include<bits/stdc++.h>
// Used BackTracking To solve the problem 

// It will generate all possibles subsets
	using namespace std;
	
	
	int res[100]; // result array to store subsets temporarily
	
	void subsets(int n , int k , int arrayLen , int arr[] , int start) {
		
		int sum = 0;
		
			for(int i = arrayLen-1 ; i >= n ; i--) 
					sum += res[i];
				
			if(sum == k) {
				cout<<endl;
				
				for(int i = arrayLen-1 ; i >= n ; i--) {
				
					cout<<res[i]<<" ";
				}		
			}
		
		if(n < 0) 
			return;	
		else {
			
			for( int i = start ; i < arrayLen ; i++) {
				
				if(res[n] != arr[i])
					res[n-1] = arr[i];
				else
					continue;
                start++;
				subsets(n-1 , k , arrayLen , arr , start);
			}
		}
	}
	
	int main() {
		
		int arr[100] = {5, 10, 12, 13, 15, 18};
		int K = 30;
		int arrayLen = 6; // length of the array
		
//		cout<<"Enter ArrayLen and K";
//		cin>>arrayLen>>K;
//		
//		cout<<"Enter Array";
//		for(int i = 0 ; i < arrayLen ; i++)
//			cin>>arr[i];
//			
			
		subsets(arrayLen , K , arrayLen , arr , 0);
		
		
		return 0;
	}
	
	

