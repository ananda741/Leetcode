#include<iostream>
#include<string>
#include<vector>
using namespace std;

void swap(char *a,char *b){
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

string reverse(string answer){
	int i,j,len = answer.length();
	for(i=0,j=len-1;j>i;i++,j--){
		swap(&answer[i],&answer[j]);
	}
	return answer;
}

string int2str(int data){
	string answer;
	while(data){
		int k = data%10;
		char val = (char)(k+48);
		data/=10;
		answer.push_back(val);
	}
	cout<<answer;
	return reverse(answer);
}

    vector<int> tree;
    
    void func(string data){
        int i,len = data.length();
        int val = 0,flag = 0;
        
        for(i=0;i<len;i++){
            if(data[i] == '.'){
		if(flag == 1) val*=-1;
                tree.push_back(val);
		val = 0;
		flag = 0;
            }
            else{
		if(data[i] == '-')
			flag = 1;
		else
                	val = val*10 + ((int)data[i] - 48);
            }
        }
    }

int main(){
	string laser;
	//cout<<char(1+48);
	cout<<"Enter a string\n";
	getline(cin,laser);
	int val = 15;
	string answer = int2str(val);
	func(laser);
	laser = laser + answer;
	cout<<endl<<laser<<endl;

	int i,len = tree.size();
	
	for(i=0;i<len;i++)
		cout<<tree[i]<<" ";
	cout<<endl;
}
