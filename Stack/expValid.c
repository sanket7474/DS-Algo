#include<stdio.h>
#include<stdlib.h>
#include<string.h>

	#define MAXSIZE 10
	
	struct ArrayStack {
		
		int top;
		int cap;
		char *arr;
	};
	
	struct ArrayStack *createStack() {
		
		struct ArrayStack *s = (struct ArrayStack *)malloc(sizeof(struct ArrayStack));
		s->cap = MAXSIZE;
		s->top = -1;
		
		s->arr = (char *)malloc(s->cap*sizeof(char));
		
		return s;
	}
	int isEmpty(struct ArrayStack *s) {
		
		return (s->top == -1);
	}
	int isFull(struct ArrayStack *s) {
		
		return s->top == s->cap - 1;
	}
	void push(struct ArrayStack *s , char data) {
		
		if(isFull(s))
			printf("\nCannot Push Stack is full");
		else
			s->arr[++s->top] = data;
	}
	char pop(struct ArrayStack *s) {
		
		if(isEmpty(s))
			printf("Cannot pop stack is empty");
	 else
			return s->arr[s->top--]; 
	}
	int top(struct ArrayStack *s) {
		
		return s->arr[s->top];
	}
	void print(struct ArrayStack *s) {
		int i;
		for( i = s->top ; i >= 0 ; i--) {
			printf("\n");
			printf("|	%c	|",s->arr[i]);
			printf("\n --------------- ");
		}
	}
 	int getCode(char c) {
 		
 		switch(c) {
 			
 			case '(':
 			case ')' : return 1;
 			case '{':
 			case '}' : return 2;
 			case '[':
 			case ']' : return 3;
		 }
	}
	int main() {
		
		char str[100];
		struct ArrayStack *s;
		int i;
		
		s = NULL;
		s = createStack();
		
		gets(str);
		
		for(i = 0 ; i < strlen(str) ; i++) {
			
			if(str[i] != ' ') {
			
				if(str[i] == '{' || str[i] == '(' || str[i] == '[')
					push(s,str[i]);
				else {
					
					if( getCode(str[i]) == getCode(top(s)) )
						pop(s); 
					else
						push(s,str[i]);
				}
		}
		}
		if(isEmpty(s))
			printf("Valid");
		else
			printf("Invalid");
		return 0;
	}
