#include<iostream>
using namespace std;

void Segregate(int *A,int n){
	int lo=0,mid=0,hi=n-1;
	while(mid<=	hi){
		switch(A[mid]){
			case 0 : swap(A[lo++],A[mid++]);
				 break;
			case 1 : mid++;
				 break;
			case 2 : swap(A[mid],A[hi--]);		
				 break;
		}
	}
}

int main(){
	int arr[] = {0,1,0,2,0,1,1,2,2,0,1,0,2,0,1,0,2,1,2};
	int size,i;
	size = sizeof(arr)/sizeof(arr[0]);
	Segregate(arr,size);
	for(i=0;i<size;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}
