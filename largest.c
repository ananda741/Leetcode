#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char* largestnum(const int* A, int n1) {
    int arr[10]={0},i,len,rem,k=0,p;
    char *s = (char*)malloc(100*sizeof(char));
    
    for(i=0;i<n1;i++){
        p = A[i];
        while(p>0){
            rem = p%10;
            arr[rem]++;
            p=p/10;
        }
    }

    
    for(i = 9;i>=0;i++){
        while(arr[i]!=0){
            s[k++] = i - 48;
        }
    }

	s[k] = '\0';
	
	return s;

}

int main(){
	int A[] = {8 , 89};
	char *p;
	p = largestnum(A,2);
	int i,len;
	len = strlen(p);
	printf("%s",p);
	
}
