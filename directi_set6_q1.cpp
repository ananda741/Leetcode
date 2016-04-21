#include<iostream>
#include<string>
using namespace std;

bool isDigit(char ch){
	return (ch>='0' && ch<='9');
}

void findchar(string str,int pos){
	int i=0,cl=0,pl,val=0,len = str.length();
	while(cl<pos){
		pl = cl;
		if(!isDigit(str[i])){
			i++,cl++;
			val=0;
		}
		else{
			val = val*10+(str[i]-'0');
			if((i+1)<len && isDigit(str[i+1]));
			else{
				cl = cl*val;
				cout<<val<<endl;
			}
			i++;
		}
	}

	if(cl>pos){
		int temp = pos%pl;
		if(temp==0) temp=pl;
		findchar(str,temp);
	}

	if(cl == pos && !isDigit(str[i-1]))
		cout<<str[i-1]<<endl;
	else if(cl == pos && !isDigit(str[i-2]))
		cout<<str[i-2]<<endl;
}

int main(){
	findchar("ab2c13d2",66);
}
