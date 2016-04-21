#include<iostream>
#include<map>
using namespace std;

struct Dnode{
  int key;
  int value;
  Dnode *prev,*next;
  Dnode(int x,int y) : key(x),value(y),prev(NULL),next(NULL){}
};


class LRUCache{
    int cap;
    map<int,Dnode*> laser;
    Dnode *head;
    Dnode *end;
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = NULL;
        end = NULL;
    }
    
    void remove_node(Dnode *temp){
        if(temp->prev == NULL && temp->next == NULL){
            head = end = NULL;
        }
        else if(temp->prev == NULL)
            head = temp->next;
        else if(temp == end || temp->next == NULL){
            end = end->prev;
	}
        else{
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
    }
    
    void insert_node(Dnode *temp){
        if(head == NULL && end == NULL)
                head = end = temp;
        else{
            temp->next = head;
            head->prev = temp;
            head= temp;
        }
    }
    
    int get(int key) {
        if(laser.find(key)!=laser.end()){
            Dnode *temp = laser[key];
            remove_node(temp);
            insert_node(temp);
            return temp->value;
        }
        
        return -1;
    }
    
    void set(int key, int value) {
        if(laser.find(key) != laser.end()){
            Dnode *temp = laser[key];
            temp->value = value;
            remove_node(temp);
            insert_node(temp);
        }
        else{
            Dnode *temp = new Dnode(key,value);
            if(laser.size()>=cap){
                laser.erase(end->key);
                remove_node(end);
                insert_node(temp);
            }
            else
                insert_node(temp);
                
            laser[key] = temp;
        }
    }

    void print(){
	Dnode *temp = head;
	while(temp != end->next){
		cout<<temp->key<<" ";
		temp = temp->next;
	}
	cout<<endl;
    }
};



int main(){
	LRUCache LRU(3);

	LRU.set(1,1);
	LRU.set(2,2);
	LRU.set(3,3);
	LRU.set(4,4);
	cout<<LRU.get(4)<<" ";
	cout<<LRU.get(3)<<" ";
	cout<<LRU.get(2)<<" ";
//	LRU.print();
	cout<<LRU.get(1)<<" ";  

	LRU.set(5,5);
	cout<<LRU.get(1)<<" ";
	cout<<LRU.get(2)<<" ";
	cout<<LRU.get(3)<<" ";
	cout<<LRU.get(4)<<" ";
	cout<<LRU.get(5)<<" ";                     
	cout<<endl;
}
