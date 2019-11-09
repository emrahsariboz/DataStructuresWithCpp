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
        AdjListNode node = *itr;
        if(!visited[node.vertexNum])
            topologicalSortUtil(node.vertexNum, visited, Stack);
    }

    Stack.push(v);
}


void Graph::shortestPath(int s){
    stack<int> Stack;
    int dist[V];

    bool *visited = new bool[V]{false};

    for (int i = 0; i < V; i++)
            if (visited[i] == false)
                topologicalSortUtil(i, visited, Stack);


    for(int i=0; i<V; i++)
        dist[i] = INF;

    dist[s] = 0;


    while(!Stack.empty()){
        int u = Stack.top();
        Stack.pop();

        list<AdjListNode>::iterator i;

        if(dist[u] != INF){

            for(i = adj[u].begin(); i!=adj[u].end(); i++)
                if(dist[i->vertexNum] > dist[u] + i->weight)
                    dist[i->vertexNum] = dist[u] + i->weight;
        }
    }


    for(int i=0; i<V; i++)
         (dist[i] == INF) ? cout<< "INF ": cout<<dist[i] << " ";

}
