#include<stdio.h>
#include<stdlib.h>
	struct List {
		
		int data;
		struct List *next;
	};
	struct List * create(struct List *head , int n) {
		struct List *node,*temp; 
		while(n--) {
		
		if(head == NULL) {
			
			node = (struct List *)malloc(sizeof(struct List));
			printf("\n Enter data:\t");
			scanf("%d",&node->data);
			node->next = NULL;
			head = node;
			temp = head;
		}
		else {
		
			node = (struct List *)malloc(sizeof(struct List));
			printf("\n Enter data:\t");
			scanf("%d",&node->data);
			node->next = NULL;
			temp->next = node;
			temp = node;
		}  
	}
		
		return head;
	}
	
	struct List *insert(struct List *head , int pos , int data) {
		
		struct List *node,*temp,*temp2;
		int k = 1;
		
		temp = head;
		node = (struct List *)malloc(sizeof(struct List));
		node->data = data;
		if(pos == 1) {
			
			node->next = head;
			head = node;
			
		}
		else {
		
			while((temp != NULL) && (k < pos)) {
				
				temp2 = temp;
				temp= temp->next;	
				k++;
			}
			temp2->next = node;
			node->next = temp;
		}
		
		return head;
	}
	void print(struct List *head) {
		printf("\n\n");
		while(head) {
			
			printf("%d->",head->data);
			head= head->next;
		}
		printf("NULL");
	}
	
	void printRev(struct List * head) {
		
		if(head == NULL) 
			return;
		else {
			
			printRev(head->next);
			printf("%d->",head->data);
		}
	}
	
	struct List * sort(struct List *head) {
		
		struct List *temp,*temp2;
		
		for(temp = head ; temp->next!= NULL ; temp=temp->next) {
			
			for(temp2 = head ; temp2->next != NULL ; temp2=temp2->next) {
				
					if(temp2->next->data < temp2->data) {
						
						
					}
			}
		}
		
	}
	void change(struct List** head) {
		
		*head = (*head)->next;
		
	}
	void c(struct List* head) {

			head = NULL;
	}
	int main() {
		
			struct List *head;
			int n=5;
			
			head = NULL; 	
			head = create(head,n);
			print(head);
			c(head);
			print(head);
			// change(&head->next->next);
				
		return 0;
	}
