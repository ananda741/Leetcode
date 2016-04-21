#include<iostream>
#include<vector>
using namespace std;


int searchInsert(vector<int>& nums, int target) {
	int start = 0;
	int end = nums.size()-1;
	int mid;

	while(start<=end){
	mid = (start+end)/2;
	cout<<"MID--"<<mid<<endl;
	if(nums[mid] == target)
		return mid;
	else if(nums[mid]<target){
		start = mid+1;
	}
	else
		end = mid-1;
	}

	
	if(nums[mid]>target)
		return mid;
	else
		return mid+1;
}

int main(){
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);

	cout<<searchInsert(nums,0)<<endl;
}
