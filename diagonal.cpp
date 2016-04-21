#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > diagonal(vector<vector<int> > &A) {
    int a,b,i,j;
    vector<int> out;
    vector<vector<int> > res;
    
    int n = A.size();
    
    for(a=0,b=0;a<n;){
        i = a,j = b;
        while(i<=b && j>=a){
            out.push_back(A[i][j]);
            i++;
            j--;
        }
        res.push_back(out);
        out.clear();
        if(b == n-1)
            a++;
        else
            b++;
    }
    
    return res;
}


int main(){
	vector<int> out;
	vector<vector<int> > res;
	out.push_back(1),out.push_back(2),out.push_back(3);
	res.push_back(out);
	out.push_back(4),out.push_back(5),out.push_back(6);
	res.push_back(out);
	out.push_back(7),out.push_back(8),out.push_back(9);
	res.push_back(out);
	
	res = diagonal(res);

	
}
