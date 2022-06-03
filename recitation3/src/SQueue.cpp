#include <iostream>
#include <stack>
#include <SQueue.h>


using namespace std;

void SQueue::enqueue(int x)
{
    //Fill this method
    if(!main.empty()){
        while(!main.empty()){
            temp.push(main.top());
            main.pop();
        }
    }  
    main.push(x);
    while(!temp.empty()){
        main.push(temp.top());   
        temp.pop();
    }
}

void SQueue::dequeue()
{
    int x;
    //Fill this method
    if(main.empty()){
        cout << "Queue is empty" << endl;
    }else{
        x = main.top();
        main.pop();
        cout << x << " is dequeued" << endl;
    }
}

void SQueue::printQueue()
{
    if (main.empty())
        return;

    int x = main.top();
    main.pop();
    cout << x << ' ';
    printQueue();
    main.push(x);
}