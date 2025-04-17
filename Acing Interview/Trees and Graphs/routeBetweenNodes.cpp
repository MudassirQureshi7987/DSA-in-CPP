#include <vector>
#include <iostream>
#include <queue>
using namespace std;

// Graph Class implementing a directed graph in adjacency list representation
class Graph
{
public:
	int V;	// number of vertices
	vector<int> *adj;  //adjacency list 

	Graph(int V);
	void addEdge(int x, int y);
	bool isRoute(int x, int y);
};

// Constructor
Graph::Graph(int V)
{
	this->V=V;
	this->adj = new vector<int>[V];
}

// add a directed edge from x to y
void Graph::addEdge(int x, int y){
	adj[x].push_back(y);
}

// isRoute function to determine if there is a route from x to y
bool Graph::isRoute(int x, int y){
    vector<int> vis(V,0);

    queue<int> q;
    q.push(x);

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        if(front == y)
        {
            return true;
        }

        for(auto neighbour : adj[front])
        {
            if(!vis[neighbour])
            {
                q.push(neighbour);
                vis[neighbour] = 1;
            }
        }
    }

    return false;
}

int main(){
	
    Graph g(6);	
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

/*	
	Test graph :

	0 <---4---->1
	^ 			^
	|			|
	|			|
    5---->2---->3 

*/
    cout<<g.isRoute(5,4)<<endl; // false
    cout<<g.isRoute(5,1)<<endl; // true

    return 0;
}