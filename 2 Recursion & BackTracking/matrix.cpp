#include<bits/stdc++.h>

	using namespace std;
	
	int getVal(int (*a)[5] , int i , int j , int r  , int c) {
		
		if(i < 0 || i >=r || j < 0 || j >= c)
			return 0;
		return a[i][j];
		
	}
	void maxBlock(int (*a)[5] , int i, int j , int c , int r , int size , int visited[][5] , int &max) {
		
		if(i >= c || j >= r)
			return;
		
		visited[i][j] = 1;
		size++;
		
		if(size > max)
			max = size;
		
		int directions[][2] = {{1,1} ,{1,0} , {0,1} , {-1,1} , {-1,0} , {0,-1} , {-1,-1} , {1,-1}};
		
		for(int ii = 0 ; ii < 8 ; ii++) {
			
			int newi = i + directions[ii][0];
			int newj = j + directions[ii][1];
			
			int val = getVal(a,newi,newj,r,c);
			
			if(val > 0 && (visited[newi][newj] == 0)) {
				
				maxBlock(a,newi,newj,c,r,size,visited,max);
			}
		}
			visited[i][j] = 0;
	}
	
	void findMaxOne(int (*a)[5] , int r ,int c) {
		int max = 0;
		
		int visted[r][5];
		for(int i = 0 ; i < r ; i++) 
			for(int j = 0 ; j < c ; j++ )
				visted[i][j] = 0;
		for(int i = 0 ; i< r ; i++) {
			for(int j = 0 ; j< c ;j++) {
				
				if(a[i][j] == 1) 
					maxBlock(a, i , j , c , r, 0 , visted , max);
			}
		}
		
		printf("%d",max);
	}
	int main() {
		
		int a[][5] = {{1,1,0,0,1} , {0,1,0,0,1} , {0,1,0,0,0} ,{0,1,1,0,1},{0,0,0,0,0}};
		
		findMaxOne(a,5,5);		
		return 0;
	}
