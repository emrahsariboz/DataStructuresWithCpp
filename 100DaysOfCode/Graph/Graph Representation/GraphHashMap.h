#ifndef GRAPHHASHMAP_H
#define GRAPHHASHMAP_H
#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

template<typename T>
class Graph{

    unordered_map<T, list<T>> adjList;

public:
    Graph(){

    }

    void addEdge(int u, int v, bool bidir){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto row:adjList){
            T key = row.first;
            cout<<key << "-->";

            for(T element:row.second){
                cout<<element<<",";
            }
            cout<<endl;
        }
    }
};


#endif // GRAPHHASHMAP_H
