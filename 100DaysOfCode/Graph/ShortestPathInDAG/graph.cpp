#include "graph.h"

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<AdjListNode>[V];

}

void Graph::addEdge(int source, int destionation, int weight){
    AdjListNode newNode(destionation, weight);
    adj[source].push_back(newNode);

}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack){
    visited[v] = true;

    list<AdjListNode>::iterator itr;

    for(itr = adj[v].begin(); itr != adj[v].end(); itr++){
        if(!visited[*itr])
            topologicalSortUtil(*itr, visited, Stack);

    }
}

