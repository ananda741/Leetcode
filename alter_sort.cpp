#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};


ListNode *merge(ListNode *l1,ListNode *l2){
	if(l1 == NULL) return l2;
	if(l2 == NULL) return l1;
	
	ListNode *result;
	if(l1->val <= l2->val){
		result = l1;
		result->next = merge(l1->next,l2);
	}
	else{
		result = l2;
		result->next = merge(l1,l2->next);
	}
	return result;
}

ListNode *reverse(ListNode *head){
	ListNode *first = head;
	if(first == NULL) 
		return NULL;
	ListNode *rest = head->next;
	if(rest == NULL) 
		return first;
	ListNode *p = reverse(rest);
	first->next->next = first;
	first->next = NULL;
	return p;
}

ListNode *alter_sort(ListNode *head){
	if(head == NULL || head->next == NULL) return head;
	
	ListNode *first,*second;
	ListNode *tempA,*tempB;
	tempA = head;
	tempB = head->next;
	first = tempA , second = tempB;
	while(tempA != NULL && tempB != NULL){
		tempA->next = tempB->next;
		tempA = tempA->next;
		if(tempA == NULL) break;
		tempB->next = tempA->next;
		tempB = tempB->next;
	}
	
	tempA = first , tempB = second;
	cout<<"First :";
	while(tempA!=NULL){
		cout<<tempA->val<<" ";
		tempA = tempA->next;
	}

	cout<<"Second :";
	while(tempB!=NULL){
		cout<<tempB->val<<" ";
		tempB = tempB->next;
	}

	if(first->next != NULL){
		if(first->val > first->next->val)
			first = reverse(first);
	}

	if(second->next != NULL){
		if(second->val >second->next->val)
			second = reverse(second);
	}

	cout<<endl;
	head = merge(first,second);
	return head;
}


int main(){
	ListNode *head = new ListNode(10);
	head->next = new ListNode(60);
	head->next->next = new ListNode(30);
	head->next->next->next = new ListNode(40);
	head->next->next->next->next = new ListNode(50);
	head->next->next->next->next->next = new ListNode(20);

	head = alter_sort(head);
	ListNode *temp = head;
	while(temp!=NULL){
		cout<<temp->val<<" ";
		temp = temp->next;
	}	
}
