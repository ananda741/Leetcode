#include<iostream>
#include<vector>
using namespace std;

void swap(int *val1,int *val2){
	int temp;
	temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}

void min_heapify(vector<int> &arr,int pos){
	int len = arr.size();
	int left = 2*pos+1;
	int right = 2*pos+2;
	
	int maxim = pos;
	if(left < len && (arr[left] < arr[pos]))
		maxim = left;
	if(right < len && (arr[right] < arr[maxim]))
		maxim = right;

	if(maxim != pos)
		swap(&arr[pos],&arr[maxim]);
	min_heapify(arr,maxim);
}

void Build_heap(vector<int> &arr){
	int len = arr.size(),i;
	for(i=len/2-1;i>=0;i--){
		min_heapify(arr,i);
	}
}

vector<int> answer;

void heap_sort(vector<int> &arr){
	int len = arr.size();
	while(len != 0){
		answer.push_back(arr[0]);
		arr[0] = arr[len-1];
		arr.erase(arr.begin()+len-1);
		min_heapify(arr,0);
		len = arr.size();
	}
}

int main(){
	vector<int> arr({4,2,5,1,6,3,7});
	Build_heap(arr);
	heap_sort(arr);
	int len = answer.size();
	for(int i=0;i <len;i++)
		cout<<answer[i];
}
