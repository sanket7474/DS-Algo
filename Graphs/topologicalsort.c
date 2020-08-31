#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
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

    struct ArrayStack *s;

    void sort(struct graph *G , int v , int *visited) {

        visited[v] = 1;

        for(int i = 0 ; i < G->V ; i++)
            if(!visited[i] && G->Adj[v][i])
                sort(G,i,&visited[0]);

        push(s,v);
    }

    void topologicalSort(struct graph *G) {

        int visited[G->V];
        s =  createStack();
        for(int i = 0 ; i < G->V  ; i++)
            visited[i] = 0;
        
        for(int i = 0 ; i < G->V ; i++)
            if(!visited[i])
                sort(G , i , &visited[0]);

        while(!isEmpty(s)) {

            printf("%d->",pop(s));
        }

    }
    int main() {

        struct graph *G = createGraph();
        
        topologicalSort(G); 
        return 0;
    }
    
    /*
    
    8 9
    0 1
    0 3
    1 5
    2 3
    3 6
    3 5
    3 7
    4 7
    4 1

    */