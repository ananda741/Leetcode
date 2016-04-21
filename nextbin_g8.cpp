#include<iostream>
using namespace std;

int next(int x){
	x = x+1;
	int mask = 3;
	int pos = 2;
	while(mask <=x){
		if((mask & x) == mask){
			x>>=pos;
			x+=1;
			x<<=pos;
		}
		mask<<=1;
		pos+=1;
	}
	return x;
}


int main(){
	cout<<next(8);
}
