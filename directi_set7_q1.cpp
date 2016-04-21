#include<iostream>
#include<string>
using namespace std;

bool lexo_compare(string s1,string s2){
	int len1 = s1.length(),len2 = s2.length();
	if(len1!=len2) return false;

	for(int i=0;i<len1;i++){
		if(s1[i] < s2[i])
			return true;
		else if(s1[i] > s2[i])
			return false;
	}
	return false;
}

string reverse(string str){
	int len = str.length();
	int i,j;
	for(i=0,j=len-1;i<j;i++,j--){
		char temp;
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	return str;
}

string ans;

void generate(string str,int start){
	int len = str.length();
	if(start>=len-1) return;

	for(int i=start;i<len;i++){
		generate(str,start+1);
		string res = "";
		if(start>0) res.append(str.substr(0,start));			
		if((i-start) >= 0) res.append(reverse(str.substr(start,i-start+1)));
		if((len-i-1) > 0) res.append(str.substr(i+1,len-i));
		
		cout<<res<<"\n";		

		if(lexo_compare(res,ans))
			ans = res;
 	}
}

int main(){
	string str;
	cin>>str;
	ans = str;
	generate(str,0);
	cout<<ans<<endl;
}
