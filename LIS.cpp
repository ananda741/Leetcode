#include<iostream>
#include<algorithm>
using namespace std;

//Building bridges across river LIS modification
struct bank_pair{
	int north;
	int south;
};

int formula(bank_pair a,bank_pair b){
	return (a.south > b.south)?0:1;
}

int findpos(int *arr,int start,int end,int target){
	int mid;
	while(start<=end){
		mid = (start+end)/2;
		if(arr[mid] == target)
			return mid;
		else if(arr[mid] < target)
			start = mid+1;
		else
			end = mid-1;
	}
	if(arr[mid] > target)
		return mid;
	else
		return mid+1;
}

int LIS(int *arr,int len){
	if(len == 0) return 0;
	int table[100];
	table[0] = arr[0];
	int i,j,size = 1;
	for(i=1;i<len;i++){
		if(table[0] > arr[i])
			table[0] = arr[i];
		else if(table[size-1] < arr[i])
			table[size++] = arr[i];
		else
			table[findpos(table,0,size-1,arr[i])] = arr[i];
		for(j=0;j<size;j++)
			cout<<table[j]<<" ";
		cout<<endl;
	}	

	return size;	
}

int main(){
	int i;
	bank_pair pairs[] = {{7,5},{4,3},{3,2},{6,4},{2,6},{1,1},{5,7}};

	sort(pairs,pairs+7,formula);
	for(i=0;i<7;i++){
		cout<<pairs[i].north<<" "<<pairs[i].south<<endl;
	}
	int arr[7];
	for(i=0;i<7;i++){
		arr[i] = pairs[i].north;
	}
	for(i=0;i<7;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	//int size = sizeof(arr)/sizeof(arr[0]);
	cout<<LIS(arr,7)<<endl;
}
