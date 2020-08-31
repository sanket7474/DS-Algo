#include<stdio.h>
#include<stdlib.h>

   
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

            // G->v[u][v] = 1; // if The Graph is undirected

        }
        return G;
    }