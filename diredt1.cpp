#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	long long N,M,T;
	cin>>T;
	while(T--){
		cin>>N>>M;
		int flag = 0;
		long long arr[M],i;
		for(i=0;i<M;i++){
			cin>>arr[i];
		}
		
		sort(arr,arr+M);
		
		for(i=0;i<M-2;i++){
			if(arr[i]+1 == arr[i+1] && arr[i+1] + 1 == arr[i+2])
				flag = 1;
		}

		if(flag == 1) cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
}
