#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left,*right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

    string new_str;
    
    void swap(char *a,char *b){
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

string reverse(string answer){
	int i,j,len = answer.length();
	for(i=0,j=len-1;j>i;i++,j--){
		swap(&answer[i],&answer[j]);
	}
	return answer;
}

string int2str(int data){
	string answer;
	int flag = 0;
	if(data == 0)
		return "0";
	if(data < 0){
		flag = 1;
		data*=-1;
	}
	while(data){
		int k = data%10;
		char val = (char)(k+48);
		data/=10;
		answer.push_back(val);
	}
	if(flag == 1)
		answer = answer + "-";
	return reverse(answer);
}
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL){
            new_str = new_str + "99999.";
            return new_str;
        }
        new_str = new_str + int2str(root->val);
        new_str = new_str + '.';
        serialize(root->left);
        serialize(root->right);
        
        return new_str;
    }


    vector<int> tree;
    
    void func(string data){
        int i,len = data.length();
        int val = 0,flag = 0;
        
        for(i=0;i<len;i++){
            if(data[i] == '.'){
		if(flag == 1) val*=-1;
                tree.push_back(val);
		val = 0;
		flag = 0;
            }
            else{
		if(data[i] == '-')
			flag = 1;
		else
                	val = val*10 + ((int)data[i] - 48);
            }
        }
    }
    
	int val = 0;

    TreeNode *de_serialize(){ 
        if(tree[val] == 99999)
            return NULL;
        TreeNode *new_node = new TreeNode(tree[val]);
	val++;
        new_node->left = de_serialize();
	val++;
        new_node->right = de_serialize();
        return new_node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        func(data);
	int i,len = tree.size();

        return de_serialize();
    }

	void inorder(TreeNode *root){
		if(root == NULL) return;
		inorder(root->left);
		cout<<root->val<<" ";
		inorder(root->right);
	}

int main(){
	TreeNode *new_node = new TreeNode(-1);
	new_node->left = new TreeNode(0);
	new_node->right = new TreeNode(1);
	//new_node->left->left = new TreeNode(2);
	//new_node->left->right = new TreeNode(8);
	//new_node->right->left = new TreeNode(12);
	//new_node->right->right = new TreeNode(18);

	string answer = serialize(new_node);
	cout<<endl<<answer<<endl;
	TreeNode *root = deserialize(answer);

	inorder(root);
	cout<<endl;
}
