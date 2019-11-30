#include <iostream>

using namespace std;

int majorityElement(int A[], int size){

      int maj_index = 0, count = 1;

      for(int i= 1; i<size; i++){

          if(A[maj_index] == A[i])
              count++;
          else
              count--;

          if(count == 0){
              maj_index = i;
              count = 1;
          }
      }
    return A[maj_index];
}

bool isMajority(int A[], int size, int majorityElement){
    int count = 0;
    for(int i=0; i<size; i++){
          if(A[i] == majorityElement)
              count++;
    }

    if(count>=(size/2))
        return true;



    return false;

}


int main()
{
    int a[] = {1, 3, 1, 1, 2};
    int size = (sizeof(a))/sizeof(a[0]);

    int majorityE = majorityElement(a, size);
    cout<<majorityE<<endl;
    if(isMajority(a, size, majorityE))
         cout<<"The majority element is: " << majorityE<<endl;
    else
        cout<<"There isn't majority element"<<endl;

    return 0;
}
