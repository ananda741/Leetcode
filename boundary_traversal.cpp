#include<iostream>
using namespace std;

struct btree{
	int val;
	btree *left,*right;
	btree(int x):val(x),left(NULL),right(NULL){}
};


void boundary(btree *root,int left,int right){
	if(root == NULL)
		return;
	if(right == 0)
		cout<<root->val<<" ";
	boundary(root->left,left+1,right);
	if(root->left == NULL && root->right ==NULL && right>0 && left>0)
		cout<<root->val<<" ";
	boundary(root->right,left,right+1);
	if(left == 0){
		if(right!=0)
			cout<<root->val<<" ";
	}
}

int main(){
	btree *root = new btree(1);
	root->left = new btree(2);
	root->right = new btree(3);
	root->left->left = new btree(4);
	root->left->right = new btree(5);
	root->right->left = new btree(6);
	root->right->right = new btree(7);
	root->left->left->left = new btree(8);
	root->left->left->right = new btree(9);
	root->left->right->left = new btree(10);
	root->left->right->right = new btree(11);
	root->right->right->left = new btree(12);
	root->right->right->right = new btree(13);
	boundary(root,0,0);
}
