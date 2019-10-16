#include <iostream>
#include <queue.h>
using namespace std;




int main()
{
    Queue q(5);
    q.enqueue(100);

    q.enqueue(200);
    q.enqueue(123123);
    cout << q.dequeue()<<endl;
    cout << q.dequeue()<<endl;
    cout << q.dequeue()<<endl;
    cout << q.dequeue()<<endl;
    return 0;
}
