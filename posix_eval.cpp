#include<iostream>
using namespace std;
#include<stack>
#include<vector>


    int func(int a,int b,char c){
        int k;
        switch(c){
            case '+': k = b+a;
                      break;
            case '-': k = a-b;
                      break;
            case '*': k = a*b;
                      break;
            case '/': k = a/b;
        }
        return k;
    }
    
    int strtoint(string s){
        int laser = 0,len = s.length(),i,flag = 0;
        for(i=0;i<len;i++){
	    if(s[i] == '-')
		flag = 1;
	    else
            	laser = laser*10 + int(s[i])-48;
	}
            
	if(flag == 1)
        	return -laser;
	else 
		return laser;
    }


    int evalRPN(vector<string>& tokens) {
        stack<int> laser;
        
        int i,len = tokens.size(),k;
        int a,b,c;
        
        for(i = 0;i<len;i++){
            if(tokens[i].length()>1){
                k = strtoint(tokens[i]);
		cout<<k<<endl;
                laser.push(k);
            }
            else if(tokens[i].length() == 1 && tokens[i][0]>='0'&& tokens[i][0]<='9'){
                k = strtoint(tokens[i]);
		cout<<k<<endl;
                laser.push(k);
            }
            else{
                b = laser.top();
                laser.pop();
                a = laser.top();
                laser.pop();
                laser.push(func(a,b,tokens[i][0]));
		cout<<"TOP ELEMENT "<<a<<tokens[i][0]<<b<<" "<<laser.top()<<endl;
            }
        }
        
        return laser.top();
    }


int main(){
	vector<string> tokens;
	tokens.push_back("-78");
	tokens.push_back("-33");
	tokens.push_back("196");
	tokens.push_back("+");
	tokens.push_back("-19");
	tokens.push_back("-");
	tokens.push_back("115");
	tokens.push_back("+");
	tokens.push_back("-");
	tokens.push_back("-99");
	tokens.push_back("/");
	tokens.push_back("-18");
	tokens.push_back("8");
	tokens.push_back("*");
	tokens.push_back("-86");
	tokens.push_back("-");
	tokens.push_back("-");
	tokens.push_back("16");
	tokens.push_back("/");

	tokens.push_back("26");
	tokens.push_back("-14");
	tokens.push_back("-");
	tokens.push_back("-");
	tokens.push_back("47");
	tokens.push_back("-");

	tokens.push_back("101");
	tokens.push_back("-");
	tokens.push_back("163");
	tokens.push_back("*");
	tokens.push_back("143");

	tokens.push_back("-");
	tokens.push_back("0");
	tokens.push_back("-");
	tokens.push_back("171");
	tokens.push_back("+");
	tokens.push_back("120");
	tokens.push_back("*");
	tokens.push_back("-60");

	tokens.push_back("+");
	tokens.push_back("156");
	tokens.push_back("/");
	tokens.push_back("173");
	tokens.push_back("/");

	tokens.push_back("-24");
	tokens.push_back("11");
	tokens.push_back("+");

	tokens.push_back("21");
	tokens.push_back("/");
	tokens.push_back("*");
	tokens.push_back("44");
	tokens.push_back("*");

	tokens.push_back("180");
	tokens.push_back("70");
	tokens.push_back("-40");
	tokens.push_back("-");
	tokens.push_back("*");
	tokens.push_back("86");
	tokens.push_back("132");

	tokens.push_back("-84");
	tokens.push_back("+");
	tokens.push_back("*");
	tokens.push_back("-");
	tokens.push_back("38");
	tokens.push_back("/");
	tokens.push_back("/");
	tokens.push_back("21");

	tokens.push_back("28");
	tokens.push_back("/");
	tokens.push_back("+");
	tokens.push_back("83");

	tokens.push_back("/");
	tokens.push_back("-31");
	tokens.push_back("156");
	tokens.push_back("-");
	tokens.push_back("+");
	tokens.push_back("28");
	tokens.push_back("/");
	tokens.push_back("95");
	tokens.push_back("-");
	tokens.push_back("120");
	tokens.push_back("+");

	tokens.push_back("8");

	tokens.push_back("*");
	tokens.push_back("90");
	tokens.push_back("-");
	tokens.push_back("-94");
	tokens.push_back("*");

	tokens.push_back("-73");
	tokens.push_back("/");
	tokens.push_back("-62");
	tokens.push_back("/");

	tokens.push_back("93");
	tokens.push_back("*");
	tokens.push_back("196");

	tokens.push_back("-");
	tokens.push_back("-59");
	tokens.push_back("+");
	tokens.push_back("187");
	tokens.push_back("-");
	tokens.push_back("143");

	tokens.push_back("/");
	tokens.push_back("-79");
	tokens.push_back("-89");
	tokens.push_back("+");
	tokens.push_back("-");

	cout<<evalRPN(tokens);
}
