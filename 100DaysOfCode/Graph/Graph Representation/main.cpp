#include <iostream>
#include "GraphAdjacencyMatrix.h"
#include "GraphAdjacencyList.h"
#include "GraphHashMap.h"

int main()
{
    /*
    simple_graph graph;

    graph.print_graph();

    graph.add_edge(1,3, 10);
    graph.add_edge(1,4,23);
    cout<<endl;
    graph.print_graph();
    */
/*
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(3, 2);


    g.printAdjList();
*/
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(3, 2);


    return 0;
}
