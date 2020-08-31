#include<stdio.h>
#include<stdlib.h>
	#define MAXSIZE 10
	
	struct ArrayStack {
		
		int top;
		int cap;
		int *arr;
	};
	
	struct ArrayStack *createStack() {
		
		struct ArrayStack *s = (struct ArrayStack *)malloc(sizeof(struct ArrayStack));
		s->cap = MAXSIZE;
		s->top = -1;
		
		s->arr = (int *)malloc(s->cap*sizeof(int));
		
		return s;
	}
	int isEmpty(struct ArrayStack *s) {
		
		return (s->top == -1);
	}
	int isFull(struct ArrayStack *s) {
		
		return s->top == s->cap - 1;
	}
	void push(struct ArrayStack *s , int data) {
		
		if(isFull(s))
			printf("\nCannot Push Stack is full");
		else
			s->arr[++s->top] = data;
	}
	int pop(struct ArrayStack *s) {
		
		if(isEmpty(s))
			printf("Cannot pop stack is empty");
	 else
			return s->arr[s->top--]; 
	}
	void print(struct ArrayStack *s) {
		int i;
		for( i = s->top ; i >= 0 ; i--) {
			printf("\n");
			printf("|	%d	|",s->arr[i]);
			printf("\n --------------- ");
		}
	}
 	
	int main() {
		int c,n;
		struct ArrayStack *s;
		s = NULL;
		s = createStack();
		
		do {
			printf("\n\n1: Push\n2: Pop\n3: Exit\n\nEnter Choice:\t");
			scanf("%d",&c);
			
			if(c == 1) {
				printf("\nEnter data to push:\t");
				scanf("%d",&n);
				push(s,n);
				print(s);
			}
			else if(c == 2) {
				
				n = pop(s);
				printf("\nPoped %d",n);
				print(s);
			}
		}while(c!= 3);
		return 0;
	}
