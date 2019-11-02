#ifndef GRAPHADJACENCYLIST_H
#define GRAPHADJACENCYLIST_H
#include <iostream>
#include <vector>
#include <list>
#include <queue>
static int time = 1;

using namespace std;

class Graph{
    int V = 10;
    //Array of Linked List of size V.
    //There are V Linked List;
    list<int> *adjList;
public:
    bool *visited = new bool[V]{0};
    int *pre = new int[V]{0};
    int *post = new int[V]{0};
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

    void dfs(int src){
        visited[src] = 1;
        pre[src] = time;
        time++;
        cout<<src << " ";

        list<int>::iterator i;

        for(i = adjList[src].begin(); i!= adjList[src].end(); i++)
            if(visited[*i] == 0)
                dfs(*i);
        post[src] = time;
        time++;
      }
};

#endif // GRAPHADJACENCYLIST_H
