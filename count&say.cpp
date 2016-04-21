#include<iostream>
#include<string>
using namespace std;

    string countAndSay(int n) {
        string str = "";
        if(n == 0) return str;
        
        if(n == 1) return "1";
        
        string oldstr = "1";
        int count,var=1;
        while(var<n){
            string newstr;
            int len = oldstr.length();
            char last = oldstr[0];
            count = 1;
            for(int i=1;i<len;i++){
                if(str[i] == last)
                    count++;
                else{
                    newstr.push_back(count+'0');
                    newstr.push_back(last);
                    count = 1;
                    last = str[i];
                }
            }
            newstr.push_back(count+'0');
            newstr.push_back(last);
            oldstr = newstr;
            var++;
        }
        
        return oldstr;
    }

int main(){
	cout<<countAndSay(3);
}

