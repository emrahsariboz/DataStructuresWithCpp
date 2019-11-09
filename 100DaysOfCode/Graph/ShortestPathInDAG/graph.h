#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <stack>
#include <list>

using namespace std;

class AdjListNode{
public:
    int V;
    int weight;
    AdjListNode(int V, int weight){
        this->V = V;
        this->weight = weight;
    }
};


class Graph
{   
public:
    int V;

    list<AdjListNode> *adj;
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
    void shortestPath(int s);
    void addEdge(int source, int destionation, int weight);

    Graph(int V);
};

#endif // GRAPH_H
