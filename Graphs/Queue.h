
#include<stdio.h>
#include<stdlib.h>

struct ArrayQueue {
		
		int front;
		int rear;
		int cap;
		int *arr;
	};
	struct ArrayQueue * createQueue(int size) {
		
		struct ArrayQueue * Q = (struct ArrayQueue *) malloc(sizeof(int));
		
		Q->cap = size;
		Q->arr = (int *)malloc(size*sizeof(int));
		Q->rear = -1;
		Q->front = -1;
		return Q;
	}
	int isFullQ(struct ArrayQueue * Q) {
		
		return Q->rear == (Q->cap - 1);
        
	}
	void EnQ(struct ArrayQueue * Q , int data) {
		
		if(isFullQ(Q))
			printf("\nQueue is Full");
		else {
			
			Q->rear++;
			Q->arr[Q->rear] = data;
			
			if(Q->front == -1)
				Q->front = Q->rear;
			
		}
	}
	int isEmpty(struct ArrayQueue * Q) {
	
		return Q->front > Q->rear;
	}
	
	int deQ(struct ArrayQueue * Q) {
		int data;
		if(isEmpty(Q))
			printf("Queue is Empty");
		
			else {
			data = Q->arr[Q->front];
			Q->front++;
			return data;
			}
			
		
	}