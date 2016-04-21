#include<iostream>
//#include<vector>
using namespace std;

int median(int *arr,int len){
	if(len % 2 != 0)
		return arr[len/2];
	else{
		int val = arr[len/2 - 1] + arr[len/2];
		return val/2;
	}
}

int getMedian(int *arr1,int *arr2,int n){
	if(n <= 0)
		return -1;
	if(n == 1)
		return (arr1[0]+arr2[0])/2;
	if(n == 2)
		return (max(arr1[0],arr2[0]) + min(arr1[1],arr2[1]))/2;

	int m1,m2;
	m1 = median(arr1,n);
	m2 = median(arr2,n);
	
	if(m1 == m2)
		return m1;

	if(m1 < m2){
		if(n%2 == 0 )
			return getMedian(arr1 + n/2 - 1,arr2,n - n/2 + 1);
		else
			return getMedian(arr1 + n/2,arr2,n - n/2);			
	}
	else{
		if(n%2 == 0)
			return getMedian(arr2 + n/2 - 1,arr1,n - n/2 + 1);
		else
			return getMedian(arr2+ n/2,arr1,n - n/2);
	}
}


int main(){
	int arr1[]={1, 12, 15, 26, 38},arr2[] = {2, 13, 17, 30, 45};
	cout<<getMedian(arr1,arr2,5)<<endl;
}
