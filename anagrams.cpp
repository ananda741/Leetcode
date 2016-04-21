#include<iostream>
#include<vector>
#include<map>
using namespace std;


vector<vector<int> > anagrams(vector<string> &strs) {
            map<string,pair<long long,long long> > laser;
        vector<vector<int> > result;
        long long i,len = strs.size();
        long long sum,mul,j;
        for(i = 0;i<len;i++){
            sum = 0,mul = 1;
            for(j = 0;j<strs[i].size();j++){
                sum = sum + (long long)strs[i][j];
                mul = mul * (long long)strs[i][j];
            }
            pair<long long,long long> key = make_pair(sum,mul);
                laser[strs[i]] = key;
          
        }
        
        vector<int> maser;
        int flag;
        
        for(i=0;i<len-1;i++){
            flag = 0;
            for(j = i+1;j<len;j++){
                if(laser[strs[i]] == laser[strs[j]]){
                    if(flag == 0){
                        maser.push_back(i+1);
                        flag = 1;
                    }
                    maser.push_back(j+1);
                }
            }
            result.push_back(maser);
            maser.clear();
        }
        return result;
}


int main(){
	vector<string> s;
	vector<vector<int> > laser;
	s.push_back("cat");  
	s.push_back("dog");
	s.push_back("god");
	s.push_back("tca");
	//s.push_back("may");
	//s.push_back("ill");
	//s.push_back("buy");
	//s.push_back("bar");
	//s.push_back("max");
	//s.push_back("doc");

	laser = anagrams(s);
	int i ,len = laser.size(),j;
	for(i = 0;i<len;i++){
		for(j = 0;j<laser[i].size();j++){
			cout<<laser[i][j];
		}
	cout<<endl;
	}
}
