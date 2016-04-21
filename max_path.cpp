#include<iostream>
#include<string>
using namespace std;

struct btree{
	char val;
	btree *left,*right;
	btree(char x):val(x),left(NULL),right(NULL){}
};

int flag = 0;

string lefty,righty;


int height(btree *root){
	if(root == NULL)
		return 0;
	int lheight = height(root->left);
	int rheight = height(root->right);
	
	return (lheight > rheight)?lheight+1:rheight+1;
}

void print_left(btree *root,int height){
	if(root == NULL)
		return;
	print_left(root->left,height-1);
	print_left(root->right,height-1);
	if(height == 0){
		lefty.push_back(root->val);
		flag = 1;
		return;	
	}
	else if(flag == 1){
		lefty.push_back(root->val);
	}
}


void print_right(btree *root,int height){
	if(root == NULL)
		return;
	print_right(root->right,height-1);
	print_right(root->left,height-1);
	if(height == 0){
		righty.push_back(root->val);
		flag = 1;
		return;
	}
	else if(flag == 1){
		righty.push_back(root->val);
	}
}

int main(){
	btree *root = new btree('A');
	root->left = new btree('B');
	root->right = new btree('F');
	root->left->left = new btree('C');
	root->left->right = new btree('E');
	root->right->left = new btree('G');
	root->left->right->left = new btree('D');
	
	int i;
	int lh = height(root->left);
	int rh = height(root->right);
	print_left(root->left,lh);
	flag = 0;
	print_right(root->right,rh);
	int left_len = lefty.length(),right_len = righty.length();
	for(i=0;i<left_len;i++)
		cout<<lefty[i];
	cout<<root->val;
	for(i=right_len-1;i>=0;i--)
		cout<<righty[i];
}
