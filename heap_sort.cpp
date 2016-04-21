#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void swap(int *a,int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void Max_heapify(vector<int> &arr,int val){
	int i,len = arr.size();
	int l = 2*val+1;
	int r = 2*val+2;
	int maxim = val;

	if(l<len && arr[l] > arr[val])
		maxim = l;
	if(l<r && arr[r] > arr[maxim])
		maxim = r;
	if(maxim != val){
		swap(&arr[maxim],&arr[val]);
		Max_heapify(arr,maxim);
	}	
}

void Build_heap(vector<int> &arr){
	int i,len = arr.size();
	for(i=len/2-1;i>=0;i--)
		Max_heapify(arr,i);
}

vector<int> heap_sort(vector<int> &arr){
	int len = arr.size();
	vector<int> answer;
	while(len != 1){
		answer.push_back(arr[0]);
		arr[0] = arr[len-1];
		arr.erase(arr.begin()+len-1);
		Max_heapify(arr,0);
		len--;
	}
	if(len == 1)
		answer.push_back(arr[0]);

	return answer;
}

int main(){
	vector<int> nums({5,4,7,8,1,2,9,0,3});
	int i,len = nums.size();

	Build_heap(nums);

	vector<int> answer = heap_sort(nums);	
	
	for(i=0;i<len;i++)
		cout<<answer[i]<<" ";
	cout<<endl;
}
