#include <QCoreApplication>
#include "TopologicalSort.h"
int main()
{

    cout<<"DFS BELOW " << endl;

    Graph forDFS(6);
    forDFS.addEdge(0, 1);
    forDFS.addEdge(0, 2);
    forDFS.addEdge(2, 4);
    forDFS.addEdge(1, 3);
    forDFS.addEdge(4, 5);


    forDFS.printAdjList();

    forDFS.dfs(0);

    cout<<endl;
    for(int i=0; i<6; i++){
        cout<< "Node: " << i << " Pre number "
                                       << forDFS.pre[i] << " Post number " << forDFS.post[i] << endl;
    }


    forDFS.topologicalSortUtil();


    return 0;
}
