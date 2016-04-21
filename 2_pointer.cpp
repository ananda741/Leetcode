#include<iostream>
using namespace std;

int numRange(int *A,int n,int B,int C){
	int k=0,i,j,sum;
	sum = A[0];
	for(i = 1,j=1;i<n;){
		if(sum>=B && sum<=C){
			sum+=A[j];
			k++;
			j++;
		}
		else if(sum<B){
			sum+=A[j];
			j++;
		}
		else{
			sum = A[i];
			i++;
			j=i;
		}
	
	}

	return k;
}

int main(){

	int A[]={80, 97, 78, 45, 23, 38, 38, 93, 83, 16, 91, 69, 18, 82, 60, 50, 61, 70, 15, 6, 52, 90};
	int size,k,B,C;
	B=99,C=269;
	size = sizeof(A)/sizeof(A[0]);

	k = numRange(A,size,B,C);

	cout<<k;
}
