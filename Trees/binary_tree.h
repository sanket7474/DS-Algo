#include<stdlib.h>
#include "Queue.h"
struct BinaryTree {
		
		int data;
		struct BinaryTree * left;
		struct BinaryTree * right;
	};
	struct BinaryTree * create(struct BinaryTree * root , int data) {
		
		root = (struct BinaryTree *)malloc(sizeof(struct BinaryTree));
		root->data = data;
		root->left = NULL;
		root->right = NULL;
		return root;
	
	}
	
	struct BinaryTree * insert(struct BinaryTree * root , int data) {
		 
		struct Queue *Q = createQueue();
		struct BinaryTree * temp;
		struct BinaryTree * node;
		node = (struct BinaryTree *)malloc(sizeof(struct BinaryTree));
		node->left = node->right = NULL;
		node->data = data;
		
		if(root == NULL) {
	
			root = node;
			return root;
		}
		
		enQ(Q,root);
		
		while(!isEmpty(Q)) {
			
			temp = deQ(Q);
			
			if(temp->left)
				enQ(Q,temp->left);
			else {
				
				temp->left = node;
				return root;
			}
			if(temp->right)
				enQ(Q,temp->right);
			else {
				
				temp->right = node;
				return root;
			}
		}
		
	}
	
	struct BinaryTree * newNode(int data) {
		
		struct BinaryTree * node;
		
		node= (struct BinaryTree *)malloc(sizeof(struct BinaryTree));
		node->data = data;
		node->left = NULL;
		node->right = NULL;
		
		return node;
	}