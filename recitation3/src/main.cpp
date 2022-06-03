#include <iostream>
#include <stack>
#include <SQueue.h>

using namespace std;

void print_menu();
bool perform_operation(char);


SQueue q;

int main()
{

    bool end = false;
    char choice;


    while (!end)
    {
        print_menu();
        cin >> choice;
        end = perform_operation(choice);
    }

    return EXIT_SUCCESS;
}

void print_menu()
{
    cout << "Choose an operation" << endl;
    cout << "A: Enqueue an element to the queue" << endl;
    cout << "D: Dequeue an element from the queue"<< endl;
    cout << "P: Print the queue"<< endl;
    cout << "E: Exit" << endl;
    cout << "Enter a choice {A,D,P,E}:";
}

bool perform_operation(char choice)
{
    bool terminate = false;
    int e;

    switch (choice)
    {
        case 'A':
        case 'a':
            cout << "Enqueued element:";
            cin >> e;
            q.enqueue(e);
            break;
        case 'D':
        case 'd':
            q.dequeue();
            break;
        case 'P':
        case 'p':
            q.printQueue();
            cout << endl;
            break;
        case 'E':
        case 'e':
            terminate = true;
            break;
        default:
            cout << "Error: You have entered an invalid choice" << endl;
            cin >> choice;
            terminate = perform_operation(choice);
            break;
    }
    return terminate;
}