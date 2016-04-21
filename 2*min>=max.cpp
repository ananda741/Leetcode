#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

int bin_search(vector<int> &arr,int num){
	int start = 0,end = arr.size()-1,mid = 0;
	while(start<=end){
		mid = (start+end)/2;
		if(arr[mid] == num)
			return mid;
		else if(arr[mid] > num)
			end = mid - 1;
		else
			start = mid+1;
	}	
	return mid-1;
}

int main(){
	vector<int> arr({4, 5, 100, 9, 10, 11, 12, 15, 200});
	sort(arr.begin(),arr.end());
	int first = 0,last = arr.size()-1;
	int count = 0,min = INT_MAX,i;

	for(i=0;i<last;i++){
		if(2*arr[i] >= arr[last])
			count = i;
		else{
			int index = bin_search(arr,2*arr[i]);
			//cout<<"index = "<<index<<endl;
			count = i+(last - index);	
		}
		if(min>count)
			min = count;
	}	

	cout<<min;
}
