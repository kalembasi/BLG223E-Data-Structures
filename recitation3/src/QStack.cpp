#include <iostream>
#include <queue>
#include <QStack.h>


using namespace std;

void QStack::push(int x)
{
    //Fill this method
    int s = main.size();
    main.push(x);
    for(int i=0; i<s; i++){
        main.push(main.front());
        main.pop();
    }
}

void QStack::pop()
{
    //Fill this method
    if(main.empty())
        cout << "Stack is empty" << endl;
    else{
        int x = main.front();
        main.pop();
        cout << x << " is popped" << endl;
    }
}

void QStack::printStack()
{
    if (main.empty())
        return;

    int x;
    for(unsigned long int i=0;i<main.size();i++)
    {
        x = main.front();
        main.pop();
        cout << x << ' ';
        main.push(x);
    }
}