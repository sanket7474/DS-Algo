/*


    Shortest Path for *unweighted* graph



*/


#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"


    #define vertex 5
    struct graph
    {
        /* data */
        int V; // for No of Vertex
        int E; // for No of Edges

        int **Adj; // 2D array matrix
    };
    int **allocate(int n) {
        
        int **arr = (int **)malloc(n * sizeof(int *));

        for(int i = 0 ; i < n ; i++)
            arr[i] = (int *)malloc(n*sizeof(int));
        return arr;
    }
    struct graph * createGraph() {

        int i,j,k,v,u;

        struct graph *G = (struct graph *)malloc(sizeof(struct graph ));

        if(!G) {

            printf("Mem Error");
            return NULL;
        }
        
        printf("\nEnter V & E:\t");
        scanf("%d%d", &G->V , &G->E);
        G->Adj = allocate(G->V);
        //or

        // G->Adj = malloc(sizeof(int) * (G->V * G->V));
        for(i = 0 ; i < G->V ; i++) 
            for( j = 0 ; j < G->V ; j++) 
                    G->Adj[i][j] = 0;
        
        for(i = 0 ; i < G->E ; i++) {
            printf("\nReading Edge:\t");
            scanf("%d%d",&v,&u);

            G->Adj[v][u] = 1;

            // G->v[j][i] = 1; // if The Graph is undirected

        }
        return G;
    }
    int distance[vertex];
    int path[vertex];
    void shortestPath(struct graph *G , int s) {

        int sel;

        struct ArrayQueue *Q = createQueue(G->V);
        
        EnQ(Q,s);
        for(int i = 0 ; i < G->V ; i++)
            distance[i] = -1;
        
        distance[s] = 0;
        while(!isEmpty(Q)) {

            sel = deQ(Q);

            for(int i = 0 ; i < G->V ; i++)
                if(G->Adj[sel][i]) {

                    if(distance[i] == -1) {

                        distance[i] = distance[sel]+1;
                        path[i] = sel;
                        EnQ(Q,i);
                    }
                }
        }

    }
    int main() {
        
        int s = 0;
        struct graph *G = createGraph();
        
        shortestPath(G,s);
       
        printf("From\tTO\tdist\tpath");
        
            for(int j = 0 ; j < G->V ; j++)
                printf("\n%d\t%d\t%d\t%d",s , j , distance[j]  , path[j]); 

          return 0;
    }
                          
    /*
    
    5 6
    0 1
    0 2
    1 4
    2 1
    2 3
    3 4

    */  
