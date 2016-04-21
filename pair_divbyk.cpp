#include<iostream>
#include<vector>
#include<map>
using namespace std;

void PrintPairs(vector<int> &arr,int k){
	int i,len = arr.size();
	vector<int> mod(len,0);

	for(i=0;i<len;i++)
		mod[i] = arr[i]%k;

	for(i=0;i<len;i++)
		cout<<mod[i]<<" ";
	cout<<endl;

	map<int,int> hashmap;

	for(i=0;i<len;i++){
		if(hashmap.find(k-mod[i]) != hashmap.end()){
			cout<<"Pair : "<<arr[i]<<" "<<arr[hashmap[k-mod[i]]]<<endl;
		}
		if(hashmap.find(mod[i]) == hashmap.end())
			hashmap[mod[i]] = i;
	}	
}

int main(){
	vector<int> arr({3,4,1,6,11,7,9,8});
	PrintPairs(arr,7);
	
}
