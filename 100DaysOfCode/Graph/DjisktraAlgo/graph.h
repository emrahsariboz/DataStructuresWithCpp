#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <set>

using namespace std;

class Node{
public:
    int dest;
    int weight;

};

class Graph{
public:
    int V = 10;
    list<Node> *adjList;
    int weight;
    Graph(int V);

    void addEdge(int source, int destionation, int weight);
    void displayEdges();

    void Djisktra(Graph g, int *dest, int *prev,  int start);
    void showList(int src, list<Node> listt);
};

#endif // GRAPH_H
