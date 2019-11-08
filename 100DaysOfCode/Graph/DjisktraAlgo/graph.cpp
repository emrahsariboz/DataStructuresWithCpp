#include "graph.h"

Graph::Graph(int V){
    this->V = V;
    adjList = new list<Node>[V];

}

void Graph::addEdge(int s, int d, int w){
    Node n;
    n.dest = d;
    n.weight = w;
    adjList[s].push_back(n);

}


void Graph::Djisktra(Graph g, int *distance, int *prev,  int start){
    int totalNodes = g.V;

    for(int i=0; i<totalNodes; i++){
        distance[i] = 9999;
        prev[i] = -1;
    }

    distance[start] = 0;
    set<int> S;
    list<int> Q;

    for(int i=0; i<totalNodes; i++){
        Q.push_back(i);
    }

    while(!Q.empty()){
        list<int> :: iterator i;
        i = min_element(Q.begin(), Q.end());
        int u = *i;

        Q.remove(u);
        S.insert(u);
        list<Node>::iterator it;

        for(it = g.adjList[u].begin(); it != g.adjList[u].end();it++) {
             if(  (distance[u] + it->weight) < distance[it->dest] )
                    distance[it->dest] = distance[u] + (it->weight);
                    prev[it->dest] = u;
        }

    }
}

void Graph::showList(int src, list<Node> listt){
    list<Node> :: iterator i;
             Node tempNode;

             for(i = listt.begin(); i != listt.end(); i++) {
                tempNode = *i;
                cout << "(" << src << ")---("<<tempNode.dest << "|"<<tempNode.weight<<") ";
             }
             cout << endl;
}

void Graph:: displayEdges() {
        for(int i = 0; i<V; i++) {
           list<Node> tempList = adjList[i];
           showList(i, tempList);
        }
     }
