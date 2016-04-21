#include<iostream>
#include<string>
using namespace std;

long long fact(long long n){
	long long fact = 1;
	if(n<=1) return 1;
	for(long long i=2;i<=n;i++)
	    fact*=i;
	return fact;
}

long long right_side(string str,int pos){
	long long count = 0,len = str.length();
	for(long long i =pos+1;i<len;i++)
		if(str[i] < str[pos])
			count++;
	return count;
}

long long find_rank(string str){
	long long rank = 1,len = str.length();
	long long var = fact(len),right_val;
	cout<<"var = "<<var<<endl;
	if(len == 0) return 0;
	if(len == 1) return 1; 
	for(long long i=0;i<len;i++){
		var/=len-i;
		right_val = right_side(str,i);
		if(right_val == 0) continue;
		cout<<right_val<<"*"<<len-i-1<<"!"<<" + ";
		rank = rank + right_val*var;
	}
	cout<<endl;
	return (rank)%1000003;
}

int main(){
	cout<<find_rank("AaBbCc")<<endl;
}
