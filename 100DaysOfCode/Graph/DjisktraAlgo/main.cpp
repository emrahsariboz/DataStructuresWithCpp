#include <QCoreApplication>
#include "graph.h"

int main()
{
    int n = 7;

    Graph g(n);

    int dist[n], prev[n];

    int start = 0;

       g.addEdge(0, 1, 3);
       g.addEdge(0, 2, 6);

       g.addEdge(1, 3, 1);
       g.addEdge(2, 1, 6);

       g.addEdge(2, 3, 1);
       g.addEdge(2, 4, 4);

       g.addEdge(2, 5, 2);

       g.addEdge(3, 4, 2);
       g.addEdge(3, 6, 4);

       g.addEdge(4, 5, 2);

       g.addEdge(4, 6, 1);


       g.addEdge(5, 6, 1);

       g.Djisktra(g, dist, prev, start);

       for(int i = 0; i<n; i++)
             if(i != start)
                cout<<start<<" to "<<i<<", Cost: "<<dist[i]<<" Previous: "<<prev[i]<<endl;

       return 0;
}
