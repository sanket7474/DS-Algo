#include<stdio.h>
#include<stdlib.h>
 
    #define MAXSIZE 5
    struct List
    {
        /* data */
        int vertexNo;
        struct List * next;
    };
    struct List *head[MAXSIZE];


    void add(int s , int d) {

        struct List *temp,*node;

        if(head[s] == NULL) {

            node = (struct List *)malloc(sizeof(struct List));
            node->vertexNo = s;
            node->next = NULL;
            head[s] = node;

        }
        
            
            temp = head[s];
            node = (struct List *)malloc(sizeof(struct List));
            node->vertexNo = d;
            node->next = NULL;
            
            while(temp->next != NULL)
                temp=temp->next;
            
            temp->next = node;
        

    }


    int main() {

       
        
        for(int i = 0 ; i < MAXSIZE ; i++)
            head[i] = NULL;
        

        add(0,1);
        add(0,2);
        add(1,2);
        add(1,3);
        add(2,1);
        add(2,3);
        printf("%d",head[2]->next->next->vertexNo);
        return 0;
    }
    