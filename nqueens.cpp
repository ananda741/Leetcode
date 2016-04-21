#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

int x[100];
vector<vector<string> > result;

bool place(int k, int i){
	for(int j=1;j<k;j++){
		if(x[j] == i || (abs(k-j) == abs(i-x[j])))
			return false;
	}
	return true;
}

void Nqueens(int k,int n,vector<string> answer){
	for(int j=1;j<=n;j++){
		if(place(k,j)){
			x[k] = j;
			answer[k-1][j-1] = 'Q';
			if(k == n)
				result.push_back(answer);
			else
				Nqueens(k+1,n,answer);
			answer[k-1][j-1] = '.';
		}
	}
}

vector<vector<string> > solveQueens(int n){
	string out;
	vector<string> answer;
	for(int i=0;i<n;i++)
		out.push_back('.');
	for(int i =0;i<n;i++)
		answer.push_back(out);

	Nqueens(1,n,answer);

	return result;
}

int main(){
	int n;
	cout<<"Enter the size of the chess\n";
	cin>>n;
	
	result = solveQueens(n);

	int len = result.size();

	for(int i = 0;i<len;i++){
		vector<string> laser= result[i];

		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				cout<<laser[j][k];
			}
			cout<<endl;
		}
		cout<<endl;
	}
}
