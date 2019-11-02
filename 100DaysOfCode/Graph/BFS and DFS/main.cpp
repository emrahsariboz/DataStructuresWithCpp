#include <iostream>
//#include "GraphAdjacencyMatrix.h"
#include "GraphAdjacencyList.h"
//#include "GraphHashMap.h"

int main()
{
    /*
    simple_graph graph;

    graph.print_graph();

    graph.add_edge(1,3, 10);
    graph.add_edge(1,4,23);
    cout<<endl;
    graph.print_raph();
    */

    cout<<"BFS BELOW " << endl;
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 4);
    g.addEdge(2,4);
    g.addEdge(3,2);
    g.addEdge(2,3);
    g.addEdge(3,5);

    g.printAdjList();
    //start index 0
    g.bfs(0);

    cout<<"DFS BELOW " << endl;

    Graph forDFS(4);
    forDFS.addEdge(0, 1);
    forDFS.addEdge(0, 2);
    forDFS.addEdge(1, 2);
    forDFS.addEdge(2, 3);
    forDFS.addEdge(3, 3);


    forDFS.dfsHelper(2);

/*
    Graph<string> g;
    g.addEdge("Texas", "New Mexico");
    g.addEdge("Texas", "Oklahama");
    g.addEdge("Texas", "New Orleans");
    g.addEdge("New Mexico", "Colorado");
    g.addEdge("New Mexico", "Arizona");

    g.printAdjList();
    */
    return 0;
}
