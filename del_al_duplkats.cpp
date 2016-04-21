#include<iostream>
#include<map>
#include<stdio.h>
using namespace std;

struct ListNode{
	int val;
	struct ListNode* next;
};


  ListNode* deleteDuplicates(ListNode* head) {
        map<int , int> laser;
        if(head == NULL || head->next == NULL)
            return head;
            
        ListNode* res = NULL,*temp,*prev = NULL;
        temp = head;
        
        while(temp!=NULL){
            if(laser.find(temp->val) == laser.end())
                laser[temp->val] = 1;
            else
                laser[temp->val]+=1;
                
            temp = temp->next;
        }
        
        temp = head;
        while(temp!=NULL){
            if(laser[temp->val] == 1){
                if(res == NULL)
                    res = temp;
                else
                    prev->next = temp;
                    
                prev = temp;
            }
            temp = temp->next;
        }
	if(prev)
        prev->next = NULL;
        
        return res;
    }


struct ListNode *newNode(int data)
{
    struct ListNode *new_node = new ListNode;
    new_node->val = data;
    new_node->next = NULL;
    return new_node;
}


void push(struct ListNode** head_ref, int new_data)
{
    /* allocate node */
    struct ListNode* new_node = newNode(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}


void printList(struct ListNode *node)
{
    while(node != NULL)
    {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}
 
/* Drier program to test above function */
int main(void)
{
  
    struct ListNode* first = NULL;

 
    // create first list 7->5->9->4->6
    push(&first, 1);
    push(&first, 1);
    //push(&first, 2);
    //push(&first, 2);
    //push(&first, 3);
    printf("First List is ");
	printList(first);

    first = deleteDuplicates(first);

	cout<<endl;
	printList(first);
    
   return 0;
}

