#include<iostream>
#include<stack>
using namespace std;

string simplifyPath(string path) {
        stack<string > laser,maser;
        int i,len = path.length();
        
        string s;
        
        for(i = 0;i<len;i++){
            if(path[i]!='/')
                s+=path[i];
            else{
                if(s.length()>2)
                    laser.push(s);
                else{
                    if(s.length() == 1 && s[0] == '.');
                    else if(s.length() == 2 && s[0] == '.' && s[1] == '.'){
                        if(!laser.empty())
                            laser.pop();
                    }
                    else if(s.length()>0)
                        laser.push(s);
                }
                s.clear();
            }
        }
        
	if(s.length()>2)
		laser.push(s);
	
	  else{
                if(s.length() == 1 && s[0] == '.');
                 else if(s.length() == 2 && s[0] == '.' && s[1] == '.'){
                     if(!laser.empty())
                         laser.pop();
                 }
                 else if(s.length()>0)
                     laser.push(s);
          }
	
	
	s.clear();
	if(laser.empty())
		return s+='/';

        while(!laser.empty()){
            string k = laser.top();
            cout<<k<<"----"<<endl;
            laser.pop();
            maser.push(k);
        }
        
        s.clear();
        
        while(!maser.empty()){
            s+='/';
            s+=maser.top();
            maser.pop();
        }
        
        return s;
    }


int main(){
	cout<<simplifyPath("/...")<<endl;
}
