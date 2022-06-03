/* @Author
Student Name: Ömer Malik Kalembaşı
Student ID : 150180112
Date: 24.03.2022 */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "trackNode.cpp"
#include "trackLinkedList.cpp"


using namespace std;


void parseAndFill(TrackLinkedList* ll, const char *path)
{
    fstream infile;                 // Initializes the file operation
    infile.open(path, ios::in);     // Opens the file pointer
    string buffer;
    string delim = ",";             // Comma-separated values
    int d = -1;
    if(infile.is_open()){
        // Initialize the attributes of the entries
        string artist;
        string trackID;
        string kwd;
        string url;
        int views;

        string token;
        size_t pos = 0;
        while(getline(infile,buffer))
        {
            // Skipping the first line
            if (d == -1){
                d = 0;
                continue;
            }

            // d=0 --> artist
            // d=1 --> trackID
            // d=2 --> kwd
            // d=3 --> url and views
            while ((pos = buffer.find(delim)) != std::string::npos) {
                token = buffer.substr(0, pos);
                switch (d)
                {
                case 0:
                    artist = token;
                    break;
                case 1:
                    trackID = token;
                    break;
                case 2:
                    kwd = token;
                    break;
                case 3:
                    url = token;
                    buffer.erase(0, pos+delim.length());
                    views = stoi(buffer);
                    break;
                
                }
                buffer.erase(0, pos+delim.length());
                d++;
            }

            // Creates a TrackNode object by using the attributes
            TrackNode* node = new TrackNode(views, trackID, artist, kwd, url);

            // Adding the node to the linked list
            ll->add_node(node);
            d = 0;
        }
    }
    else{
      cerr<<"Error opening file!!"<<endl;
    }

    // Closes the file pointer
    infile.close();
}

void print_menu()
{
    cout << "Choose an operation" << endl;
    cout << "A) Load the entries from the text file and print the resulting linked list" << endl;
    cout << "B) printing the linked list after reducing multiple entries" << endl;
    cout << "C) printing the linked list after reverting its ordering" << endl;
    cout << "E) Exit" << endl;
    cout << "Enter a choice: {A,B,C,E}: ";
}

bool perform_operation(TrackLinkedList* ll, char choice, const char* path_to_file)
{
    bool terminate = false;
    switch (choice)
    {
    case 'A':
    case 'a':
        // Reads from the input file repeatedly as many times 'A' is pressed
        // Generates a linked list of track entries
        // Intended to be run at once
        parseAndFill(ll, path_to_file);
        ll->print_list(false);
        break;
    case 'B':
    case 'b':
        // Removes the duplicate entries by checking the search keyword queries (kwd)
        ll->reduce_duplicates();
        ll->print_list(false);    
        break;
    case 'C':
    case 'c':
        // Reverses the linked list
        ll->print_list(true);    
        break;
    case 'E':
    case 'e':
        terminate = true;
        break;
    default:
        cout << "Error: You have entered an invalid choice" << endl;
        cin >> choice;
        terminate = perform_operation(ll, choice, path_to_file);
        break;
    }

    return terminate;
}

int main(int argc, char** argv){
    bool terminate = false;
    char choice;
    // Constructs the linked list object
    TrackLinkedList* ll = new TrackLinkedList();

    while(!terminate)
    {
        print_menu();
        cin >> choice;
        terminate = perform_operation(ll, choice, argv[1]);
    }

    // Destroys the linked list object
    delete ll;

    return 0;
}