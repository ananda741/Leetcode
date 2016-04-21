#include<iostream>
#include<stdio.h>
using namespace std;

struct ListNode{
	int data;
	ListNode* next;
};



    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first,*second,*temp;
        first = head;
        second = head;
        
        if(head == NULL)
            return NULL;
            
        if(n == 0)
            return head;
            
        if(n == 1 &&head->next==NULL)
            return NULL;
            
        int count = 1;
        
        while(count<n && second!=NULL){
            second = second->next;
            count++;
        }
        
            
        while(second->next!=NULL){
            first = first->next;
            second = second->next;
        }
        
	temp = head;
	if(temp ==  first){
		ListNode* laser = head;
		head = head->next;
		delete(laser);
		return head;		
	} 
	while(temp->next!=first)
		temp = temp->next;

        
        temp->next = first->next;
        delete(first);
        
        return head;
    }



void push(struct ListNode** head_ref, int new_data)
{
  /* allocate node */
  struct ListNode* new_node = new ListNode;
 
  /* put in the data  */
  new_node->data  = new_data;
 
  /* link the old list off the new node */
  new_node->next = (*head_ref);    
 
  /* move the head to point to the new node */
  (*head_ref)    = new_node;
}
 

void PrintList(ListNode* node){
	while(node!=NULL){
		cout<<node->data<<" ";
		node = node->next;
		}
	cout<<endl;
}

/* Drier program to test above function*/
int main()
{
  /* Start with the empty list */
  struct ListNode* head = NULL;
  push(&head, 5);
  push(&head, 4);
  push(&head, 3);
  push(&head, 2);
  push(&head, 1);
  //push(&head, 15); 
 
  cout<<"Before Removal\n";

	PrintList(head);
	head = removeNthFromEnd(head,5);
  cout<<"After Removal\n";

	PrintList(head);
}
