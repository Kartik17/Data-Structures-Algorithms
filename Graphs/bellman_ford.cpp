#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
struct Edge
{
	int src;
	int dst;
	int weight;
};

struct Graph
{
	int V,E;
	struct Edge* edges;

};

struct Graph create_graph(int V, int E){

	 struct Graph graph;
	 graph.V = V;
	 graph.E = E;
	 graph.edges = new Edge[E];

	 return graph;

}

void bellman_ford(struct Graph graph, int src){
	 
	int V = graph.V;
	int E = graph.E;

	int* distance = new int[V];
	bool* neg_cycle = new bool[V];
	for(int i =0; i< V;i++){
		distance[i] = INT_MAX;
		neg_cycle[i] = false;
	}
	distance[src] = 0;


	for(int i=0;i<V-1;i++){
		for(int j=0;j<E;j++){
			
			int u = graph.edges[j].src;
			int v = graph.edges[j].dst;
			//cout<<u<<" "<<v<<" "<<distance[u]<<" "<<graph.edges[j].weight<<endl;
			if(distance[u] != INT_MAX){
				if(distance[u] + graph.edges[j].weight < distance[v]){
					distance[v] = distance[u] + graph.edges[j].weight;
									
				}
			}
		}
	}
	for(int i = 0;i<V;i++){
		cout<<distance[i]<<" "<<neg_cycle[i]<<endl;
	}
	for(int i=0;i<V-1;i++){
		for(int j=0;j<E;j++){
			
			int u = graph.edges[j].src;
			int v = graph.edges[j].dst;
			if(distance[u] + graph.edges[j].weight < distance[v]){
				neg_cycle[v] = true;
									
				}
			
		}
	}

	for(int i = 0;i<V;i++){
		cout<<distance[i]<<" "<<neg_cycle[i]<<endl;
	}

}

int main(int argc, char const *argv[])
{
	int V = 5;
	int E = 8;

	Graph graph = create_graph(V,E);

	graph.edges[0].src = 0; 
    graph.edges[0].dst = 1; 
    graph.edges[0].weight = -1; 
  
    // add edge 0-2 (or A-C in above figure) 
    graph.edges[1].src = 0; 
    graph.edges[1].dst = 2; 
    graph.edges[1].weight = 4; 
  
    // add edge 1-2 (or B-C in above figure) 
    graph.edges[2].src = 1; 
    graph.edges[2].dst = 2; 
    graph.edges[2].weight = 3; 
  
    // add edge 1-3 (or B-D in above figure) 
    graph.edges[3].src = 1; 
    graph.edges[3].dst = 3; 
    graph.edges[3].weight = 2; 
  
    // add edge 1-4 (or A-E in above figure) 
    graph.edges[4].src = 1; 
    graph.edges[4].dst = 4; 
    graph.edges[4].weight = 2; 
  
    // add edge 3-2 (or D-C in above figure) 
    graph.edges[5].src = 3; 
    graph.edges[5].dst = 2; 
    graph.edges[5].weight = 5; 
  
    // add edge 3-1 (or D-B in above figure) 
    graph.edges[6].src = 3; 
    graph.edges[6].dst = 1; 
    graph.edges[6].weight = 1; 
  
    // add edge 4-3 (or E-D in above figure) 
    graph.edges[7].src = 4; 
    graph.edges[7].dst = 3; 
    graph.edges[7].weight = -3; 

    bellman_ford(graph,0);

	return 0;
}
