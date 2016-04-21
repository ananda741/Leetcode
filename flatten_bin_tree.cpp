#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left,*right;
	
};




    void preorder(TreeNode* root,vector<TreeNode*> &arr){
        if(root == NULL)
            return;
            
        arr.push_back(root);
        preorder(root->left,arr);
        preorder(root->right,arr);
    }

    void flatten(TreeNode* root) {
        vector<TreeNode*> arr;
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL)
            return;
        preorder(root,arr);
        


        int i,len;
        len = arr.size();

	for(i = 0;i<len;i++)
		cout<<arr[i]->val<<" ";
	cout<<endl;

  	for(i = 0;i<len-1;i++){
		arr[i]->right = arr[i+1];
		arr[i]->left = NULL;
	}
    }






struct TreeNode* newnode(int data)
{
  struct TreeNode* node = new TreeNode;
  node->val = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
 
/* Driver program to test above functions*/
int main()
{
 
  /* Construct the following binary tree
              1
            /   \
          2      3
        /  \
      4     5
     /
    7
  */
  struct TreeNode *root = newnode(1);
  root->left        = newnode(2);
  root->right       = newnode(3);
  root->left->left  = newnode(4);
  root->left->right = newnode(5);
  root->left->left->left  = newnode(7);
 
	flatten(root);

	while(root!=NULL){
		cout<<root->val<<" ";
		root = root->right;
	}
  
  cout<<endl;
  return 0;
}
