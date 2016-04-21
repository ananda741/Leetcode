#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left,*right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};


 int max_level = -1;
 vector<int> out;
 vector<vector<int> > answer;
vector<vector<int> > Level_traversal(TreeNode *root,int level){
     if(root == NULL)
        return answer;
    
    if(level > max_level){
        out.push_back(root->val);
        answer.push_back(out);
        out.clear();
        max_level = level;
    }
    else
        answer[level].push_back(root->val);
        
    Level_traversal(root->left,level+1);
    Level_traversal(root->right,level+1);
    
    return answer;
}
 
vector<vector<int> >levelOrder(TreeNode* root) {
     return Level_traversal(root,0);
}


int main(){
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right =  new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	
	vector<vector<int> > answer = levelOrder(root);
	int i,j;
	for(i=0;i<answer.size();i++){
		for(j=0;j<answer[i].size();j++)
			cout<<answer[i][j]<<" ";
		cout<<endl;
	}

}
