#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct trie{
	int prefix_count;
	bool is_end;
	trie *children[26];
};


trie* initialize(){
	trie* head = new trie();
	head->prefix_count = 0;
	head->is_end = false;
	int i=0,index;
	for(i=0;i<26;i++){
		head->children[i] = NULL;
	}
	return head;
}

class trie_struct{
	trie *head;
	public:
		trie_struct();
		void insert(string key);
		bool search(string key);
};

trie_struct::trie_struct(){
	head = initialize();
}

void trie_struct::insert(string key){
	trie * current;
	current = head;
	current->prefix_count++;
	int i,len = key.length(),index;
	for(i=0;i<len;i++){
		index = int(key[i]) - 97;
		if(current->children[index] == NULL)
			current->children[index] = initialize();
		current->children[index]->prefix_count++;
		current = current->children[index];
	}
	current->is_end = true;
}


bool trie_struct::search(string key){
	trie *current;	
	current = head;
	int i,len = key.length(),index;
	for(i=0;i<len;i++){
		index = int(key[i])-97;
		if(current->children[index] == NULL)
			return false;
		current = current->children[index];
	}
	return current->is_end;
}

int main(){
	trie_struct first;
	vector<string> array({"the", "a", "there", "answer", "any", "by", "bye", "their"});
	int i,len = array.size();
	for(i=0;i<len;i++)
		first.insert(array[i]);
	string laser;
	cout<<"Enter the string to search\n";
	cin>>laser;
	if(first.search(laser))
		cout<<"Found\n";
	else
		cout<<"Not present\n";
}
