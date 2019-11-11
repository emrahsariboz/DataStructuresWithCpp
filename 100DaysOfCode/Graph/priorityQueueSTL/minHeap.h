#ifndef MINHEAP_H
#define MINHEAP_H

#include <queue>
#include <iostream>
using namespace std;

void showpq(priority_queue<int, vector<int>, greater<int>> minH){
    priority_queue<int, vector<int>, greater<int>> minHeap = minH;

    while(!minHeap.empty()){
        cout<<"\t" <<minHeap.top();
        minHeap.pop();
    }
    cout << '\n';
}



#endif // MINHEAP_H
