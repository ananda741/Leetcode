#include<iostream>
#include<vector>
using namespace std;

    void gameOfLife(vector<vector<int> >& board) {
        int row = board.size(),col = board[0].size();
        int i,j,count = 0;
        if(row == 0) return;
        
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                if(i == 0 && j == 0){
                    if(i+1 < row && board[i+1][j])
                        count++;
                    if(j+1 < col && board[i][j+1])
                        count++;
                    if(i+1 < row && j+1 < col && board[i+1][j+1])
                        count++;
                }
                
                else if(i == 0 && j == col-1){
                    count = 0;
                    if(j-1>=0 && board[i][j-1])
                        count++;
                    if(i+1 < row && board[i+1][j])
                        count++;
                    if(j-1 >=0 && i+1 < row && board[i+1][j-1])
                        count++;
                }
                
                else if(i == row-1 && j == 0){
                    count = 0;
                    if(i-1 >= 0 && board[i-1][j]) count++;
                    if(j+1 < col && board[i][j+1]) count++;
                    if(i-1 >= 0 && j+1 < col && board[i-1][j+1]) count++;
                }
                
                else if(i == row-1 && j == col-1){
                    count=0;
                    if(i-1 >= 0 && board[i-1][j]) count++;
                    if(j-1 >= 0 && board[i][j-1]) count++;
                    if(i-1 >= 0 && j-1 >=0 && board[i-1][j-1]) count++;
                }
                
                else if(i == 0){
                    count = 0;
                    if(board[i][j-1]) count++;
                    if(board[i][j+1]) count++;
                    if( i+1 < row && board[i+1][j-1]) count++;
                    if(i+1 < row && board[i+1][j]) count++;
                    if(i+1 < row && board[i+1][j+1]) count++;
                }
                
                else if(i == row-1){
                    count = 0;
                    if(board[i][j-1]) count++;
                    if(board[i][j+1]) count++;
                    if(i-1 >= 0 && board[i-1][j-1]) count++;
                    if(i-1 >= 0 && board[i-1][j]) count++;
                    if(i-1 >= 0 && board[i-1][j+1]) count++;                    
                }
                
                else if(j == 0){
                    count = 0;
                    if(board[i-1][j]) count++;
                    if(board[i+1][j]) count++;
                    if(j+1 < col && board[i-1][j+1]) count++;
                    if(j+1 < col && board[i][j+1]) count++;
                    if(j+1 < col && board[i+1][j+1]) count++;
                }
                
                else if(j == col-1){
                    count = 0;
                    if(board[i-1][j]) count++;
                    if(board[i+1][j]) count++;
                    if(j-1 >= 0 && board[i-1][j-1]) count++;
                    if(j-1 >= 0 && board[i][j-1]) count++;
                    if(j-1 >= 0 && board[i+1][j-1]) count++;                   
                }
                
                else{
                    count = 0;
			cout<<"In else box i = "<<i<<" j = "<<j<<"\n";
                    if(board[i-1][j-1]) count++;
                    if(board[i-1][j]) count++;
                    if(board[i-1][j+1]) count++;
                    if(board[i][j-1]) count++;
                    if(board[i][j+1]) count++;
                    if(board[i+1][j-1]) count++;
                    if(board[i+1][j]) count++;
                    if(board[i+1][j+1]) count++;
                }
                
		cout<<count<<" i = "<<i<<" j = "<<j<<endl;
                 if(board[i][j]){
                        if(count < 2) board[i][j] = 0;
                        else if(count == 2 || count == 3) board[i][j] = 1;
                        else board[i][j] = 0;
                    }
                else
                    if(count == 3) board[i][j] = 1;
            }
        }
    }

int main(){
	vector<vector<int> > board;
	int i,j,val;
	vector<int> laser;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			cin>>val;
			laser.push_back(val);	
		}
		board.push_back(laser);
		laser.clear();
	}
	int row = board.size(), col = board[0].size();

	gameOfLife(board);
	cout<<endl;
	
	for(i=0;i<row;i++){
		for(j=0;j<col;j++)
			cout<<board[i][j]<<" ";
		cout<<endl;
	}
}
