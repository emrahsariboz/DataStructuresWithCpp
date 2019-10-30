#include <QCoreApplication>
#include <iostream>
#define SIZE 10


using namespace std;

int hashH(int k){
    return k%SIZE;
}

int probe(int H[], int k){
    int index = hashH(k);

    int i=0;
    while(H[index+(i*i)] % SIZE != 0)
        i++;

    return (index+(i*i)) % SIZE;
}

void Insert(int H[], int k){
    int index = hashH(k);
    if(H[index] != 0){
         index = probe(H, k);
    }

    H[index] = k;
}

int Search(int H[],int k){
    int index = hashH(k);

    int i=0;
    while(H[ (index + (i*i)) % SIZE] != k && H[index] != 0){
        if(H[ (index + (i*i)) % SIZE] == k){
            return index;
        }
        i++;
    }

    index=-1;
    return index;

}


int main()
{
   int HT[10] = {0};

   Insert(HT, 23);
   Insert(HT, 13);
   Insert(HT, 43);

   Insert(HT, 42);

   cout << "Item found at " << Search(HT, 43) << endl;

    return 0;
}
