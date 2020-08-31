#include<stdio.h>
#include<stdlib.h>
	struct List {
		
		int data;
		struct List *next;
	};
	void create(struct List **head) {
		struct List *node; 
		if(*head == NULL) {
			
			node = (struct List *)malloc(sizeof(struct List));
			node->data = 10;
			*head = node;
		}
		
		
	}
	int main() {
		
			struct List *head;
			
			head = NULL; 
		
			create(&head);
			if(head == NULL)
				printf("Head is Null");
			else
			printf("%d",head->data);	
		return 0;
	}
