#include "graph.h"

int main()
{
    Graph g(6);

     g.addEdge(0, 1, 5);
     g.addEdge(0, 2, 3);
     g.addEdge(1, 3, 6);
     g.addEdge(1, 2, 2);
     g.addEdge(2, 4, 4);
     g.addEdge(2, 5, 2);
     g.addEdge(2, 3, 7);
     g.addEdge(3, 4, 1);

     cout<<"Shortest paths from vertext: " << 0 << endl;

     g.shortestPath(0);

    return 0;
}
