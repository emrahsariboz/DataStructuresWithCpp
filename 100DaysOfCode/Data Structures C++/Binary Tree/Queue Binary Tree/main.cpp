#include <iostream>
#include <queue.h>
using namespace std;




int main()
{
    Queue q(5);
    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(123123);
    q.enqueue(999);

    q.Display(q);

    return 0;
}
