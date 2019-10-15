#include <QCoreApplication>
#include "NodeQueue.h"

int main(int argc, char *argv[])
{
   NodeQueue q1;

   cout<<q1.isEmpty()<<endl;

   q1.enqueue(200);
   cout<<q1.isEmpty()<<endl;

   cout<< q1.peek() <<endl;
   cout<<q1.dequeue()<<endl;


    return 0;
}
