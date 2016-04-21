#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

    vector<int> plusOne(vector<int>& digits) {
        if(digits[digits.size()-1]!=9){
            digits[digits.size()-1]+=1;
	    while(digits[0] == 0){
		digits.erase(digits.begin());
	}
            return digits;
        }
	if(digits.size() == 1 && digits[0] == 9){
		digits.clear();
		digits.push_back(0);
		digits.insert(digits.begin(),1,1);
		return digits;
	}
        else{
            int carry = 1,i;
            i = digits.size()-1;
            while(carry){
                digits[i--]=0;
                if(digits[i] == 9 && i == 0){
                    digits.insert(digits.begin(),1,1);
                    carry = 0;
		    digits[i+1] = 0;
                }
                else if(digits[i] == 9){
                    carry = 1;
                }
                else{
                    digits[i]+=1;
                    carry = 0;
                }
            }
        }
	while(digits[0] == 0){
		digits.erase(digits.begin());
	}
	
        return digits;
    }

int main(){
	vector<int> digits;
	int i;
	
	digits.push_back(0);
	digits.push_back(3);
	digits.push_back(7);
	digits.push_back(6);
	digits.push_back(4);
	digits.push_back(0);
	digits.push_back(5);
	digits.push_back(5);
	digits.push_back(5);/*
	digits.push_back(9);*/
	digits = plusOne(digits);
	for(i=0;i<digits.size();i++)
		cout<<digits[i];
	cout<<endl;
	return 0;
}
