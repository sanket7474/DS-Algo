#include<stdio.h>
#include<stdlib.h>
	struct ListNode {
		
		struct BST *data;
		struct ListNode *next;
	};
	struct Queue {
		
		struct ListNode *front;
		struct ListNode *rear;
	};
	
	struct Queue *createQueue() {
		
		struct Queue *Q;
		
		Q = (struct Queue*)malloc(sizeof(struct Queue));
		Q->front = Q->rear = NULL;
		return Q;
	}
	void enQ(struct Queue *Q , struct BST* data) {
		
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
	
	struct BST* deQ(struct Queue *Q) {
		struct BST* data;
		struct ListNode *temp;
		
		if(isEmpty(Q))
			printf("\nQueue is Empty");
		else {
			
			temp = Q->front;
			data = Q->front->data;
			
			Q->front = Q->front->next;
			free(temp);
			
			return data;
		}  
	}
