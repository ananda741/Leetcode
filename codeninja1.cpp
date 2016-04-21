#include<iostream>
#include<map>
#include<vector>
#include<limits.h>
using namespace std;

vector<int> getMode(vector<int> &A, vector<vector<int> > &B) {
    map<int,int> hashmap;
    vector<int> answer;
    int i,len = A.size(),up_len = B.size();
    int mode = 0,maxim = INT_MIN;
    
    for(i=0;i<len;i++){
        if(hashmap.find(A[i]) == hashmap.end())
            hashmap[A[i]] = 1;
        else
            hashmap[A[i]]++;
        if(hashmap[A[i]] > mode){
            maxim = hashmap[A[i]];
            mode = A[i];
        }
    }
    
    for(i=0;i<up_len;i++){
        int a = B[i][0];
        int b = B[i][1];
        
        if(A[a-1] == mode)
            maxim--;
        hashmap[A[a-1]]--;
        A[a-1] = b;
        if(hashmap.find(A[a-1]) == hashmap.end())
            hashmap[A[a-1]] = 1;
        else
            hashmap[A[a-1]]++;
        
        if(hashmap[A[a-1]] > maxim){
            mode = A[a-1];
            answer.push_back(mode);
            maxim = hashmap[A[a-1]];
        }
        else if(hashmap[A[a-1]] == maxim){
            if(mode > A[a-1])
                mode = A[a-1];
            answer.push_back(mode);
        }
        else{
            //int maxi = INT_MIN;
            map<int,int>:: iterator it;
            for(it = hashmap.begin();it != hashmap.end();it++){
                if(it->second >= maxim){
                    maxim = it->second;
                    if(it->first < mode)
                        mode = it->first;
                }
            }
            answer.push_back(mode);
        }
    }
    
    return answer;
}

int main(){
	vector<int> A({2,2,2,3,3});
	vector<vector<int> > B({1,3},{5,4},{2,4});
	A = getMode(A,B);
	int i,len = A.size();
	for(i=0;i<len;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
}
