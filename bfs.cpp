#include <iostream>
#include <list>
#include <queue>

class Graph{
	int n_vertices;
	std::list<int> *adj_list;
	bool* visited;
public:
	Graph(int vertices);
	void addEdge(int u, int v);
	void BFS(int u);
};

Graph::Graph(int vertices){
	n_vertices = vertices;
	adj_list = new std::list<int>[vertices];
}

void Graph::addEdge(int u, int v){
	adj_list[u].push_back(v);
	adj_list[v].push_back(u);
}

void Graph::BFS(int u){
	
	// Initialize visited array
	visited = new bool[n_vertices];
	for(int i=0; i<n_vertices; i++){
		visited[i] = false;
	}

	// Add first entry to the queue
	std::queue<int> queue;
	queue.push(u);
	visited[u] = 1;

	// Loop over the queue
	std::list<int>::iterator it;
	while(!queue.empty()){
		// Extract first element of the queue
		int current_vertex = queue.front();
		std::cout << "visited " << current_vertex << std::endl;
		queue.pop();

		// Loop over the neighboors of the vertex
		for(it = adj_list[current_vertex].begin(); it !=adj_list[current_vertex].end(); it++){
			if(!visited[*it]) {
				queue.push(*it);
				visited[*it] = true;
			}
		}
	}
}

int main(){
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(2,3);
	
	g.BFS(2);

	std::cout << "Done" << std::endl;
}
