#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

	    ListNode *middle(ListNode* head){
		ListNode  *fast,*slow;
		slow = head;
		fast = head->next;
		
		while(fast!=NULL && fast->next!=NULL){
		    slow = slow->next;
		    fast = fast->next->next;
		}
		return slow;
	    }

	    ListNode *reverse(ListNode *maser){
		ListNode *current,*temp = NULL;
		current = maser;
		ListNode *node;
		while(current!=NULL){
		    node = current->next;
		    current->next = temp;
		    temp = current;
		    current = node;
		}
		
		return temp;
	    }

	    bool isPalindrome(ListNode* head) {
		if(head == NULL || head->next == NULL)
		    return true;
		ListNode *mid;
		mid = middle(head);
		//cout<<mid->val<<endl;
		ListNode* cutie = mid->next;
		mid->next = NULL;
		cutie = reverse(cutie);
		//cout<<cutie->val;
		ListNode *temp,*wemp;
		temp = head;
		wemp = cutie;
		
		int flag = 0;
		
		while(wemp!=NULL){
		    if(temp->val != wemp->val){
		        flag = 1;
		        break;
		    }
		    wemp = wemp->next;
		    temp = temp->next;
		}
		
		return (flag == 0)? true: false;
	    }


int main(){
	ListNode *head = new ListNode(1);
	ListNode *temp = new ListNode(2);
	head->next = temp;
	ListNode *wemp = new ListNode(1);
	temp->next = wemp;
	cout<<isPalindrome(head);
}


