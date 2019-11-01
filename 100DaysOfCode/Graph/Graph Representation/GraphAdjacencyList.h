#ifndef GRAPHADJACENCYLIST_H
#define GRAPHADJACENCYLIST_H
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph{
    int V;
    //Array of Linked List of size V.
    //There are V Linked List;
    list<int> *adjList;
public:
    Graph(int v){
        V = v;
        adjList = new list<int>[V];
    }

    void addEdge(int u, int v, bool  bidirec=true){
        adjList[u].push_back(v);
        if(bidirec){
            adjList[v].push_back(u);
        }
    }

    void printAdjList(){
        list<int> :: iterator it;
        for(int i=0; i<V; i++){
            cout<<i <<"-->";
            for(it = adjList->begin(); it != adjList->end(); i++)
                cout<<*it;
            cout << endl;
        }
    }


};

#endif // GRAPHADJACENCYLIST_H
