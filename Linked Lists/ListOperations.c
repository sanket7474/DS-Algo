#include<stdio.h>
#include<stdlib.h>	

	#define let struct List *
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
	
	let attach(let head) {
		
		let temp;
		let temp2;
		
		temp = head;
		int i = 1;
			while(temp->next != NULL) {
				
				if(i == 3) 
					temp2 = temp;
					
				temp=temp->next;
				i++;
				
			}
			
			temp->next = temp2;
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
	
	void findLoop(let head) {
		
		let slowptr = head;
		let fastptr = head;
		
		int flag = 0;
		while(slowptr && fastptr && fastptr->next) {
			
			slowptr = slowptr->next;
			fastptr = fastptr->next->next;
			if(slowptr == fastptr) {
				printf("\n%d---%d\n",slowptr->data,fastptr->data);
				flag = 1;
				break;
			}
		}
		if(flag) { 
		
			printf("\nyes");
				
	}
		else
			printf("\no");
	}
	let mergeSort(let head , let head2) {
		
		let res = NULL;
		if(head == NULL) 
			return head2;
		if(head2 == NULL) 
			return head;
		
		if(head->data < head2->data) {
			
			res = head;
			
			res->next=mergeSort(head->next,head2);
		}
		else {
			res = head2;
			res->next = mergeSort(head , head2->next);
		}
		return res;
	}
	int main() {
		
		
		struct List *head;
		head = NULL;
		/* head = create(head,8);
		head = attach(head);
		findLoop(head);*/
		
		let head2;
		head2 = NULL;
		let head3;
		head3 = NULL;
		head = create(head,5);
		head2 = create(head2,5);
		
		head3 = mergeSort( head , head2);
		print(head3);
		return 0;
	}

