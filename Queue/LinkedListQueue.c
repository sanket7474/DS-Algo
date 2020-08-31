#include<stdio.h>
#include<stdlib.h>
	struct ListNode {
		
		int data;
		struct ListNode *next;
	};
	struct Queue {
		
		struct ListNode *front;
		struct ListNode *rear;
	};
	
	struct Queue *create() {
		
		struct Queue *Q;
		
		Q = (struct Queue*)malloc(sizeof(struct Queue));
		Q->front = Q->rear = NULL;
	}
	void enQ(struct Queue *Q , int data) {
		
		struct ListNode *node;
		
		node = (struct ListNode*)malloc(sizeof(struct ListNode));
		node->next = NULL;
		node->data = data;
		if(Q->rear)
			Q->rear->next = node;
		Q->rear = node;
		
		if(Q->front == NULL)
			Q->front = node;
	}
	int isEmpty(struct Queue *Q) {
		
		return Q->front == NULL;
	}
	
	int deQ(struct Queue *Q) {
		int data = 0 ;
		struct ListNode *temp;
		
		if(isEmpty(Q))
			printf("\nQueue is Empty");
		else {
			
			temp = Q->front;
			data = Q->front->data;
			
			Q->front = Q->front->next;
			free(temp);
			Q = NULL;
			return data;
		}  
	}
	int main() {
		int c,n;
		struct Queue *Q;
		Q = create();
		
		do{
			printf("\n\n1: EnQ\n2: DeQ\n3:Exit\n\nEnter Choice:\t");
			scanf("%d",&c);
			
			if(c == 1) {
				printf("\nENter Data:\t");
				scanf("%d",&n);
				enQ(Q,n);
			}
			else if(c == 2) {
				
				n = deQ(Q);	
				printf("\nRemoved: %d",n);
			}
		}while(c <= 2);
		return 0;
	}
