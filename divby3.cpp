#include<iostream>
#include<cmath>
using namespace std;

    bool isPowerOfThree(int n) {
        if(n == 0) return false;
        double ans = log10(n)/log10(3);
	cout<<ans<<endl;
        return ceil(ans) == floor(ans);
    }

int main(){
	cout<<isPowerOfThree(240)<<endl;
}
