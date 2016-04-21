#include<iostream>
#include<string>
#include<map>
#include<limits.h>
using namespace std;

map<string,int> hash;

struct QuadTree{
	string str;
	QuadTree *onem_pos,*onep_pos;
	QuadTree *twom_pos,*twop_pos;
	QuadTree(string s):str(s),onem_pos(NULL),onep_pos(NULL),twom_pos(NULL),twop_pos(NULL){}
};


void swap(char *a,char *b){
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

QuadTree *number_steps(string I,string F,int steps,int pos){
	QuadTree *root = new QuadTree(I);
	int len = I.length();
	if(hash.find(I) == hash.end())
		hash[I] = steps;
	else{
		if(steps < hash[I])
			hash[I] = steps;
		return root;
	}
	
	if(I == F)
		return root;

	if(pos<0 || pos >len-1) return root;

	if((pos-1)>=0){
		swap(&I[pos],&I[pos-1]);
		root->onem_pos = number_steps(I,F,steps+1,pos-1);
		swap(&I[pos],&I[pos-1]);
	}
	if((pos+1)<len){
		swap(&I[pos],&I[pos+1]);
		root->onep_pos = number_steps(I,F,steps+1,pos+1);
		swap(&I[pos],&I[pos+1]);
	}
	if((pos-2)>=0 && I[pos-1] != I[pos-2]){
		swap(&I[pos],&I[pos-2]);
		root->twom_pos = number_steps(I,F,steps+1,pos-2);
		swap(&I[pos],&I[pos-2]);

	}
	if((pos+2)<len && I[pos+1] != I[pos+2]){
		swap(&I[pos],&I[pos+2]);
		root->twop_pos = number_steps(I,F,steps+1,pos+2);
		swap(&I[pos],&I[pos+2]);

	}
	return root;
}

int main(){
	QuadTree *root = number_steps("aaab_ab","aa_baab",0,4);
	cout<<hash["aa_baab"]<<endl;
}
