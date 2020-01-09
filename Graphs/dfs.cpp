#include <iostream>
#include <list>
using namespace std;



class Graph
{
	private:
		int v;
		list<int> *adj_list;
		bool *visited;
	public:
		Graph(int v);
		void display();
		void addEdge(int a, int b);
		void dfs(int start);
};

Graph::Graph(int v){

	this->v = v;
	adj_list = new list<int>[v];
	visited = new bool[v];
	for (int i = 0; i < v; i++)
	{
    	visited[i] = false;
	}
}
	
void Graph::addEdge(int a,int b){
	adj_list[a].push_back(b);
}

void Graph::display(){
	list<int>::iterator i;

	for(int j =0;j < this->v; j++){

		cout<<j<<":";
		for(i = this->adj_list[j].begin(); i != this->adj_list[j].end(); ++i ){

			cout<<*i<<" ";

		}

		cout<<endl;
	}

}


void Graph::dfs(int start){
	
	this->visited[start] = 1;
	list<int>::iterator i;
	cout<<start<<" ";
	for(i = this->adj_list[start].begin(); i != this->adj_list[start].end(); ++i){
		if(this->visited[*i] == 0){ 
			dfs(*i);
			}
		}
	
	return;

	}




int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n"; 
    
    //g.display();
    g.dfs(2); 
  
    return 0; 
} 