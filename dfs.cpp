#include <iostream>
#include <list>
#include <stack>

class Graph{
	int vertices;
	std::list<int> *adjList;
public:
	Graph(int n_vertices);
	~Graph();
	int addEdge(int u, int v);
	void DFS(int u);

};

int Graph::addEdge(int u, int v){
	adjList[u].push_back(v);
	adjList[v].push_back(u);
}

Graph::Graph(int n_vertices){
	vertices = n_vertices;
	adjList = new std::list<int>[vertices];
}

/*
 * Compare to BFS
 *
 * - It uses a stack instead of a queue
 * - The DFS should mark discovered only 
 *   after popping the vertex not before pushing it.
 *
 *
 */
void Graph::DFS(int u){
	// Init visited array
	bool visited[vertices];
	for(int i=0; i<vertices; i++){
		visited[i] = false;
	}

	// Create stack
	std::stack<int> stack;
	stack.push(u);
	//visited[u] = true; NO!

	// Graph traversal
	std::list<int>::iterator itr;
	while(!stack.empty()){
		int v = stack.top();
		stack.pop();

		if(!visited[v]){
			visited[v]=true;
			std::cout << "Vertex " << v << std::endl;
		}

		for(itr = adjList[v].begin(); itr!=adjList[v].end(); itr++){
			if(!visited[*itr]){
				stack.push(*itr);
				//visited[*itr] = true; NO!
			}

		}
	}
}

Graph::~Graph(){
	delete[] adjList;
}

int main(){
	// Create graph
	Graph g(3);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(0,1);

	g.DFS(0);

}
