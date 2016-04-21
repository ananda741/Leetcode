#include<iostream>
#include<string>
using namespace std;

int main1[256] = {0},sub1[256] = {0};

int compare(string main,string sub){
	int i;
	for(i=0;i<255;i++){
		if(main1[i] != sub1[i])
			return 0;
	}
	return 1;
}

int substring_check(string main,string sub){
	int i,sub_len = sub.length() , main_len = main.length();
	for(i=0;i<sub_len;i++){
		main1[main[i]]++;
		sub1[sub[i]]++;
	}
	if(sub_len == main_len){
		if(compare(main,sub))
			return 1;
		else 
			return 0;			
	}

	for(i = sub_len;i<main_len;i++){
		main1[main[i]]++;
		main1[main[i-sub_len]]--;
		if(compare(main,sub))
			return 1;
	}
	return 0;
}

int main(){
	string main,sub;
	cout<<"Main string : ";
	cin>>main;
	cout<<"Sub string : ";
	cin>>sub;
	cout<<substring_check(main,sub);	
}
