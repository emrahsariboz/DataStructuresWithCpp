#include <QCoreApplication>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main()
{

    bool palindrome = true;

    char character;
    char stackChar;
    char queueChar;

    stack <char> s;
    queue<char> q;

    cout << "Enter a string; " <<endl;
    cin.get(character);

    while (character != '\n') {
        s.push(character);
        q.push(character);
        cin.get(character);
    }

    while(palindrome && !q.empty()){
        stackChar = s.top();
        s.pop();
        queueChar = q.front();
        q.pop();

        if(stackChar != queueChar)
            palindrome = false;
    }


    if(palindrome)
        cout<<"Palindrome"<<endl;
    else
        cout<<"Not palindrome"<<endl;
    return 0;
}
