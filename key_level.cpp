#include<iostream>
#include<stdio.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};


int getLevel(node* root,int dat,int level){
	if(root == NULL)
		return 0;
	if(root->data == dat)
		return level;

	int down_level = getLevel(root->left,dat,level+1);
	if(down_level!=0)
		return down_level;
	down_level = getLevel(root->right,dat,level+1);
	return down_level;
}

struct node* newNode(int data)
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
    struct node *root = new struct node;
    int x;
 
    /* Constructing tree given in the above figure */
    root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(4);
 
    for (x = 1; x <=5; x++)
    {
      int level = getLevel(root, x,1);
      if (level)
        printf(" Level of %d is %d\n", x, level);
      else
        printf(" %d is not present in tree \n", x);
 
    }
 
    getchar();
    return 0;
}
