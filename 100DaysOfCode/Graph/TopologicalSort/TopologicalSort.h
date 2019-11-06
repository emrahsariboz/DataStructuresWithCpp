#ifndef TOPOLOGICALSORT_H
#define TOPOLOGICALSORT_H
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>

static int timeT = 0;

using namespace std;

class Graph{
    int V = 10;
    //Array of Linked List of size V.
    //There are V Linked List;
    list<int> *adjList;
    vector<int> *transpose;
public:
    int sinkNode;
    bool *visited = new bool[V]{0};
    int *pre = new int[V]{0};
    int *post = new int[V]{0};
    Graph(int v){
        sinkNode = 0;
        V = v;
        adjList = new list<int>[V];
        transpose = new vector<int>[V];
    }

    void addEdge(int u, int v, bool  bidirec=true){

        cout<<u << " : is visited"<<endl;

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
    void dfs(int src){
        visited[src] = 1;
        pre[src] = timeT;
        timeT++;
        cout<<src << " ";

        list<int>::iterator i;

        for(i = adjList[src].begin(); i!= adjList[src].end(); i++)
            if(visited[*i] == 0)
                dfs(*i);
        post[src] = timeT;
        timeT++;
      }

    void topologicalSort(int src, stack<int> &stack, bool visitedN[]){
        visitedN[src] = true;
        list<int>::iterator i;

        for(i = adjList[src].begin(); i!=adjList[src].end(); i++){
            if(!visitedN[*i])
                topologicalSort(*i, stack, visitedN);
        }

        stack.push(src);

    }

    void topologicalSortUtil(){
        stack<int> TPstack;
        bool *visitedN = new bool[V]{false};

        for(int i=0; i <V; i++)
            if(visitedN[i] != true)
                topologicalSort(i, TPstack, visitedN);


        cout<<"Topological order" << endl;
        while (!TPstack.empty()) {
            cout<<TPstack.top()<<" ";
            TPstack.pop();
        }
        cout<<endl;
    }

        void transposeGraph(){
            for(int i=0; i<V; i++){
                    for(int node:adjList[i]){
                        transpose[node].push_back(i);
                }
            }

          printTranspose();
        }

    void printTranspose(){
        cout<<"Transpose of the Graph"<<endl;
        for(int i=0; i<V; i++){
            cout<<i <<"-->";
            for(int node:transpose[i])
                cout<<node<<",";
            cout << endl;
        }

    }

};

#endif // TOPOLOGICALSORT_H


