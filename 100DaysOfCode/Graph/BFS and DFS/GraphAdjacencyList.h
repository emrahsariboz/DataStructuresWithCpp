#ifndef GRAPHADJACENCYLIST_H
#define GRAPHADJACENCYLIST_H
#include <iostream>
#include <vector>
#include <list>
#include <queue>
static int time = 0;

using namespace std;

class Graph{
    int V = 10;
    //Array of Linked List of size V.
    //There are V Linked List;
    list<int> *adjList;

public:
    int sinkNode;
    bool *visited = new bool[V]{0};
    bool *visited2 = new bool[V]{0};
    int *pre = new int[V]{0};
    int *post = new int[V]{0};
    Graph(int v){
        sinkNode = 0;
        V = v;
        adjList = new list<int>[V];

    }


    void addEdge(int u, int v, bool  bidirec=true){


        visited2[u] = 1;
        cout<<u << " : is visited"<<endl;

        adjList[u].push_back(v);
        if(bidirec){
            adjList[v].push_back(u);
        }

    }

    void sinkNodes(){
        for(int i=0; i<V; i++){
            if(visited2[i] == 1)
                sinkNode++;
        }


        cout<<"Total number of sink nodes in Graph: " << V - sinkNode << endl;
        cout<<"Total number of source nodes in Graph: " << sinkNode << endl;

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

     bool isCyclicUtil(int v, bool visited[], int parent)
     {
         // Mark the current node as visited
         visited[v] = true;

         // Recur for all the vertices adjacent to this vertex
         list<int>::iterator i;
         for (i = adjList[v].begin(); i != adjList[v].end(); ++i)
         {
             // If an adjacent is not visited, then recur for that adjacent
             if (!visited[*i])
             {
                if (isCyclicUtil(*i, visited, v))
                   return true;
             }
             // If an adjacent is visited and not parent of current vertex,
             // then there is a cycle.
             else if (*i != parent)
                return true;
         }
         return false;
     }

     // Returns true if the graph contains a cycle, else false.
     bool isCyclic()
     {
         // Mark all the vertices as not visited and not part of recursion
         // stack
         bool *visited = new bool[V];
         for (int i = 0; i < V; i++)
             visited[i] = false;

         // Call the recursive helper function to detect cycle in different
         // DFS trees
         for (int u = 0; u < V; u++)
             if (!visited[u]) // Don't recur for u if it is already visited
               if (isCyclicUtil(u, visited, -1))
                  return true;

         return false;
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
