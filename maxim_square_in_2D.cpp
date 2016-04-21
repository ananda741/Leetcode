#include<iostream>
using namespace std;

void maxim_square(int nums[][5],int row,int col){
	int **aux,i,j;
	aux = new int*[row];

	for(i=0;i<row;i++)
		aux[i] = new int[col];

	for(i=0;i<row;i++)
		aux[i][0] = nums[i][0];
	
	for(i=0;i<col;i++)
		aux[0][i] = nums[0][i];

	int max_i,max_j,max_val = 0;

	for(i=1;i<row;i++){
		for(j=1;j<col;j++){
			if(nums[i][j] == 1){
				aux[i][j] = min(aux[i][j-1],min(aux[i-1][j],aux[i-1][j-1]))+1;
				if(aux[i][j] > max_val){
					max_val = aux[i][j];
					max_i = i;
					max_j = j;
				}
			}
			else
				aux[i][j] = 0;
		}
	}
	

	for(i = max_i;i>max_i-max_val;i--){
		for(j = max_j;j>max_j-max_val;j--)
			cout<<nums[i][j]<<" ";
		cout<<endl;
	}
}

int main(){
	int nums[][5] = {{0,1,1,0,1},{1,1,0,1,0},{0,1,1,1,0},{1,1,1,1,0},{1,1,1,1,1},{0,0,0,0,0}};
	int i;
	int row = 6,col =5;
	maxim_square(nums,row,col);
}
