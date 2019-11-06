#include <iostream>
#include <vector>
#include <list>
using namespace std;

bool isEven(const int& val){
    return (val%2) == 0;
}

int main()
{
    int arr[5] = {1,2,3,4,5};

    list<int> list1;

    list1.insert(list1.begin(), arr, arr+5);
    //list1.assign({10,20,30});
    list1.push_back(5);
    list1.push_front(5);
    cout <<"Size : " << list1.size() << endl;

    list<int>::iterator it1 = list1.begin();

    advance(it1, 1);
    cout<<"2nd Index: " << *it1 << endl;
    it1 = list1.begin();
    list1.insert(it1, 8);

    list1.erase(list1.begin());
    it1 = list1.begin();
    list<int>::iterator it2 = list1.begin();

    advance(it2, 2);
    list1.erase(it1,it2);

    list1.pop_front();
    list1.pop_back();


    int arr2[6] = {10, 9, 8, 7, 6,6};
    list<int> list2;
    list2.insert(list2.begin(), arr2, arr2+6);
    list2.sort();
    list2.reverse();
    list2.unique();
    list2.remove(6);
    list2.remove_if(isEven);


    list1.merge(list2);


    cout<<endl;

    for(int i:list1)
        cout<<i<<" ";
    cout<<endl;

    for(int i:list2)
        cout<<i<<" ";
    cout<<endl;

    cout<<"VECTORS"<<endl;


	    vector<int> newV;

	    for(int i=1; i<10; i++)
	        newV.push_back(i);

	    cout<<newV.size()<<endl;
	    vector<int>::iterator newItr;

	    for(newItr =newV.begin(); newItr!=newV.end(); newItr++)
	            cout<<*newItr<< " ";

	    cout<<endl;
	    newItr = newV.begin();

	    advance(newItr, 3);

	    vector<int>::iterator newItr2 = newV.end();
	    cout<<"The end of the vector: " << *newItr2 << endl;
	    auto newItr3 = prev(newItr2,1);

	    cout<<"The first iterator points to: " << *newItr << endl;

    cout<<"The newItr3 points to : " << *newItr3<<endl;



    return 0;
}
