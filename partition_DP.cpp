#include<iostream>
using namespace std;

bool partition(int *arr,int size){
	int sum = 0,i,j;
	for(i = 0;i<size;i++){
		sum+=arr[i];
	}
	if(sum%2 != 0)
		return false;

	bool part[size+1][sum/2+1];

	for(i=0;i<size+1;i++)
		part[i][0] = true;

	for(i=0;i<sum/2+1;i++)
		part[0][i] = false;

	for(i=1;i<size+1;i++){
		for(j=1;j<sum/2+1;j++){
			if(j < arr[i])
				part[i][j] = part[i-1][j];
			else{
				if(part[i-1][j] == true)
					part[i][j] = part[i-1][j];
				else
					part[i][j] = part[i-1][j-arr[i]];
			}
		}
	}

	return part[size][sum/2];
}

int main(){
	int arr[] = {3,1,1,2,2,1};
	cout<<partition(arr,6);
}
