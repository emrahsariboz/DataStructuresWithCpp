#include<iostream>
#include <list>
#include <limits.h>

using namespace std;

class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    bool isCyclicUtil(int v, bool visited[], bool *rs);  // used by isCyclic()
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    bool isCyclic();    // returns true if there is a cycle in this graph
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}


bool Graph::isCyclicUtil(int v, bool *visited, bool *rs){

    if(visited[v] == false){
        visited[v] = true;
        rs[v] = true;

        list<int>::iterator i;

        for(i = adj[v].begin(); i!=adj[v].end(); i++){
            if(!visited[*i] && isCyclicUtil(*i, visited, rs))
                    return true;
            else if(rs[*i])
                return true;
        }
    }

    rs[v] = false;
    return false;

}


bool Graph::isCyclic(){
    bool *visited = new bool[V];
    bool *recStack = new bool[V];

    for(int i=0; i<V; i++){
        visited[i] = false;
        recStack[i] =false;
    }

    for(int i=0; i<V;i++)
        if(isCyclicUtil(i, visited, recStack))
            return true;

    return false;
}


int main()
{
    // Create a graph given in the above diagram
    Graph g(3);
    g.addEdge(0, 1);
    g.addEdge(0, 2);


    if(g.isCyclic())
        cout << "Graph contains cycle\n";
    else
        cout << "Graph doesn't contain cycle\n";
    return 0;
}
