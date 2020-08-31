#include<stdio.h>
#include<string.h>
	void reverse(char *s) {
		int i;
		char temp;
		int n = strlen(s);
		for(i = 0 ; i < strlen(s)/2 ; i++) {
			
				temp = s[i];
				s[i] = s[n-i-1];
				s[n-i-1] = temp;
		}
		
		puts(s);
	}

	int main() {
		
		char s[] = "Sanket";
		reverse(s);
		return 0;
	}
