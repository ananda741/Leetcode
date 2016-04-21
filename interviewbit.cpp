#include<iostream>
#include<stdio.h>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
}; 



ListNode* reverse(ListNode *head){
    ListNode *current= head,*temp = NULL,*laser;
    while(current!=NULL){
        laser = current->next;
        current->next = temp;
        temp = current;
        current = laser;
    }
    return temp;
}

ListNode* mid(ListNode *head){
    ListNode* fast,*slow;
    slow = head;
    fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}
 
ListNode* subtract(ListNode* A) {
    ListNode* second,*middle,*temp,*maser;
    if(A == NULL || A->next == NULL)
        return A;
    middle = mid(A);
    second = middle->next;
    middle->next=NULL;
    second =reverse(second);
    temp = second;
    maser = A;
    while(temp!=NULL){
        maser->val = temp->val - maser->val;
        maser = maser->next;
        temp = temp->next;
    }
    
    second = reverse(second);
    middle->next = second;
    
    return A;
}






void push(struct ListNode** head_ref, int new_data)
{

  struct ListNode* new_node = new ListNode;
            
 
  new_node->val  = new_data;
 
  new_node->next = (*head_ref);    
 
  (*head_ref)    = new_node;
}
 
 
void printList(struct ListNode *node)
{
  while(node != NULL)
  {
    printf("%d ", node->val);
    node = node->next;
  }
}
 

int main()
{
  struct ListNode *start = NULL;   
 
  /* The constructed linked list is:
   1->2->3->4->5 */
  //push(&start, 5);
  push(&start, 4);
  push(&start, 3);
  push(&start, 2);
  push(&start, 1);
 
  printf("\n Linked list before moving last to front ");
  printList(start);
 
  start = subtract(start);
 
  printf("\n Linked list after removing last to front ");
  printList(start);
  cout<<endl;

}
