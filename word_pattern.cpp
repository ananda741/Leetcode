#include<iostream>
#include<string>
#include<map>
using namespace std;

    bool wordPattern(string pattern, string str) {
        map<char,string> hashmap;
        string new_str;
        int i,j = 0 ,len = str.size();
        
        int pattern_len = pattern.length(),count = 0;
        for(i=0;i<len;i++)
            if(str[i] == ' ')
                count++;
                
        if( pattern_len != (count+1))
            return false;

	cout<<"count = "<<count+1<<" pattern length = "<<pattern_len<<endl;
                
        
        for(i=0;i<len;i++){
            if(str[i] == ' '){
                if(hashmap.find(pattern[j]) == hashmap.end()){
                    hashmap[pattern[j]] = new_str;
                }
                else{
                    if(hashmap[str[j]] != new_str)  
                        return false;
                }
                new_str.clear();
                j++;
            }
            else
                new_str.push_back(str[i]);
        }
        
        if(hashmap.find(pattern[j]) == hashmap.end())
            hashmap[pattern[j]] = new_str;
        else{
            //cout<<hashmap[str[j]]<<"  "<<new_str<<endl;
		if(hashmap[pattern[j]] != new_str)
                return false;
        }
	/*
	for(i=0;i<pattern_len;i++){
		cout<<"\n"<<hashmap[str[i]]<<endl;;
	}*/
        
        return true;
    }

int main(){
	string pattern = "abba";
	string str = "dog cat cat fish";

	cout<<wordPattern(pattern,str);
}
