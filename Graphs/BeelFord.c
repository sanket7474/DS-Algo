#include<stdio.h>
#include<limits.h>
#include "graph.h"
#include "Queue.h"
#define vertex 5

void BellFord(struct graph *G , int start) {

    int distance[G->V] ,sel , wt[G->V][G->V] , d  , path[G->V];
    struct ArrayQueue *Q = createQueue(G->V);

    for(int i = 0 ; i < G->V ; i++)
        distance[i] = INT_MAX;

    distance[start] = 0;
    EnQ(Q,start);

    while(!isEmpty(Q)) {

        sel = deQ(Q);

        for(int i = 0 ; i < G->V ; i++) {
            
            if(G->Adj[sel][i]) {

                printf("Enter weight %d->%d ",sel,i);
                scanf("%d",&wt[sel][i]);
                
                d = distance[sel] + wt[sel][i];

                if(distance[i] > d) {

                    distance[i] = d;
                    path[i] = sel;
                    EnQ(Q,i);
                }
            }

        }


    } 

    printf("\n\nFrom\tTO\tdist\tpath");
        
            for(int j = 0 ; j < G->V ; j++)
                printf("\n%d\t%d\t%d\t%d",start , j , distance[j]  , path[j]); 
    
}

int main() {

    struct graph *G = createGraph();

    BellFord(G,0);

    return 0;
}

/*

    5 6
    0 1
    0 2
    2 1
    2 3
    1 4
    3 4

*/

