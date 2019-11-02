#ifndef GRAPHADJACENCYLIST_H
#define GRAPHADJACENCYLIST_H
#include <iostream>
#include <vector>
#include <list>
#include <queue>
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
            for(int node:adjList[i])
                cout<<node<<",";
            cout << endl;
        }
    }

    void bfs(int src){
        queue<int> q;
        bool *visited = new bool[V]{0};
        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            int node = q.front();
            cout<<node << " " ;
            q.pop();
            for(int neighbour:adjList[node]){
                if(!visited[neighbour])
                    q.push(neighbour);
                    visited[neighbour] = true;
            }
        }

    }

    void dfsHelper(int src){
        bool *visited = new bool[V]{0};

        dfs(src, visited);
    }

    void dfs(int src, bool visited[]){

            visited[src] = 1;
            cout<<src << " ";


        list<int>::iterator i;

        for(i = adjList[src].begin(); i!= adjList[src].end(); i++)
            if(visited[*i] == 0)
                dfs(*i, visited);


    }


};

#endif // GRAPHADJACENCYLIST_H
