#include<iostream>
using namespace std;

void SubArr(int *arr,int len){
	if(len == 0) return;
	int cur_sum = arr[0],start = 0;

	for(int i = 1;i<len;i++){
		while(cur_sum > 0 && start < i-1){
			cur_sum-= arr[start];
			start++;
		}
		if(cur_sum == 0){
			cout<<"From "<<start<<" To "<<i-1;
			return;
		}
		if(i<len) cur_sum+= arr[i];
	}
}

int main(){
	int arr[] = {4,2,-3,1,6};
	int len = sizeof(arr)/sizeof(arr[0]);
	SubArr(arr,len);
}
