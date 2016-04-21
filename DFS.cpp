#include<iostream>
#include<list>
#include<stack>
#include<map>
using namespace std;

class graph{
	int V;
	list<int> *adj;
	public:
		graph(int v);
		void addEdge(int v,int w);
		void DFS(int v);
};

graph::graph(int v){
	V = v;
	adj = new list<int>[v];
}

void graph::addEdge(int v,int w){
	adj[v].push_back(w);
}

void graph::DFS(int v){
	stack<int> laser;
	map<int,bool> visited;
	laser.push(v);
	cout<<v<<" ";
	visited[v] = true;
	
	while(!laser.empty()){
		int vivek = laser.top();
		int flag = 0;
		list<int>::iterator i;
		for(i = adj[vivek].begin();i!=adj[vivek].end();i++){
			if(!visited[*i]){
				visited[*i] = true;
				laser.push(*i);
				cout<<*i<<" ";
				flag = 1;
				break;
			}
			else{
				flag = 2;
				break;
			}
		}
		if(flag == 0){
			laser.pop();
		}
		if(flag == 2){
			cout<<"Graph contains cycle\n";
			break;
		}
	}
}

int main(){
    graph g(4);
    g.addEdge(0, 1);
    //g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    //g.addEdge(3, 3);
    g.DFS(2);
}

