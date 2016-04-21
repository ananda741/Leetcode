#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

 map<vector<int>,int> flag;

    void generate(vector<int> &nums,int step,vector<vector<int> >& res,vector<int> &out){
        int i;
        for(i=step;i<nums.size();i++){
        out.push_back(nums[i]);
        if(flag.find(out)==flag.end()){
                res.push_back(out);
                flag[out] = 1;
            }
        if(i<nums.size()-1)
            generate(nums,i+1,res,out);
        out.pop_back();
        }
    }

    vector<vector<int> > subsets(vector<int>& nums) {
        vector<int> out;
        vector<vector<int> > res;
        if(nums.size() == 0)
            return res;
        res.push_back(out);
        sort(nums.begin(),nums.end());    
        generate(nums,0,res,out);
	return res;
    }


int main(){
	vector<int> nums;
	nums.push_back(5);
	nums.push_back(4);
//	nums.push_back(3);

	vector<vector<int> > laser = subsets(nums);

	int i,j;
	for(i=0;i<laser.size();i++){
		for(j=0;j<laser[i].size();j++)
			cout<<laser[i][j]<<" ";
		cout<<endl;
	}

	cout<<endl;
}
