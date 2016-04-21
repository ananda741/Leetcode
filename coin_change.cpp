#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int min_coins(vector<int> &coins,int total){

	int len = coins.size();
	vector<vector<int> > Matrix(len,vector<int>(total+1,0));

	for(int i=0;i<len;i++){
		for(int j = 1;j<total+1;j++){
			if(i == 0){
				if(j%coins[i] == 0)
					Matrix[i][j] = j/coins[i];
				else
					Matrix[i][j] = j/coins[i]+1;
			}
			else if(j >= coins[i]){
				Matrix[i][j] = min(Matrix[i-1][j],Matrix[i][j-coins[i]]+1);
			}
			else
				Matrix[i][j] = Matrix[i-1][j];
		}
	}
	
	for(int i = 0;i<len;i++){
		for(int j = 0 ;j<total+1;j++){
			cout<<Matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	return Matrix[len-1][total];
	
}

int main(){
	vector<int> coins({2,8,6,5});
	sort(coins.begin(),coins.end());
	int total;
	cout<<"Enter the total sum of money : ";
	cin>>total;
	cout<<min_coins(coins,total)<<endl;
	
}
