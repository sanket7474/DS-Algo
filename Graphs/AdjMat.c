#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"
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




    void DFS(struct graph *G , int v , int *visited) {
        
        visited[v] = 1;
        printf("%d->",v);
        for(int i = 0 ; i < G->V ; i++)
            if(!visited[i] && G->Adj[v][i])
                DFS(G,i,&visited[0]);
    
    }

    void DFSTraversal(struct graph *G) {
        int i;
        int visted[G->V];

        for(i = 0 ; i< G->V ; i++) 
            visted[i] = 0;

        for(i = 0 ; i < G->V ; i++)
            if(!visted[i]) {
                DFS(G,i,&visted[0]);
                // printf("\n");
            }

    }

    void BFS(struct graph *G , int v , int *visited) {

        struct ArrayQueue *Q = createQueue(20); 
        int sel;
        visited[v] = 1;
        
        EnQ(Q,v);

        while(!isEmpty(Q)) {

            sel = deQ(Q);
              
            printf("%d->",sel);
            visited[sel] = 1;
            for(int i = 0 ; i < G->V ; i++)
                if(!visited[i] && G->Adj[sel][i]) 
                    EnQ(Q,i);
        }

    }

    void BFSTraversal(struct graph *G) {

        int visited[G->V];

        for(int i = 0 ; i < G->V ; i++)
            visited[i] = 0;
        
        for(int i = 0 ; i < G->V ; i++)
            if(!visited[i]) {
                BFS(G,i,&visited[0]);
                // printf("\n");
            }
    }


    int main() {

        struct graph *G = createGraph();
        int visted[G->V];

       DFSTraversal(G);
        printf("\n");
        BFSTraversal(G);
        return 0;
    }
    
    /*

    6 6
    0 1
    0 2
    1 3
    2 5
    3 4
    5 4

    */