#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left,*right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* Tree_construct(vector<int> &pre,vector<int> &post,int *preindex,int l,int h){
	int i,len = pre.size();
	if(*preindex >= len || l>h)
		return NULL;

	TreeNode *root = new TreeNode(pre[*preindex]);
	++*preindex;
	
	for(i=0;i<len;i++){
		if(pre[*preindex] == post[i])
			break;
	}

	if(i<=h){
		root->left = Tree_construct(pre,post,preindex,l,i);
		root->right = Tree_construct(pre,post,preindex,i+1,h);
	}

	return root;
}

void inorder(TreeNode *root){
	if(root == NULL)
		return;
	inorder(root->left);
	cout<<root->val<<"  ";
	inorder(root->right);
}


int main(){
	vector<int> pre,post;
	pre.push_back(1);
	pre.push_back(2);
	pre.push_back(4);
	pre.push_back(5);
	pre.push_back(3);
	pre.push_back(6);
	pre.push_back(7);
	post.push_back(4);
	post.push_back(5);
	post.push_back(2);
	post.push_back(6);
	post.push_back(7);
	post.push_back(3);
	post.push_back(1);
	
	int preindex = 0,len = pre.size();
	TreeNode *root = Tree_construct(pre,post,&preindex,0,len-1);
	inorder(root);
	cout<<endl;
}
