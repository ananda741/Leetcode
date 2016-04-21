#include<iostream>
#include<algorithm>
using namespace std;

struct chain{
	int start;
	int end;
};

int formula(chain a,chain b){
	return (a.start < b.start)?1:0;
}

int LIS(chain *arr,int len){
	if(len <= 1) return len;
	chain *table = (chain *)malloc(sizeof(chain)*len);
	int size = 1,i;

	table[0] = arr[0];
	
	for(i=1;i<len;i++){
		if(table[size-1].end < arr[i].start)
			table[size++] = arr[i];
		else if(table[size-1].end > arr[i].end)
			table[size-1] = arr[i];
	}
	return size;
}

int main(){
	chain arr[4] = {{5,24},{15,25},{27,40},{50,60}};
	sort(arr,arr+4,formula);
	cout<<LIS(arr,4)<<endl;
}
