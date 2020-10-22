#include<bits/stdc++.h>

using namespace std;
	
	void print(deque <int>Q) {
		
		    deque <int> :: iterator it; 
		    
		    for(it = Q.begin() ; it != Q.end() ; ++it)
		    	cout<<" "<<*it;
			cout<<endl;
	}

	int main() {
		
		deque <int>Q;
		int n,d;
		while(1) {
			
			cin>>n;
			
			switch(n) {
				
				case 1: cin>>d;
						Q.push_front(d);
						break;
				case 2: Q.pop_front();
						break;
				case 3: cin>>d;
						Q.push_back(d);
						break;
				case 4: Q.pop_back();
						break;
				
			}
			
			print(Q);
		}
		print(Q);
		return 0;
	}
