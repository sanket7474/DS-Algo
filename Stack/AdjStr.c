#include<stdio.h>
#include<string.h>
	void rmAdjacent(char *str) {
		
		int stkptr = -1;
		int i = 0;
		int len = strlen(str);
		
		while(i < len) {
			
			if(stkptr == -1 || str[stkptr]!=str[i]) {
				
				stkptr++;
				str[stkptr] = str[i];
				i++;
			}
			else {
				
				while(i<len && str[stkptr] == str[i])
					i++;
				stkptr--;
			}
		}
		
		str[stkptr+1] = '\0';
		puts(str);
	}
	int main() {
		
		char s[100];
		gets(s);
		rmAdjacent(s);
		
		return 0;
	}
