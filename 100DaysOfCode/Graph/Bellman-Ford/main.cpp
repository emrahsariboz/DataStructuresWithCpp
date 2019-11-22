#include <iostream>
using namespace std;

struct Edge{
    int source, weight, destination;
};


struct Graph{
    int V, E;

    struct Edge *edge;

};

struct Graph *createGraph(int V, int E){
    Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];

    return graph;
}

void printArr(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

void BellmanFord(struct Graph *graph, int src){
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    for(int i=0; i<V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for(int i=1; i<= V-1; i++){
        for(int j=0; j<E; j++){
            int u = graph->edge[j].source;
            int v= graph->edge[j].destination;
            int weight = graph->edge[j].weight;

            if(dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;

        }
    }

    //Checking for negative cycles

    for(int i=0; i<E; i++){
        int u = graph->edge[i].source;
        int v = graph->edge[i].destination;
        int weight = graph->edge[i].weight;

        if(dist[u] != INT_MAX && dist[u] + weight < dist[v]){
            printf("GRAPH CONTAINS NEGATIVE CYCLE");
            return;
        }
    }
    printArr(dist, V);

    return;

}


int main(int argc, char *argv[])
{

    int V = 5;

    int E = 8;

    Graph *graph = createGraph(V,E);

    graph->edge[0].source = 0;
    graph->edge[0].destination = 1;
    graph->edge[0].weight = -1;

    graph->edge[1].source = 0;
    graph->edge[1].destination = 2;
    graph->edge[1].weight = 4;

    graph->edge[2].source = 1;
    graph->edge[2].destination = 2;
    graph->edge[2].weight = 3;

    graph->edge[3].source = 1;
    graph->edge[3].destination = 3;
    graph->edge[3].weight = 2;

    graph->edge[4].source = 1;
    graph->edge[4].destination = 4;
    graph->edge[4].weight = 2;

    graph->edge[5].source = 3;
    graph->edge[5].destination = 2;
    graph->edge[5].weight = 5;

    graph->edge[6].source = 3;
    graph->edge[6].destination = 1;
    graph->edge[6].weight = 1;

    graph->edge[7].source = 4;
    graph->edge[7].destination = 3;
    graph->edge[7].weight = -3;




    BellmanFord(graph, 0);





    return 0;
}
