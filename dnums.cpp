#include<iostream>
#include<map>
#include<vector>
using namespace std;

vector<int> dNums(vector<int> &arr, int k) {
    int i,len = arr.size();
    map<int,int> hashmap;
    vector<int> answer;
    
    for(i=0;i<len;i++){
	if(hashmap.find(arr[i]) == hashmap.end())
		hashmap[arr[i]] = 1;
        else 
		hashmap[arr[i]]++;
        if(i >= k-1){
            answer.push_back(hashmap.size());	    
            hashmap[arr[i-k+1]]--;
	    if(hashmap[arr[i-k+1]] == 0) 
		hashmap.erase(arr[i-k+1]);
        }
    }
    
    return answer;
}

int main(){
	vector<int> arr({1,2,1,3,4,3});
	vector<int> answer = dNums(arr,3);
	int len = answer.size();
	for(int i=0;i<len;i++)
		cout<<answer[i]<<" ";
}
