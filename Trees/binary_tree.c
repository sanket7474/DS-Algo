#include<limits.h>
#include "binary_tree.h"

	#define let struct BinaryTree*
	
	

	int max = 0;
	void preOrder(let root) {
		
		if(root) {
			if(max < root->data)
				max = root->data;
			printf("%d ",root->data);
			preOrder(root->left);
			preOrder(root->right);
		}
		
	}

	void inOrder(let root) {
		
		if(root) {
			
			inOrder(root->left);
			printf("%d ",root->data);
			inOrder(root->right);
		}
	}

	void postOrder(let root) {
		
		if(root) {
			
			postOrder(root->left);
			postOrder(root->right);
			printf("%d ",root->data);
		}
	}
	
	void levelOrder(let root) {
		
		struct Queue *Q = createQueue();
		struct BinaryTree *temp;
		
		enQ(Q,root);
		
		while(!isEmpty(Q)) {
			
			temp = deQ(Q);
			printf("%d ",temp->data);
			if(temp->left)
				enQ(Q,temp->left);
			if(temp->right)
				enQ(Q,temp->right);
		}	
	}
	
	int findMax(let root) {
		
		int root_val , right , left , max = INT_MIN;
		
		if(root != NULL) {
			
			root_val = root->data;
			left = findMax(root->left);
			right = findMax(root->right);
			
			if(left > right)
				max = left;
			else
				max = right;
			
			if(root_val > max)
				max = root_val;
			
		}
		return max;
	}
	
	
	
	int size(let root) {
		
		if(root == NULL)
			return 0;
		else return 1 + size(root->left) + size(root->right);
	
	}
	
	int largestHeight(let root) {
		
		int lh , rh;

		if(root == NULL)
			return 0;
		else {

			lh = largestHeight(root->left);
			rh = largestHeight(root->right);

			
				if(lh > rh)
					return lh+1;
				else
					return rh+1;
			
		}
	}

	int largestHeightLoop(let root) {
		
		int level = 0;
		struct Queue *Q;
		let temp;
		Q = createQueue();
		
		if(!root)
			return 0;
		enQ(Q,root);
		enQ(Q,NULL);

		while(!isEmpty(Q)) {

				temp = deQ(Q);

				if(temp == NULL) {

					if(!isEmpty(Q))
						enQ(Q,NULL);
					level++;
				}
				else {

					if(temp->left)
						enQ(Q,temp->left);
					if(temp->right)
						enQ(Q,temp->right);
				}

		}

		return level;
	}

	int leaves(let root) {

		int count = 0;
		struct Queue *Q = createQueue();
		let temp;

		enQ(Q,root);
		
		while(!isEmpty(Q)) {
 
			temp = deQ(Q);

			if(temp->right == NULL && temp->left == NULL)
				count++;
			else {

				if(temp->left)
					enQ(Q,temp->left);
				if(temp->right)
					enQ(Q,temp->right);
			}
		}

	return count;


	}

	int maxLevelSum(let root) {

			struct Queue *Q = createQueue();
			let temp;
			int sum = 0,maxSum=0,maxLevel=1;
			int level = 1;
			enQ(Q,root);
			enQ(Q,NULL);

			while(!isEmpty(Q)) {

				temp = deQ(Q);
				
				if(temp == NULL) {

					if(!isEmpty(Q))
						enQ(Q,NULL);
					if(sum > maxSum){

						maxSum = sum;
						maxLevel = level;
					}
					sum = 0 ;
					level++;

				}
				else {
					sum += temp->data;
					if(temp->left)
						enQ(Q,temp->left);
					if(temp->right)
						enQ(Q,temp->right);
				}

			}
		return maxLevel;
	}


	void printArray(int path[] , int size) {

		int i;
		printf("\n\n");
		for(i = 0 ; i < size ; i++)
			printf("%d->",path[i]);
	}
	
	void printPath(let root , int path[] , int index) {
		
		if(root == NULL)
			return ;
		path[index] = root->data;
		index++;
		if(root->left == NULL && root->right == NULL)
			printArray(path , index);

		else {

			printPath(root->left , path , index);
			printPath(root->right,path,index);
		}

	}

	int hasPathSum(let root , int sum) {

		int s = 0;
		
		if(root == NULL)
			return sum == 0;
		
		sum -= root->data;
		

		return hasPathSum(root->left , sum) || hasPathSum(root->right,sum);
		
		

	}
	let mirror(let root) {

		let temp;

		if(root) {

			mirror(root->left);
			mirror(root->right);

			temp = root->left;
			root->left = root->right;
			root->right = temp;
		}
		return root;
	}	
	int main() {
			int data;
			let root;
			root = NULL;
			
			root = insert(root,1);
			root = insert(root,2);
			root = insert(root,3);
			root = insert(root,4);
			root = insert(root,5);
			root = insert(root,6);
			root = insert(root,7);
			// root = insert(root,8);			
			// printf("\n preorder (DLR)");	
			// preOrder(root);
			// printf("\nMAx: %d",max);
			// printf("\n\n ineorder (LDR)");	
			// inOrder(root);
			// printf("\n\n postorder (LRD)");	
			// postOrder(root);
			// printf("\n\n Level Order:\n");
			// levelOrder(root);
			
			// printf("\nMax:%d",findMax(root));
			
			// printf("\n Size: %d",size(root));
			// printf("Height: %d",largestHeightLoop(root));

			// printf("No : %d",leaves(root));

			// printf("Max Level: %d" , maxLevelSum(root));
			int arr[10];
			// printPath(root,arr,0);

			// printf("%d",hasPathSum(root,11));
			let root2 = mirror(root);
			levelOrder(root2);
		return 0;
	}
