#include <iostream>
#include <vector>
#include <list>
#include <utility>
using namespace std;

int main()
{

    //Creating vectors of linked list
    vector<list<int>> linkedListVector(4);

    linkedListVector[0].push_back(10);
    linkedListVector[1].push_back(20);
    linkedListVector[1].push_back(30);
    linkedListVector[2].push_back(30);
    linkedListVector[3].push_back(30);

    //Printing the vectors of linked list
    //It basically prints a hash map

    for(int i=0; i<linkedListVector.size(); i++){
        cout<<i <<"-->";
        for(list<int>::iterator it = linkedListVector[i].begin();
            it!=linkedListVector[i].end(); it++)
            cout<<*it<<",";
        cout << endl;
    }



    return 0;
}
