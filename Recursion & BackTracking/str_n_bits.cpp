#include<bits/stdc++.h>

using namespace std;
	
	
	void Binary(int n,char s[100]) {
		
		if(n < 1) {
		
			cout<<s<<endl;
			return;
		}
		else {
			
			s[n-1] = '0';
			Binary(n-1,s);
			
			s[n-1] = '1';
			Binary(n-1,s);
		}
		
	}
	char getChar(int num) {
		
		switch(num) {
			case 0 : return '0';
						break;
			case 1 : return '1';
						break;
			case 2 : return '2';
						break;
			case 3 : return '3';
						break;
			case 4 : return '4';
						break;
			case 5 : return '5';
						break;
			case 6 : return '6';
						break;
			case 7 : return '7';
						break;
			case 8 : return '8';
						break;
			case 9 : return '9';
						break;
		}
		return '0';
	}
	char s[10];
	void k_string(int n , int k) {
		
		if(n < 1)
			cout<<s<<endl;
		else {
			
			for(int i = 0 ; i < k ; i++) {
				if(s[n] != getChar(i+1))		
				s[n-1] = getChar(i+1);
			k_string(n-1 , k);
		}
	}
	}
	int main() {
		
		char s[100];	
		// Binary(2,s);

		k_string(4,4);
		return 0;
	}
