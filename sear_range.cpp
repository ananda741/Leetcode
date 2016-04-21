#include<iostream>
#include<vector>
using namespace std;


    int search(vector<int>& a,int target,int low,int high,bool b)
    {
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(target==a[mid])
            {
                
                if(b==false)
                    {
                        
                        if(mid==0||(a[mid]!=a[mid-1]))
                        {
                            cout<<"mid"<<mid;
                        return mid;
                        
                        }
                        else
                        high=mid-1;
                    }
                    
                if(b==true)
                    {
                        
                        if(mid==(a.size()-1)||a[mid]!=a[mid+1])
                        return mid;
                        
                        else
                        low=mid+1;
                    }
                
                
            }
            
            
            if(target<a[mid])
            {
                
                high=mid-1;
                
            }
            else
            {
                low=mid+1;
                
            }
            
        }
        
        return -1;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        
     vector<int> res(2,0);
     
     res[0]=search(nums,target,0,nums.size()-1,false);
  
     res[1]=search(nums,target,0,nums.size()-1,true);
     

        
        return res;
    }


int main(){
	vector<int> nums;
	nums.push_back(1);
	int target = 0;
	
	nums = searchRange(nums,target); 	
	
}
