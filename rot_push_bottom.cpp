#include<iostream>
using namespace std;

void swap(char *a,char *b){
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


void rot_push_bottom(char matrix[][3]){
	int i,j;
	for(i=0;i<2;i++)
		for(j = i+1;j<3;j++)
			swap(&matrix[i][j],&matrix[j][i]);

	int k;
	for(i=0;i<3;i++){
		for(j=0,k=2;j<k;j++,k--)
			swap(&matrix[i][j],&matrix[i][k]);
	}

	for(j=0;j<3;j++){
		for(i=0,k=2;i<k;){
			if(matrix[i][j] == 'o' && matrix[k][j] == 'o')
				i++;
			else if(matrix[i][j] == 'x' && matrix[k][j] == 'x')
				k--;
			else if(matrix[i][j] == 'o' && matrix[k][j] == 'x'){
				i++;
				k--;
			}
			else if(matrix[i][j] == 'x' && matrix[k][j] == 'o'){
				swap(&matrix[i][j],&matrix[k][j]);
				i++;
				k--;
			}
		}
	}
}


int main(){
	char matrix[3][3] = {{'x','o','o'},{'o','x','x'},{'x','o','x'}};
	int i,j;
	rot_push_bottom(matrix);
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			cout<<matrix[i][j]<<" ";
	cout<<endl;	
	}
}
