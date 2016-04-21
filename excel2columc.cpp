#include<iostream>
#include<algorithm>
using namespace std;


char* convertToTitle(int n) {
    char *s,*p;
    s = (char* )malloc(50*sizeof(char));
    p = (char* )malloc(50*sizeof(char));
    int i=0,j,k=0;
    while(n>0){
        int rem = n%26;
        if(rem == 0){
	    
            s[i++] = 'Z';
            n = n/26 - 1;
        }
        else{
            s[i++] = rem-1 + 'A';
            n = n/26;
        }
    }
    s[i] = '\0';
    
    for(j = i-1;j>=0;j--){
        p[k++] = s[j];
    }
    p[k] = '\0';
    
    return p;
}

int main(){
	string p;
	long long i;
	p = convertToTitle(78);
	for(i=0;p[i]!='\0';i++)
		cout<<p[i];
	cout<<"\n";
}
