#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void swap(int *a,int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


 void max_heapify(vector<int> &arr,int laser){
       int l = 2*laser+1;
       int r = 2*laser+2;
       int len = arr.size();
       int maxim = laser;
       
       if(l<len && (arr[l]>arr[laser]))
            maxim = l;
       if(r<len && (arr[r]>arr[maxim]))
            maxim = r;
       if(maxim != laser){
           swap(&arr[maxim],&arr[laser]);
           max_heapify(arr,maxim);
       }     
    }

    void Build_maxheap(vector<int> &arr){
        int i,len = arr.size();
        for(i=0;i<len/2;i++){
            max_heapify(arr,i);    
        }
    }
    
    void extract(vector<int> &arr){
        int len = arr.size();
        if(len == 1)
            arr.erase(arr.begin());
            
        arr[0] = arr[len-1];
        arr.erase(arr.begin()+len-1);
        max_heapify(arr,0);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size(),i;
        if(len == 0)
            return 0;
        if(len == 1 && k == 1)
            return 1;
        Build_maxheap(nums);
	for(i=0;i<len;i++)
		cout<<nums[i]<<" ";
	cout<<endl;
	k = k-1;

	if(len == k)
		return nums[len-1];
        while(k--){
            extract(nums);
        }
        
        return nums[0];
    }



int main(){
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(4);
	cout<<findKthLargest(nums,2);
}
