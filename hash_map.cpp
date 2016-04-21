#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;


class HASH{
	static const int SIZE = 5;

	struct item{
		int key;
		const char *s;
		item *next;
	};
	
	public:
		item **table;
		HASH();
		int create_hash(int key);
		void addItem(int key,const char *name);
		void PrintTable();
		void PrintTableIndex(int ind);
		void searchKey(int key);
		void RemoveKey(int key);
		int countIndex(int index);		
};


HASH::HASH(){
	table = (item **)malloc(sizeof(item *)*SIZE);
	int i;
	for(i=0;i<SIZE;i++){
		table[i] = (item *)malloc(sizeof(item));
		table[i]->key = -1;
		table[i]->s = (const char *)malloc(sizeof(const char)*10);
		table[i]->s = "empty";
		table[i]->next = NULL;
	}
}

int HASH::create_hash(int key){
	return key%SIZE;	
}

int HASH::countIndex(int index){
	int count=0;
	if(table[index]->key == 0)
		return 0;
	else{
		item *temp = table[index];
		while(temp!=NULL){
			count++;
			temp = temp->next;
		}
	}
	return count;
}

void HASH::addItem(int key,const char *name){
	int index = key%SIZE;

	if(table[index]->key == -1){
		table[index]->key = key;
		table[index]->s = name;
	}

	else{
		item *temp = table[index];
		while(temp->next!=NULL && temp->key == key)
			temp = temp->next;

		if(temp->next!=NULL){
			temp->s = name;
			return;
		}

		item *laser = (item *)malloc(sizeof(int));
		laser->key = key;
		laser->s = name;
		temp->next  = laser;
	}
}


void HASH::PrintTable(){
	int i;
	for(i=0;i<SIZE;i++){
		cout<<"----------\n";
		if(table[i]->key == -1){
			cout<<"Not present \n";
			continue;
		}
		cout<<create_hash(table[i]->key)<<" - "<<table[i]->s<<endl;
		cout<<countIndex(i)<<endl;
		cout<<"----------\n";		
	}
}

void HASH::PrintTableIndex(int ind){
	if(table[ind]->key == -1){
		cout<<"Key empty ";
	}
	else{
		item *temp;
		temp = table[ind];
		while(temp!=NULL){
			cout<<"----------\n";
			cout<<temp->key<<" - "<<temp->s;
			cout<<"----------\n";
			temp = temp->next;
		}
	}
}

void HASH::searchKey(int key){
	int index = create_hash(key);
	if(table[index]->key == -1){
		cout<<"KEY DOESN'T EXIST \n";
	}
	else{
		item *temp = table[index];
		while(temp!=NULL){
			if(temp->key == key)
				break;
			temp = temp->next;			
		}
		cout<<key<<" - "<<temp->s<<endl; 
	}
}


void HASH::RemoveKey(int key){
	int index = create_hash(key);
	
	if(table[index]->key == -1)
		cout<<"Key doesn't exist ";

	else if(table[index]->key == key && table[index]->next == NULL){
		table[index]->key = -1;
		table[index]->s = "empty";
	}

	else if(table[index]->key == key){
		item *laser = table[index];
		table[index] = table[index]->next;
		free(laser);
	}

	else{
		item *temp = table[index]->next;
		item *laser,*p1 = table[index];
		while(temp!=NULL && temp->key!=key){
			p1 = temp;
			temp = temp->next;
		}

		if(temp == NULL)
			cout<<"Key doesn't exist ";
	
		else{
			laser = temp;
			p1->next = temp->next;
			free(laser);
		}
	}
}



int main(){
	HASH hash;
	
	hash.addItem(12,"vivek");
	hash.addItem(113,"kumar");
	hash.addItem(4,"mahto");
	hash.addItem(126,"ananda");
	hash.addItem(131,"the");
	hash.addItem(1,"great");
	hash.addItem(129,"laser");
	hash.addItem(120,"awesome");
	hash.addItem(125,"brock");
	hash.addItem(122,"lesnar");
	hash.addItem(122,"roman");
	hash.addItem(167,"reigns");
	hash.addItem(1245,"cm punk");

	hash.RemoveKey(122);
	hash.searchKey(122);
}
