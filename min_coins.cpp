#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int total_denominations(vector<int> &coins,int total){
	int len = coins.size();
	vector<vector<int> > Matrix(len,vector<int>(total+1,0));

	for(int i = 0;i<len;i++)
		Matrix[i][0] = 1;

	for(int i = 0;i<len;i++){
		for(int j = 1;j<total+1;j++){
			if(i == 0)
				Matrix[i][j] = 1;
			else if(j >= coins[i])
				Matrix[i][j] = Matrix[i-1][j] + Matrix[i][j-coins[i]];
			else 
				Matrix[i][j] = Matrix[i-1][j];
		}
	}
	
	for(int i = 0;i<len;i++){
		for(int j=0;j<total+1;j++){
			cout<<Matrix[i][j]<<" ";
		}	
		cout<<endl;
	}
	
	return Matrix[len-1][total];
}

int main(){
	vector<int> coins({1,2,3});
	int total;
	cout<<"Enter the total amount money : ";
	cin>>total;
	cout<<endl;
	cout<<total_denominations(coins,total);
	cout<<endl;
}
