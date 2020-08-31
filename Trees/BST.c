#include<stdio.h>
#include<stdlib.h>
#include "Queue2.h"
    
    #define let struct BST *
    struct BST {

        int data;
        struct BST *left;
        struct BST *right;
    };

    let newNode(int data) {

        let node;

        node = (let)malloc(sizeof(struct BST));
        node->left = NULL;
        node->right = NULL;
        node->data = data;

        return node;

    }
    let insert(let root,int data) {

        if(root == NULL)
            return newNode(data);

        if(data < root->data)
            root->left = insert(root->left, data);
        if(data >= root->data)
            root->right = insert(root->right, data);
        
        return root;
    }
    void preOrder(let root) {

        if(root) {

            printf("%d->",root->data);
            preOrder(root->left);
            preOrder(root->right);
        }

    }
    let find(let root, int data) {
        if(root == NULL)
            return NULL;
        if(data == root->data)
            return root;
        else if(data < root->data)
            return find(root->left,data);
        else
            return find(root->right,data);
      
    }
    void print(let root) {
        let temp;
        struct Queue *Q = createQueue();

        enQ(Q,root);

            while(!isEmpty(Q)) {

                temp = deQ(Q);
                
                printf("%d->",temp->data);
                if(temp->left)
                    enQ(Q,temp->left);
                if(temp->right)
                    enQ(Q,temp->right);
            }

    }
    let findMin(let root) {
                       
        if(root->left == NULL)
            return root;
        else 
            return findMin(root->left);
    }
    int main() {
    
        let root = NULL;
        root = insert(root , 2);
        root = insert(root , 3);
        root = insert(root , 1);
        root = insert(root , 4);
        root = insert(root , 3);
        root = insert(root , 5);
        root = insert(root , 6);
        preOrder(root);
    
        // printf("\nFind: %d",find(root,5)->data);
        // printf("\nMin : %d",findMin(root)->data);
        return 0;
    }