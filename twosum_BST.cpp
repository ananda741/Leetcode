#include<iostream>
#include<stack>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left,*right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

bool BST_sum(TreeNode *root, int target){
	stack<TreeNode*> s1,s2;
	bool done1 = 0,done2 = 0;
	int val1 = 0 , val2 = 0;
	TreeNode *curr1 = root,*curr2 = root;
	while(1){
		while(done1 == false){
			if(curr1 != NULL){
				s1.push(curr1);
				curr1 = curr1->left;
			}
			else{
				if(s1.empty())
					done1 = 1;
				else{
					curr1 = s1.top();
					s1.pop();
					val1 = curr1->val;
					curr1 = curr1->right;
					done1 = 1;
				}
			}
		}
		while(done2 == false){
			if(curr2 != NULL){
				s2.push(curr2);
				curr2 = curr2->right;
			}
			else{
				if(s2.empty())
					done2 = 1;
				else{
					curr2 = s2.top();
					s2.pop();
					val2 = curr2->val;
					curr2 = curr2->left;
					done2 = 1;
				}
			}
		}

		if((val1 != val2) && (val1+val2 == target)){
			cout<<val1<<" + "<<val2<<" = "<<target<<endl;
			return true;
		}
		else if(val1+val2 < target)
			done1 = false;
		else if(val1+val2 > target)
			done2 = false;
		else if(val1>=val2)
			return false;
	}
}

int main(){
	TreeNode *root = new TreeNode(15);
	root->left = new TreeNode(10);
	root->right = new TreeNode(20);
	root->left->left = new TreeNode(8);
	root->left->right = new TreeNode(12);
	root->right->left = new TreeNode(16);
	root->right->right = new TreeNode(25);

	BST_sum(root,33);
}
