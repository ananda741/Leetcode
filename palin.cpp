#include<iostream>
#include<cstdlib>
using namespace std;

int  Palin(int n){
    long long s=0,rem,t;
    long long A;
	A = abs(n);
    while(A>0){
        rem = A%10;
        s = s*10+rem;
	cout<<s<<"---"<<endl;
        A = A/10;
    }
	cout<<s<<endl;
	t = s;
	if(n<0)
		return -t;

   return (long long)t;
}

int main(){
	cout<<Palin(-1146467285);
}
