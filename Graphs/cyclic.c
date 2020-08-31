#include<stdio.h>
#include "graph.h"

    #define vertex 6

    int isCyclic(struct graph *G , int v , int visited[] , int stack[]) {

        if(visited[v] == 0) {

            visited[v] = 1;
            stack[v] = 1;

            for(int i = 0 ; i < G->V ; i++) {

                if(!visited[i] && G->Adj[v][i] && isCyclic(G,i,visited,stack))
                    return 1;
                else if(stack[i] && G->Adj[v][i])
                    return 1;
            }

        }

        stack[v] = 0;
        return 0;

    }
    int cyclic(struct graph *G) {

        int visited[G->V];
        int stack[G->V];

        for(int i = 0 ; i < G->V ; i++) {

            visited[i] = 0;
            stack[i] = 0;
        }

        for(int i = 0 ; i < G->V ; i++) 
            if(isCyclic(G,i,visited,stack))
                return 1;

        return 0;

    }
    int main() {

        struct graph *G = createGraph();
        
        if(cyclic(G))
            printf("Yes");
        else
            printf("No");
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


    4 4
    0 1
    1 2
    2 3
    3 1

    */