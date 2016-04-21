#include<iostream>
#include<map>
#include<vector>
using namespace std;


    void setZeroes(vector<vector<int> >& matrix) {
        map<int,int> row,col;
        int m = matrix.size(), n=matrix[0].size();
        int i,j;
        if(m == 0)
            return;
            
        if(m == 1 && n == 1)    
            return;
        
        for(i = 0;i<m;i++){
            for(j = 0;j<n;j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        
        for(i = 0;i<m;i++){
            if(row.find(i)!=row.end()){
                for(j=0;j<n;j++)
                    matrix[i][j] = 0;
            }
        }
        
         for(j = 0;j<n;j++){
            if(col.find(j)!=col.end()){
                for(i=0;i<m;i++)
                    matrix[i][j] = 0;
            }
        }
    }




int main(){
	vector<vector<int> > laser;
	vector<int> maser;
	
	maser.push_back(0);
	maser.push_back(1);
	laser.push_back(maser);

	setZeroes(laser);

	int i,j,m = laser.size(),n = laser[0].size();

	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cout<<laser[i][j]<<" ";
		}
		cout<<"\n";
	}
}
