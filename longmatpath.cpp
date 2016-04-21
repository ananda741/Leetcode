#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

    int max_len = 0,mini = INT_MAX;
  
    void maxlength(vector<vector<int> > &mat,int len,int i,int j){
        if(len>max_len) max_len = len;
        int l = mat.size(),b = mat[0].size();
        
        if(i>=l || j>=b) return;

//	cout<<l<<" "<<b<<endl;
        
        if((i+1)<l && mat[i+1][j] > mat[i][j]) 
            maxlength(mat,len+1,i+1,j);
            
        if((j+1)<b && mat[i][j+1] > mat[i][j])
            maxlength(mat,len+1,i,j+1);
            
        if((i-1)>=0 && mat[i-1][j] > mat[i][j])
            maxlength(mat,len+1,i-1,j);
            
        if((j-1)>=0 && mat[i][j-1] > mat[i][j])
            maxlength(mat,len+1,i,j-1);
    }

    int longestIncreasingPath(vector<vector<int> >& matrix) {
	int i,j,m = matrix.size(),n = matrix[0].size();

	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
		        maxlength(matrix,1,i,j);
		}
	}
        return max_len;
    }

int main(){
	vector<vector<int> > matrix {{9,9,4},{6,6,8},{2,1,1}};

	cout<<longestIncreasingPath(matrix);
}
