#include<stdio.h>


int removeDuplicates(int* a, int numsSize) {
    int i,j,flag = 0;
    if(numsSize<=2)
        return numsSize;     
        
    for(i=0;i<numsSize-1;i++){
        if(a[i] == a[i+1] && flag == 0){
            j++;
            flag = 1;
        }
        else if(a[i] != a[i+1]){
            flag = 0;
            j++;
            a[j] = a[i+1];
        }
    }
    
    return j+1;
}


int main(){
	int arr[] ={1,1,1};
	int i,j;
	j = removeDuplicates(arr,3);
	printf("%d \n",j);
	for(i=0;i<j;i++)
		printf("%d ",arr[i]);	
}
