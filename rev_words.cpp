#include<iostream>
#include<string>
using namespace std;

    void reverse(string &s,int start,int end){
        int i,j;
        for(i=start,j = end;i<j;i++,j--){
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }

    void reverseWords(string &s) {
        int len = s.length(),i,flag = 0,j,p;
        if(len == 0)
            return;
        while(s[0] == ' ')
            s.erase(s.begin());
        if(s.length() == 0)
            return;
        while(s[s.length()-1] == ' ')
            s.erase(s.begin()+s.length()-1);
            
        if(s.length() == 0)return;
            
        for(i=0;i<s.length();){
		if(s[i] == ' '){
			if(flag == 0)flag = 1,i++;
			else s.erase(s.begin()+i);
		}
		else flag = 0,i++;
        }
        cout<<s<<endl;
        flag = 0;
        
        for(i=0;i<s.length();i++){
            if(flag == 0){
                j=i;
                flag = 1;
            }
            if(s[i] == ' '){
                reverse(s,j,i-1);
                flag = 0;
            }
        }
        
        reverse(s,j,i-1);
        reverse(s,0,s.length()-1);
    }


int main(){
	string s = "a     b";
	reverseWords(s);
	cout<<s<<endl;
}
