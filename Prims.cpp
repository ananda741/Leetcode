#include<iostream>
#include<map>
#include<vector>
#include<limits.h>

#define V 5
using namespace std;

vector<bool> mst(V,false);
vector<int> key(V,INT_MAX);
vector<int> parent(V,-1);

int findMin(){
	int minpos = INT_MAX,i;
	for(i = 0;i<V;i++){
		if(minpos > key[i] && mst[i] == false)
			minpos = i;
	}
	return minpos;
}


void printMST(){
	int i,sum=0;
	for(i=1;i<V;i++){
		cout<<parent[i]<<"-----"<<i<<"         "<<key[i]<<endl;
		sum+=key[i];	
	}
	cout<<sum;
}


void primMST(int graph[][V]){
	key[0] = 0;
	int i,j;
	for(i = 0;i<V;i++){
		int min_pos = findMin();
		mst[min_pos] = true;
		for(j = 0; j<V;j++){
			if(graph[min_pos][j] && mst[j] == false && graph[min_pos][j] <key[j]){
				key[j] = graph[min_pos][j];
				parent[j] = min_pos;
			}
		}
	}
	printMST();
}








int main()
{
   /* Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */
   int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
 
    // Print the solution
    primMST(graph);
 
    return 0;
}
