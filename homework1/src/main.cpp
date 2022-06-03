#include <iostream>
#include <string>
#include <stdio.h>
#include "MultiList.h"

using namespace std;


bool perform_operation(char);
void print_menu();
void add_record();
void delete_record();

MultiList* web_history = new MultiList();

int main(){

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
    cout << "A: Add a website record to web browser history" << endl;
    cout << "D: Delete a website record from web browser history" << endl;
    cout << "P: Print the web browser history" << endl;
    cout << "E: Exit" << endl;
    cout << "Enter a choice {A,D,P,E}: ";
}

bool perform_operation(char choice)
{
    bool terminate = false;

    switch (choice)
    {
    case 'P':
    case 'p':
        web_history->print_list();
        break;
    case 'A':
    case 'a':
        add_record();
        break;
    case 'D':
    case 'd':
        delete_record();
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

void add_record()
{
    string f_date,date,time,site_name;
    cout << "Enter the website name:";
    cin >> site_name;
    cout << "Enter the date with yyyy-mm-dd HH:MM:SS format:";
    getline(cin >> ws,f_date);
    time = f_date.substr(f_date.size()-8);
    date = f_date.substr(0,10);
    web_history->add_node(date,time,site_name);

}
void delete_record()
{
    string f_date,date,time;
    cout << "Enter the date with yyyy-mm-dd HH:MM:SS format:";
    getline(cin >> ws,f_date);
    time = f_date.substr(f_date.size()-8);
    date = f_date.substr(0,10);
    web_history->remove_node(date,time);
}