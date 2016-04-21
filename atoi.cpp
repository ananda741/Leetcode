#include<iostream>
#include<string>
#include<limits.h>
using namespace std;

    int myAtoi(string str) {
        int len = str.length(),digits=0;
        int i=0,flag = 0,blag = 0,p_count=0,m_count = 0;
        for(;str[i]==' '||str[i] =='+'||str[i] == '-';i++){
            if(str[i] == '-') flag = 1,m_count++;
            else if(str[i] == '+') blag = 1,p_count++;
        }
        
        if(p_count>1) return 0;
        if(m_count>1) return 0;
        
        if((flag == 1 || blag == 1) && str[i-1] == ' ') return 0;
        
        if(flag == 1 && blag == 1) return 0;
        
        long long answer = 0;
        
        for(;str[i] >='0' && str[i] <= '9';i++){
            answer = answer*10 + int(str[i])-48;
	    digits++;
	    //cout<<answer<<endl;
        }
 
	if(digits >= 20) return INT_MAX;	

        if((answer > INT_MAX || answer < INT_MIN) && flag == 0) return INT_MAX;
        else if((answer >INT_MAX ||answer < INT_MIN) && flag == 1) return INT_MIN;
            
        return (flag == 1)? -answer:answer;
    }

int main(){
	cout<<myAtoi("9223372036854775807")<<"\n";
}
