#include<iostream>
#include<stack>
using namespace std;

stack<int> s1,s2;

    void push(int x) {
        int laser;
        while(!s1.empty()){
            laser = s1.top();
            s1.pop();
            s2.push(laser);
        }
        s1.push(x);
        while(!s2.empty()){
            laser = s2.top();
            s2.pop();
            s1.push(laser);
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        s1.pop();
    }

    // Get the front element.
    int peek(void) {
        int laser = s1.top();	
        return laser;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty();
    }


int main(){
	push(1);
	push(2);
	cout<<peek()<<endl;
	pop();
	cout<<peek()<<endl;
	pop();
	cout<<empty()<<endl;	
}
