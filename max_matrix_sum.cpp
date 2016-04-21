#include<iostream>
#include<limits.h>
using namespace std;

bool isValid(int row,int col){
	if(row >4 || col > 4)
		return false;
	return true;
}

int max_val = INT_MIN;

int max_matrixsum(int arr[][5],int row,int col){
	int max = 0;
	if(row == 4 && row == 4){
		max+= arr[4][4];
		if(max_val < max)
			max_val = max;
		return max_val;
	}

	if(isValid(row,col)){
		max+= max_matrixsum(arr,row+1,col);
		max+= max_matrixsum(arr,row,col+1);
	}
	return max_val;
}

int main(){
	int arr[][5] = {{1,1,0,6,1},{1,9,0,18,1},{2,6,1,3,1},{5,3,13,12,9},{13,4,10,4,1}};
	cout<<max_matrixsum(arr,0,0);
}
