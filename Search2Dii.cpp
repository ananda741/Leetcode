#include<iostream>
#include<vector>
using namespace std;


    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int m = matrix.size(),n = matrix[0].size(),i,j,a,b;
        if(matrix[0][0] >target || matrix[m-1][n-1] < target)
            return false;
            
        for(a=0,b=0;a<m && b<n;a++,b++){
            i = m-1;
            j = n-1;
            
            
            if(matrix[a][j] >=target){
                for(j = n-1;j>=0;j--)
                    if(matrix[a][j] == target){
			cout<<matrix[a][j]<<" ";
                        return true;}
            }
            
            if(matrix[i][b]>=target){
                for(i = m-1;i>=0;i--)
                    if(matrix[i][b] == target)
                        return true;
                        
                return false;
            }
            
        }
        
        return false;
    }


int main(){
	vector<int> maser;
	vector<vector<int> > laser;
	maser.push_back(1);
	maser.push_back(3);
	maser.push_back(5);

	laser.push_back(maser);

	if(searchMatrix(laser,3))
		cout<<"true\n";
	
}
