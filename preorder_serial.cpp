#include<iostream>
#include<stack>
using namespace std;

    bool isValidSerialization(string preorder) {
        int len = preorder.length(),i,val = 0;
        if(len == 1 && preorder[0] == '#') return true;
        if(len < 2 ) return false; 
        stack<int> tree;
        for(i=0;i<len;i++){
            if(preorder[i] >='0' && preorder[i] <='9'){
		val = val*10 + int(preorder[i])-48;
	    }
            else if(preorder[i] == '#'){
                if(tree.empty()) break;
                tree.pop();
            }
	    else if(preorder[i] == ','){
		if((i-1)>=0 && preorder[i-1] == '#') continue;
		tree.push(val);
		val = 0;
	    }
        }
        
	cout<<len<<" "<<i<<endl;
        if(i != len-1) return false;
        
        return tree.empty();
    }

int main(){
	cout<<isValidSerialization("9,#,92,#,#")<<endl;
}
