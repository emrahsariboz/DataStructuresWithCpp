#ifndef SIMPLEGRAPH_H
#define SIMPLEGRAPH_H
#include <iostream>
using namespace std;
class simple_graph{
    int **vertex_matrix;
    int num_of_vertices, num_of_edges;
public:
    simple_graph(int _num_of_vertices = 10){
        num_of_vertices = _num_of_vertices;
        num_of_edges = 0;
        vertex_matrix = new int*[_num_of_vertices];
        for(int i=0; i<_num_of_vertices; i++){
            vertex_matrix[i] = new int[_num_of_vertices];
        }

        for(int i=0; i<num_of_vertices; i++){
            for(int j=0; j<num_of_vertices; j++){
                vertex_matrix[i][j] = INT_MAX;
            }
        }
    }
    ~simple_graph(){
        for(int i=0; i<num_of_vertices; i++){
            delete[] vertex_matrix[i];
        }

        delete[] vertex_matrix;
    }

    void add_edge(int v1, int v2,int weight){
        if(vertex_matrix[v1-1][v2-1]== INT_MAX)
            num_of_edges++;
        vertex_matrix[v1-1][v2-1] = weight;
    }
    void del_edge(int v1, int v2){
        if(vertex_matrix[v1-1][v2-1] != INT_MAX)
            num_of_edges--;
        vertex_matrix[v1-1][v2-1] = INT_MAX;
    }

    void print_graph(){
        for(int i=0; i<num_of_vertices; i++){
            for(int j=0; j<num_of_vertices; j++){
                if(vertex_matrix[i][j] != INT_MAX){
                    cout<<vertex_matrix[i][j];
                }else{
                    cout<<"I";
                }
                cout<<" " ;
            }
            cout<<endl;
        }
    }

};


#endif // SIMPLEGRAPH_H
