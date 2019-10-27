#include <QCoreApplication>
#include "priorityqueueadt.h"
int main()
{
    PriorityQueueAdt prioritQ(6);

    prioritQ.enqueue(10);
    prioritQ.enqueue(60);
    prioritQ.enqueue(5);
    prioritQ.enqueue(50);
    prioritQ.enqueue(40);
    prioritQ.enqueue(70);


    prioritQ.printQueue();

    cout<<"Dequeu Opereration on Highest Priority: " << prioritQ.dequeueShiftMethod()<<endl;
    prioritQ.printQueue();

    return 0;
}
