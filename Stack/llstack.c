#include<stdio.h>
#include<stdlib.h>
	struct ListNode {
		
		int data;
		struct ListNode* next;
	};
	
	void push(struct ListNode** top , int data) {
		
		struct ListNode* temp;
		
		temp = (struct ListNode*)malloc(sizeof(struct ListNode));
		temp->next = *top;
		temp->data = data;
		*top = temp;
	}
	int pop(struct ListNode** top) {
		struct ListNode* temp;
		int data;
		if(*top == NULL) 
			printf("Stack is Empty!");
		else {

			temp = *top;
			data = temp->data;
			*top = *top->next;
			
		}
	}
	int main() {
		
		struct ListNode* top;
		top = NULL;
		return 0;
	}
