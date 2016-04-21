#include<iostream>
#include<vector>
using namespace std;

    bool increasingTriplet(vector<int>& nums) {
        int i,len = nums.size(),val=0;
        if(len < 3) return false;
        int table[3];
        table[0] = nums[0];
        
        for(i=1;i<len;i++){
            if(nums[i] < table[0])
                table[0] = nums[i];
            else if(nums[i] > table[val])
                table[++val] = nums[i];
            else if(table[val] > nums[i] && nums[i] > table[val-1])
                table[val] = nums[i];
                
            if(val == 2)
		return true;
        }
        
        return false;
    }

int main(){
	vector<int> nums = {1,2,1,2,1,2,1,2,1,2};
	cout<<increasingTriplet(nums)<<endl;
}
