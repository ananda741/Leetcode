#include<iostream>
#include<math.h>
using namespace std;

bool isPower(int A){
    if(A<=1)
        return true;
    if(A==2)
        return false;
    int i,a = sqrt(A);
    int j;
    long long var;
//    cout<<a<<" "<<endl; 
    for(i=a;i>=2;i--){
        j = i; 
	var = 1;
        while(var<A)
            var*=j;
	cout<<var<<" "<<endl; 
        if(A == var)
            return true;
    }
    return false;
}

int main(){
	cout<<isPower(536870912);
}
