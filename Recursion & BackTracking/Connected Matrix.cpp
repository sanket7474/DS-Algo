/*

		Finding the length of conneted cells of 1s(regions) in an matrax of 0s and 1s


*/
#include<bits/stdc++.h>

	int getVal(int (*a)[5] , int i , int j , int L , int H) {
		
		if(i < 0 || i >= L || j < 0 || j >= H)
			return 0;
		else 
			return a[i][j];
	}
	void findMaxBlock(int (*a)[5] , int r , int c , int L , int H , int size , bool **cntarr , int &maxsize) {
		
		if(r >= L || c >= H)
			return;
		cntarr[r][c] = true;
		size++;
		
		if(size > maxsize)
			maxsize = size;
			
		int direction[][2] = { {-1,0} , {-1,-1} , {0,-1} , {1,-1} , {1,0} , {1,1} , {0,1} , {-1,1}};
		
		for(int i = 0 ; i < 8 ;i++) {
			
			int newi = r + direction[i][0];
			int newj = c + direction[i][1];
			
			int val = getVal(a,newi,newj,L,H);
			
			if(val > 0 && (cntarr[newi][newj] == false )) {
				
				findMaxBlock(a , newi , newj , L , H , size , cntarr , maxsize);
			}
		}
		
		cntarr[r][c] = false;
	}
	bool ** create(int rmax , int colmax) {
		
		bool **arr = new bool*[rmax];
		for(int i = 0 ; i< colmax ; i++)
			arr[i] = new bool[colmax];
			
			return arr;
	}
	int getMaxOnes(int (*a)[5] , int rmax , int colmax) {
		
		int maxsize = 0;
		int size = 0;
		bool **cntarr = create(rmax,colmax);
		
		for(int i = 0 ; i < rmax ; i++) {
			
			for(int j = 0 ; j < colmax ; j++) {
				
				if(a[i][j] == 1)
					findMaxBlock(a,i,j,rmax,colmax,0,cntarr,maxsize);
			}
		}
		
		return maxsize;
	}
	using namespace std;
	int main() {
		
		
		int a[][5] = {{0,1,0,0,0} , {1,1,1,0,0} , {0,0,1,0,1} , {0,0,0,0,1} , {0,1,1,1,0}};
		
		cout<<getMaxOnes(a,5,5)<<endl;
		return 0;
	}
