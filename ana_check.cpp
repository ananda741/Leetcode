#include<iostream>
#include<string>
#include<cstdlib>
#include<ctype.h>
using namespace std;

int main(){
	string main,sub;	
	cout<<"Main string \n";
	cin>>main;
	cout<<"Substring\n";
	cin>>sub;
	long long sub_sum = 0,sub_mul = 1;
	long long main_sum = 0,main_mul = 1;
	long long i,sub_len = sub.length(),main_len = main.length();
	for(i=0;i<sub_len;i++){
		sub[i] = tolower(sub[i]);
		main[i] = tolower(main[i]);
		sub_sum+=int(sub[i]);
		sub_mul*=int(sub[i]);
		main_sum+=int(main[i]);
		main_mul*=int(main[i]);
	}
	if(sub_len == main_len){
		if(sub_sum == main_sum && sub_mul == main_mul)
			cout<<1;
		else
			cout<<0;
		exit(0);
	}
	else{
		for(i=sub_len;i<main_len;i++){
			main[i] = tolower(main[i]);
			main_sum+=int(main[i]);
			main_mul*=int(main[i]);
			main_sum-=int(main[i-sub_len]);
			main_mul/=int(main[i-sub_len]);
			cout<<main_sum<<" "<<main_mul<<" "<<sub_sum<<" "<<sub_mul<<endl;
			if(sub_sum == main_sum && main_mul == sub_mul ){
				cout<<1;
				exit(0);
			}
		}
	}
	cout<<0;
}
