#include<stdio.h>
#include<stdlib.h>

	#define let struct ArrayQueue *
	struct ArrayQueue {
		
		int front;
		int rear;
		int cap;
		int *arr;
	};
	let createQueue(int size) {
		
		let Q = (let) malloc(sizeof(int));
		
		Q->cap = size;
		Q->arr = (int *)malloc(size*sizeof(int));
		Q->rear = -1;
		Q->front = -1;
		return Q;
	}
	int isFullQ(let Q) {
		
		return Q->rear == (Q->cap - 1);
	}
	void EnQ(let Q , int data) {
		
		if(isFullQ(Q))
			printf("\nQueue is Full");
		else {
			
			Q->rear++;
			Q->arr[Q->rear] = data;
			
			if(Q->front == -1)
				Q->front = Q->rear;
			
		}
	}
	int isEmpty(let Q) {
	
		return Q->front == -1;
	}
	
	int deQ(let Q) {
		
		if(isEmpty(Q))
			printf("Queue is Empty");
		else {
			if(Q->front >= Q->rear)
				Q->front = -1;
			else
			Q->front++;
		}	
		
	}
	
	void print(let Q) {
		
		int i;
		printf("\n\n");
		
		for(i = Q->front ; i <= Q->rear ; i++) {
			
			printf("%d\t",Q->arr[i]);
		}
		
	}
	
	int main() {
		
		let Q;
		int n,data;
		Q = createQueue(10);
		
		do {
			printf("\n\n1: EnQueue\n2: DeQueue\n3: Exit\nEnter Choice:\t");
			scanf("%d",&n);
			
			if(n == 1) {
				printf("\nEnter Data To Enqueue:\t");
				scanf("%d",&data);
				EnQ(Q,data);
				print(Q);
			}
			else if(n == 2) {
				deQ(Q);
				print(Q);
			}
		}while(n<3);
		return 0;
	}
