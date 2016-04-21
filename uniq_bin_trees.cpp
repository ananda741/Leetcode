#include<iostream>
using namespace std;

long long numTrees(int n) {
	long long arr[n],ans,j=0,denom=1,numer=1,k,flag,i;
	for(i=n+2;i<=2*n;i++){
		arr[j] = i;
		j++;	
	}
	for(i=2;i<=n;i++){
		for(k=0;k<j;k++){
			flag = 0;
			if(arr[k]%i==0){
				arr[k]/=i;
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			denom*=i;
	}

	for(k=0;k<j;k++)
		numer*=arr[k];

	ans = numer/denom;
	return (int)ans;
}

int main(){
	cout<<numTrees(19);
	cout<<endl;
}
