#include <iostream>
#include <stack> 
#include <list>
using namespace std;

class Graph{
	private:

		int v;
		list<int> *adj_list;
		stack<int> visited_nodes;
		bool *visited;


	public:
		Graph(int v);
		void dfs(int start);
		void topsort(int arr[]);
		void addEdge(int,int);

};

Graph::Graph(int v){
	this->v = v;
	adj_list = new list<int>[v];
	visited = new bool[v];

	for(int i=0; i<v; i++){
		visited[i] = false;
	}
}

void Graph::addEdge(int a,int b){
	adj_list[a].push_back(b);
}

void Graph::dfs(int start){
	
	this->visited[start] = true;
	this->visited_nodes.push(start);
	list<int>::iterator i;

	for(i = adj_list[start].begin(); i!=adj_list[start].end();++i){
		if(this->visited[*i] == 0){
			dfs(*i);
		}
	}
	return;
}

void Graph::topsort(int order_arr[]){
	int j = (this->v) -1;
	for(int i= 0; i<v;i++){
		if(this->visited[i] == true){
			continue;
		}

		dfs(i);
		while(!visited_nodes.empty()){
			order_arr[j] = visited_nodes.top();
			visited_nodes.pop();
			j--;
		}

	}
}


int main(int argc, char const *argv[])
{
	Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  	

  	int order[6]={0,0,0,0,0,0};
  	g.topsort(order);

  	for(int i =0; i<6;i++){
  		cout<<order[i]<<" ";
  	}
	return 0;
}