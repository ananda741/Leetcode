#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left,*right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

int max_level = INT_MIN;

vector<vector<int> > answer;

vector<vector<int> > Print_Diagonal(TreeNode *root,int Diag_level){
	if(root == NULL) return answer;
	Print_Diagonal(root->left,Diag_level+1);
	if(Diag_level > max_level){
		max_level = Diag_level;
		vector<int> out;
		out.push_back(root->val);
		answer.push_back(out);
	}
	else{
		answer[Diag_level].push_back(root->val);
	}
	Print_Diagonal(root->right,Diag_level);
	return answer;
}

int main(){
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->right = new TreeNode(6);
	root->left->right->left = new TreeNode(8);
	root->left->right->right = new TreeNode(7); 

	vector<vector<int> > result = Print_Diagonal(root,0);

	int len = result.size();
	int i,j;
	for(i=0;i<len;i++){
		int k = result[i].size();
		for(j=0;j<k;j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
} 
