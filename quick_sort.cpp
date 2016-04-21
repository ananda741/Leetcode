#include<iostream>
#include<vector>
using namespace std;


int partition(vector<int> &arr,int start,int end){
	int pivot = arr[end];
	int pindex = start;
	
	for(int i=start;i<end;i++){
		if(arr[i] < pivot){
			swap(arr[i],arr[pindex]);
			pindex++;
		}		
	}

	swap(arr[pindex],arr[end]);
	return pindex;
}


void Quicksort(vector<int> &arr,int start,int end){
	if(start > end) return;

	int pindex = partition(arr,start,end);
	Quicksort(arr,start,pindex-1);
	Quicksort(arr,pindex+1,end);
}

int main(){
	vector<int> arr({2,5,3,1,0,7,9,8});
	int i,len = arr.size();
	Quicksort(arr,0,len-1);
	
	for(i=0;i<len;i++)
		cout<<arr[i]<<" ";
}


