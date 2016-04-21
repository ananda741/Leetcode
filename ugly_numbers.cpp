#include<iostream>
using namespace std;

   int nthUglyNumber(int n) {
        int *ugly = new int[n];
        int i2,i3,i5;
        i2 = i3 = i5 = 0;
        ugly[0] = 1;
        int next_ugly,mul_2,mul_3,mul_5;
        mul_2 = 2*ugly[i2],mul_3 = 3*ugly[i3],mul_5 = 5*ugly[i5]; 
        for(int i=1;i<n;i++){
            next_ugly = min(mul_2,min(mul_3,mul_5));
            if(next_ugly == mul_2){
                i2+=1;
                mul_2 = 2*ugly[i2];
            }
            if(next_ugly == mul_3){
                i3+=1;
                mul_3 = 3*ugly[i3];
            }
            if(next_ugly == mul_5){
                i5+=1;
                mul_5 = 5*ugly[i5];
            }
            ugly[i] = next_ugly;
        }
        
        return ugly[n-1];
    }

int main(){
	cout<<nthUglyNumber(4);
}
