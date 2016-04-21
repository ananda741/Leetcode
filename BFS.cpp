#include<iostream>
#include<queue>
#include<map>
#include<list>
using namespace std;

class graph{
	int V;
	list<int> *adj;
	public:
		graph(int v);
		void addEdge(int v,int w);
		void BFS(int v);
};

graph::graph(int v){
	V = v;
	adj = new list<int>[v];
}

void graph::addEdge(int v,int w){
	adj[v].push_back(w);
}

void graph::BFS(int v){
	queue<int> laser;
	map<int,bool> visited;
	laser.push(v);
	visited[v] = true;
	cout<<v<<" ";

        while(!laser.empty()){
		int vivek = laser.front();
		laser.pop();
		list<int>::iterator i;
		for(i = adj[vivek].begin();i!=adj[vivek].end();i++){
			if(!visited[*i]){
				visited[*i] = true;
				laser.push(*i);
				cout<<*i<<" ";
			}
		}	
	}
}


int main(){
	graph g(5);
	g.addEdge(0,1);
	g.addEdge(0,3);
	g.addEdge(1,0);
	g.addEdge(1,3);
	g.addEdge(1,4);
	g.addEdge(1,2);
	g.addEdge(2,1);
	g.addEdge(2,4);
	g.addEdge(2,3);
	g.addEdge(3,1);
	g.addEdge(3,2);	
	g.addEdge(3,0);
	g.addEdge(4,1);
	g.addEdge(4,2);
	g.BFS(0);
}
