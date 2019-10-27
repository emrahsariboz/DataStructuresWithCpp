#include <QCoreApplication>
#include "priorityqueueadt.h"
int main()
{
    PriorityQueueAdt prioritQ(6);

    prioritQ.enqueue(20);
    prioritQ.enqueue(30);
    prioritQ.enqueue(40);
    prioritQ.enqueue(50);
    prioritQ.enqueue(60);
    prioritQ.enqueue(70);


    prioritQ.printQueue();

    cout<<"Dequeu Opereration on Highest Priority: " << prioritQ.dequeue()<<endl;
    prioritQ.printQueue();

    return 0;
}
