#include<iostream>
using namespace std;

    void gameOfLife(int board[][7],int mat_m,int mat_n) {
        //int mat_m = board.size(),mat_n = board[0].size();
        
        if(mat_n == 0 && mat_m == 0) return;
        
        if(mat_n == 1){
            for(int i=0;i<mat_m;i++)
                board[i][0] = 0;
            return;
        }
        
        if(mat_m == 1){
            for(int i=0;i<mat_n;i++)
                board[0][i] =0;
            return;
        }
        
        int count;
        
        for(int i=0;i<mat_m;i++){
            for(int j=0;j<mat_n;j++){
                count = 0;
                if(i == 0 && j == 0){
                    if(board[i+1][j] == 1 || board[i+1][j] == 2) count++;
                    if(board[i+1][j+1] == 1 || board[i+1][j+1] == 2) count++;
                    if(board[i][j+1] == 1 || board[i][j+1] == 2) count++;
                }
                else if(i == 0 && j == mat_n-1){
                    if(board[i+1][j] == 1 || board[i+1][j] == 2) count++;
                    if(board[i+1][j-1] ==1 || board[i+1][j-1] == 2) count++;
                    if(board[i][j-1] == 1 || board[i][j-1] == 2) count++;
                }
                else if(i == mat_m-1 && j == 0 ){
                    if(board[i-1][j] == 1 || board[i-1][j] == 2) count++;
                    if(board[i-1][j+1] == 1 || board[i-1][j+1] == 2 ) count++;
                    if(board[i][j+1] == 1 || board[i][j+1] == 2) count++;
                }
                else if(i == mat_m-1 && j == mat_n-1 ){
                    if(board[i-1][j] == 1 || board[i-1][j] == 2) count++;
                    if(board[i-1][j-1] == 1 || board[i-1][j-1] == 2) count++;
                    if(board[i][j-1] == 1 || board[i][j-1] == 2) count++;
                }
                else if(i == 0){
                    if(board[i][j-1] == 1 || board[i][j-1] == 2) count++;
                    if(board[i+1][j-1] == 1 || board[i+1][j-1] == 2) count++;
                    if(board[i+1][j] == 1 || board[i+1][j] == 2) count++;
                    if(board[i+1][j+1] == 1 || board[i+1][j+1] == 2) count++;
                    if(board[i][j+1] == 1 || board[i][j+1] == 2) count++;
                }
                else if(j == 0){
                    if(board[i-1][j] == 1 || board[i-1][j] == 2) count++;
                    if(board[i-1][j+1] == 1 || board[i-1][j+1] == 2) count++;
                    if(board[i][j+1] == 1 || board[i][j+1] == 2) count++;
                    if(board[i+1][j+1] == 1 || board[i+1][j+1] == 2) count++;
                    if(board[i+1][j] == 1 || board[i+1][j] == 2) count++;
                }
                else if(i == mat_m-1){
                    if(board[i][j-1] == 1 || board[i][j-1] == 2) count++;
                    if(board[i-1][j-1] == 1 || board[i-1][j-1] == 2) count++;
                    if(board[i-1][j] == 1 || board[i-1][j] == 2) count++;
                    if(board[i-1][j+1] == 1 || board[i-1][j+1] == 2) count++;
                    if(board[i][j+1] == 1 || board[i][j+1] == 2) count++;
                }
                else if(j == mat_n-1){
                    if(board[i-1][j] == 1 || board[i-1][j] == 2) count++;
                    if(board[i-1][j-1] == 1 || board[i-1][j-1] == 2) count++;
                    if(board[i][j-1] == 1 || board[i][j-1] == 2 ) count++;
                    if(board[i+1][j-1] == 1 || board[i+1][j-1] == 2) count++;
                    if(board[i+1][j] == 1 || board[i+1][j] == 2) count++;
                }
                else{
                    if(board[i-1][j-1] == 1 || board[i-1][j-1] == 2) count++;
                    if(board[i-1][j] == 1 || board[i-1][j] == 2) count++;
                    if(board[i-1][j+1] == 1 || board[i-1][j+1] == 2) count++;
                    if(board[i][j+1] == 1 || board[i][j+1] == 2) count++;
                    if(board[i+1][j+1] == 1 || board[i+1][j+1] == 2) count++;
                    if(board[i+1][j] == 1 || board[i+1][j] == 2) count++;
                    if(board[i+1][j-1] == 1 || board[i+1][j-1] == 2) count++;
                    if(board[i][j-1] == 1 || board[i][j-1] == 2) count++;
                }
                
                if(board[i][j]){
                    if(count < 2) board[i][j] = 2;
                    if(count > 3) board[i][j] = 2;
                }
                else{
                    if(count == 3) board[i][j] = -1;
                }
            }
        }
        
        for(int i=0;i<mat_m;i++){
            for(int j=0;j<mat_n;j++){
                if(board[i][j] == -1)
                    board[i][j] = 1;
                if(board[i][j] == 2)
                    board[i][j] = 0;
            }
        }
    }

int main(){
	int board[][7] = {{0,1,0,0,1,1,0},{1,1,1,1,1,1,1},{1,1,0,0,0,0,1},{1,1,0,0,1,0,0}};
	gameOfLife(board,4,7);
	int i,j;
	for(i = 0;i<4;i++){
		for(j=0;j<7;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}
