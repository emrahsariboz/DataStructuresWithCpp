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

    while(H[index+i] % SIZE != 0)
        i ++;


    return (index+i) % SIZE;
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


    while(H[index] == k || H[index] != 0){
        if(H[index] == k){
            return index;
        }
        index = (index+1) % 10;
    }
    index  = -1;
    return index;

}


int main()
{
   int HT[10] = {0};

   Insert(HT, 12);
   Insert(HT, 25);
   Insert(HT, 35);
   Insert(HT, 26);

   cout << "Item found at " << Search(HT, 35) << endl;

    return 0;
}
