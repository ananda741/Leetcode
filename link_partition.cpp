#include<iostream>
#include<stdio.h>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};


    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL)
            return head;
            
        ListNode *laser = new ListNode(0);
        laser->next = head;
        head = laser;
        ListNode *temp = head,*check_point,*first = NULL;

	cout<<head->val<<" "<<laser->val<<" "<<temp->val;
        
        int flag = 0;
        
        while(temp->next!=NULL){
            if(temp->next->val >= x && flag == 0){
                check_point = temp;
                first = temp->next;
                flag = 1;
            }
            else if(flag == 1 && temp->next->val<x){
                ListNode *maser = temp->next;
                temp->next = maser->next;
                check_point->next = maser;
                maser->next = first;
                check_point = maser;
            }
            if(temp->next!=NULL)
            	temp = temp->next;
        }
        
        return head->next;
    }





void push(struct ListNode** head_ref, int new_data)
{
    /* allocate node */
    struct ListNode* new_node = new ListNode(new_data);
             
    /* put in the data  */
    //new_node->data  = new_data;
                 
    /* link the old list off the new node */
    new_node->next = (*head_ref);     
         
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print nodes in a given linked list */
void printList(struct ListNode *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->val);
   node = node->next;
  }
} 
 
/* Drier program to test above functions*/
int main()
{
  /* Start with the empty list */
  struct ListNode* head = NULL;
   
  /* Let us create a sorted linked list to test the functions
   Created linked list will be 11->11->11->13->13->20 */
  //push(&head, 20);
  //push(&head, 13);
  //push(&head, 13);  
  //push(&head, 1);
  push(&head, 1);
  push(&head, 2);                                    
 
  printf("\n Linked list before duplicate removal  ");
  printList(head); 
 
  /* Remove duplicates from linked list */
  head = partition(head,2); 
 
  printf("\n Linked list after duplicate removal ");         
  printList(head);            
   cout<<endl;
}
