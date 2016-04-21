#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;


    bool isPalindrome(string s) {
        int i,j,len;
        for(i = 0;i<s.length();){
            if(s[i]>=65 && s[i]<=90){
                s[i] = tolower(s[i]);
		i++;
		}
                
            else if((s[i]>=48 && s[i]<=57) || (s[i]>=97 && s[i]<=122))
		i++;
            
            else
                s.erase(s.begin()+i);
        }
	cout<<s<<endl;
        len = s.length();
        for(i=0,j=len-1;i<=j;i++,j--){
            if(s[i]!=s[j])
                return false;
        }
        
        return true;
    }


int main(){
	string s = "aA";
	cout<<isPalindrome(s);
}
