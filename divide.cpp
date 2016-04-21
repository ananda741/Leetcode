#include<iostream>
#include<cstdlib>
using namespace std;

int divide(int dividend, int divisor) {
	long long nu,de;
	nu = abs(dividend);
	de = abs(divisor);
//	cout<<"dividend = "<<nu<<" divisor = "<<abs(de)<<endl;
	nu = abs(nu);
	de = abs(de);
	long long temp =1 ;
	long long quotient = 0;
	while(de<=nu){
	    temp<<=1;
	    de<<=1;
	   // cout<<"temp = "<<temp<<endl<<"divisor = "<<de<<endl;
	}

	while(temp>1){
	    temp>>=1;
	    de>>=1;
	    if(nu>=de){
		nu-=de;
		quotient+=temp;
	    }
	}
	if((dividend<0 && divisor<0)||(dividend>0 && divisor>0))
		return quotient;
	else
		return -quotient;
}

int main(){
	cout<<divide(-2147483648,-10000000 );
}
