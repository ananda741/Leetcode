#include<iostream>
#include<vector>
using namespace std;

    vector<string> answer;

    vector<string> str({"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"});
    
    void letter_phone(string digits,string out,int i){
        int len = digits.length(),j;
        char ch = digits[i];
        int val = int(ch) - 48;
        val-=2;
        for(j=0;j<str[val].length();j++){
            out.push_back(str[val][j]);
             if(i<len-1) letter_phone(digits,out,i+1);
             if(i == len-1) answer.push_back(out);
             out.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        int len = digits.length();
        if(len == 0) return answer;
        string out = "";
        letter_phone(digits,out,0);
        return answer;
    }

int main(){
	string digits = "4";
	answer = letterCombinations(digits);
	int len = answer.size();
	int i;
	for(i=0;i<len;i++){
		cout<<answer[i];
		cout<<endl;
	}
//	cout<<len<<endl;
}
