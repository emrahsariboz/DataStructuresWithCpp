#include <iostream>
#include <QCoreApplication>
#include <queue>
#include "minHeap.h"


using namespace std;


void showpq(priority_queue<int> pq){
    priority_queue<int> g = pq;
    while(!g.empty()){
        cout<<'\t'<<g.top();
        g.pop();
    }
    cout<<'\n';
}

int main()
{
    priority_queue <int> gquiz;

    gquiz.push(10);
    gquiz.push(1000);

    gquiz.push(990);
    gquiz.push(50);
    gquiz.push(14);

    cout<<"The priority queue is: " ;
    showpq(gquiz);

    cout<<"Size : " << gquiz.size()<<endl;
    cout<<"Top : " << gquiz.top() << endl;

    gquiz.pop();
    showpq(gquiz);


    cout<<"**********MINHEAP*******"<<endl;

    priority_queue<int, vector<int>, greater<int>> minHeapP;

    minHeapP.push(25);
    minHeapP.push(15);
    minHeapP.push(35);
    minHeapP.push(22);
    minHeapP.push(188);

    cout<<"The priority queue : \n";
    showpq(minHeapP);

    cout<<"Size : " << minHeapP.size()<<endl;
    cout<<"Top : " << minHeapP.top() << endl;

    minHeapP.pop();
    showpq(minHeapP);




    return 0;
}
