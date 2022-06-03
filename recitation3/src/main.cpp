#include <iostream>
#include <queue>
#include <QStack.h>

using namespace std;

void print_menu();
bool perform_operation(char);


QStack q;

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
    cout << "A: Push an element to the stack" << endl;
    cout << "D: Delete an element from the stack"<< endl;
    cout << "P: Print the stack"<< endl;
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
            cout << "Pushed element:";
            cin >> e;
            q.push(e);
            break;
        case 'D':
        case 'd':
            q.pop();
            break;
        case 'P':
        case 'p':
            q.printStack();
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