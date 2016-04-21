#include<iostream>
#include<string>
using namespace std;


bool compare(string text,string pattern,int *temp_arr){
	int text_len = text.length();
	int pat_len = pattern.length();
	
	int i,j = 0;
	for(i=0;j<pat_len && i < text_len;){
		if(text[i] == pattern[j])
			i+=1,j+=1;
		else{
			if(j != 0){
				j = temp_arr[j-1];
			}
			else
				i+=1;
		}
	}

	if(j == pat_len){
		cout<<"At pos : "<<i-pat_len-1<<endl;
		return true;
	}

	return false;
}


bool kmp(string text,string pattern){
	int text_len = text.length();
	int pat_len = pattern.length();
	int temp_arr[pat_len];
	temp_arr[0] = 0;

	int i,j = 0;
	
	for(i = 1;i < pat_len;){
		if(pattern[i] == pattern[j]){
			temp_arr[i] = j+1;
			j+=1,i+=1;
		}
		else{
			while(j!=0 && pattern[i] != pattern[j]){
				j = temp_arr[j-1];
			}
			if(pattern[i] == pattern[j]){
				temp_arr[i] = j+1;
				j+=1,i+=1;
			}
			else if(j == 0){
				temp_arr[i] = 0;
				i+=1;
			}			
		}
	}
	/*
	for(i=0;i<pat_len;i++)
		cout<<temp_arr[i]<<" ";
	cout<<endl;*/
	
	return compare(text,pattern,temp_arr);
}

int main(){
	string text,pattern;
	cout<<"Enter the text string : ";
	getline(cin,text);
	cout<<"\nEnter the pattern string : ";
	getline(cin,pattern);

	cout<<kmp(text,pattern);
}
