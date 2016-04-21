#include<iostream>
#include<vector>
using namespace std;

vector<int> repeatedNumber( vector<int> &arr) {
	long long k,j,sum=0,mul=0,sumn,muln,n=arr.size();
	sumn = (n*(n+1))/2;
	muln = (n*(n+1)*(2*n+1))/6;

	long long i;
	for(i=0;i<n;i++){
		sum+=arr[i];
		mul+=(arr[i]*arr[i]);		
	}

	long long a,b;
	a = sum - sumn;
	b = mul - muln;

	k = (b+a*a)/(2*a);
	j = k-a;
	vector<int> out;
	out.push_back(k);
	out.push_back(j);
	return out;
}

int main(){
	 vector<int> laser;
	laser.push_back(3);
	laser.push_back(1);
	laser.push_back(2);
	laser.push_back(5);
	laser.push_back(3);
	vector<int> out;
	int i;
	 out = repeatedNumber(laser);

	for(i=0;i<out.size();i++)
		cout<<out[i]<<" ";
	cout<<endl;
	
}
