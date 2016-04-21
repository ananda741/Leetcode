#include<iostream>
#include<stdio.h>
using namespace std;

struct node{
	int data;
	struct node *left,*right;
};



int maxSumPath(node* root,int sum){
	if(root == NULL)
		return 0;
	sum+=root->data;
	static int max = 0;
	cout<<"sum = "<<sum<<endl;
	if(root->left == NULL && root->right == NULL){
		if(sum > max){
			max = sum;
		}
	}

	int laser = maxSumPath(root->left,sum);
	int maset = maxSumPath(root->right,sum);

	return max;
}


struct node* newNode (int data)
{
    struct node *temp = new struct node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
 
/* Driver function to test above functions */
int main()
{
    struct node *root = NULL;
 
    /* Constructing tree given in the above figure */
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(7);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
 
    printf ("Following are the nodes on the maximum sum path \n");
    int sum = maxSumPath(root,0);
    printf ("\nSum of the nodes is %d ", sum);
 
    
    return 0;
}
