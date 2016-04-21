#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<limits.h>
using namespace std;

struct boxstack{
	int length;
	int width;
	int height;
};

boxstack new_cubes[100];

int formula(boxstack a,boxstack b){
	int area1 = a.length * a.width;
	int area2 = b.length * b.width;

	return (area1 < area2)?0:1;
}

int create_stack(boxstack cubes[],int len){
	int i,size = 0;
	if(len == 0) return len;
	for(i=0;i<len;i++){
		if(cubes[i].length == cubes[i].width && cubes[i].width == cubes[i].height)
			new_cubes[size++] = cubes[i];
		else if(cubes[i].length == cubes[i].width || cubes[i].width == cubes[i].height || cubes[i].length == cubes[i].height){
			if(cubes[i].length == cubes[i].width){
				new_cubes[size++] = cubes[i];
				if(cubes[i].height > cubes[i].width){
					swap(cubes[i].length,cubes[i].height);
					new_cubes[size++] = cubes[i];
				}
				else{
					swap(cubes[i].width,cubes[i].height);
					new_cubes[size++] = cubes[i];
				}
			}
			else if(cubes[i].width == cubes[i].height){
				new_cubes[size++] = cubes[i];
				swap(cubes[i].length,cubes[i].height);
				new_cubes[size++] = cubes[i];
			}
			else{
				new_cubes[size++] = cubes[i];
				swap(cubes[i].width,cubes[i].height);
				new_cubes[size++] = cubes[i];
			}
		}
		else{
			new_cubes[size++] = cubes[i];
			if(cubes[i].height > cubes[i].width){
				swap(cubes[i].height,cubes[i].length);
				new_cubes[size++] = cubes[i];
				if(cubes[i].height < cubes[i].length){
					swap(cubes[i].width,cubes[i].height);
					new_cubes[size++] = cubes[i];
				}
				else if(cubes[i].height > cubes[i].width){
					swap(cubes[i].height,cubes[i].length);
					new_cubes[size++] = cubes[i];
				}
			}
			else if(cubes[i].height < cubes[i].length){
				swap(cubes[i].width,cubes[i].height);
				new_cubes[size++] = cubes[i];
				if(cubes[i].height < cubes[i].length){
					swap(cubes[i].width,cubes[i].height);
					new_cubes[size++] = cubes[i];
				}
				else if(cubes[i].height > cubes[i].width){
					swap(cubes[i].height,cubes[i].length);
					new_cubes[size++] = cubes[i];
				}
			}
		}
	}
	return size;	
}

void LIS(int len){
	int *max_array = (int *)malloc(len*sizeof(int));
	int *result = (int *)malloc(len*sizeof(int));

	int i,j;
	for(i=0;i<len;i++){
		max_array[i] = new_cubes[i].height;
		result[i] = -1;
	}

	for(i=1;i<len;i++){
		for(j=0;j<i;j++){
			if(new_cubes[i].length < new_cubes[j].length && new_cubes[i].width < new_cubes[j].width){
				int val = max_array[j]+new_cubes[i].height;
				if(val > max_array[i]){
					max_array[i] = val;
					result[i] = j;
				}
			}
		}
	}
	int maxval = INT_MIN,index;

	for(i=0;i<len;i++){
		if(max_array[i] > maxval){
			maxval = max_array[i];
			index = i;
		}
	}

	cout<<"max_array "<<endl;
	for(i=0;i<len;i++)
		cout<<max_array[i]<<" ";
	cout<<endl;

	cout<<"result array "<<endl;
	for(i=0;i<len;i++)
		cout<<result[i]<<" ";
	cout<<endl;

	cout<<"Maximum height achieved "<<maxval<<endl;

	while(index != -1){
		cout<<new_cubes[index].length<<" "<<new_cubes[index].width<<" "<<new_cubes[index].height<<endl;
		index = result[index];
	}
}

int main(){
	boxstack cubes[] = {{2,1,4},{3,2,5}};
	int size = sizeof(cubes)/sizeof(cubes[0]);
	int new_len = create_stack(cubes,size);

	cout<<new_len<<endl;
	
	sort(new_cubes,new_cubes+new_len,formula);
	
	for(int i=0;i<new_len;i++){
		cout<<new_cubes[i].length<<" "<<new_cubes[i].width<<" "<<new_cubes[i].height<<" "<<endl;
	}

	LIS(new_len);
}
