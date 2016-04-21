#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

void largestnum(vector<int>& A){

    int arr[10]={0},i,len,rem,k=0;
    char s[50];
    len = A.size();
    for(i=0;i<len;i++){
        while(A[i]>0){
            rem = A[i]%10;
            arr[rem]++;
            A[i]/=10;
        }
    }

    for(i = 0;i<10;i++)
	cout<<arr[i]<<" ";

	cout<<endl;
    
    for(i = 9;i>=0;i++){
        while(arr[i]!=0){
            s[k++] = i - 48;
        }
    }

	s[k] = '\0';
    
	for(i = 0;i<k;i++){
		cout<<s[i];
	cout<<endl;
	}  

}

int main(){
	vector<int> A;
	A.push_back(3);
	A.push_back(30);
	A.push_back(34);
	A.push_back(5);
	A.push_back(9);

	largestnum(A);
}
