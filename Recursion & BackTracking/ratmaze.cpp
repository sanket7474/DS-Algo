using namespace std;

#include<bits/stdc++.h>
    
    
    #define loopi for(int i = 0 ; i < n ; i++)
    #define loopj for(int j = 0 ; j < n ; j++)

    char s[100];
    int indx = 0;

    char dir[4] = { 'R' , 'L' , 'D' , 'U'};
    int n;
    int check(int i , int j , int maze[10][10]) {

        return (i >= 0 && i < n && j >= 0 && j < n && maze[i][j] == 1);
    }

    int solveMaze(int maze[10][10] , int i ,int j , int visited[10][10]) {
        

        
        visited[i][j] = 1;
        if(i == (n-1) && j== (n-1))
            return 1;

        int directions[][2] = { {0,1} , {0,-1} , {1,0} , {-1,0} };

        for(int k = 0 ; k < 4 ; k++) {
            
            
           
            int newi = i + directions[k][0];
            int newj = j + directions[k][1];


            if(check(newi , newj , maze)) {
                s[indx] = dir[k];
                indx++;    

            if(visited[newi][newj] == 0 && solveMaze(maze , newi , newj , visited) == 1)
                return 1;
            else 
                indx--;                
            }
            
                
        }
            return 0;
    }

    int main() {
        
        int t;
        cin>>t;

        while(t--) {
        
        cin>>n;
        int maze[n][10];
        int visited[n][10];

        loopi loopj visited[i][j] = 0;
        loopi loopj cin>>maze[i][j];

        if(solveMaze(maze , 0 , 0 , visited)) {
            // cout<<"yes";
            cout<<s;
        }
        else
            cout<<"-1";

        }
        
        return 0;
    }
// 1 1 1 0 0 0 1 0 0 0 1 0 0 0 1 1
// 1 1 1 1 0 0 1 1 1 1 1 1 1 0 1 1
// 1 1 1 1 0 0 1 1 1 1 1 0 1 0 0 1