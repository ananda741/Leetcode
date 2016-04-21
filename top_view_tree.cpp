#include<iostream>
#include<map>
#include<limits.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left,*right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};

map<int,int> laser;
int maxim = INT_MIN,minim = INT_MAX;

void Top_view(TreeNode *root,int level){
	if(root == NULL)
		return;
	if(laser.find(level) == laser.end()){
		laser[level] = root->val;
		if(level>maxim)
			maxim = level;
		if(level<minim)
			minim = level;
	}

	Top_view(root->left,level-1);
	Top_view(root->right,level+1);
}

void Print(){
	int i;
	for(i = minim;i<=maxim;i++){
		cout<<laser[i]<<" ";
	}
}

int main(){
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right =  new TreeNode(4);
	root->left->right->right =  new TreeNode(5);
	root->left->right->right->right =  new TreeNode(6); 

	Top_view(root,0);
	Print();
}
