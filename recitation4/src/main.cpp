#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "BST.h"
#include "BSTNode.h"

using namespace std;

void readAndFill(BST* bst, const char* path, string mode)
{
    /*
    Reads the content from file and fills the Binary Tree
    Primarily going to be used for testing and evaluating your assignments
    Supporting the BST number addition modes: "regular" and "corrupted"
    - "regular" mode adds the nodes while respecting the BST requirements
    - "corrupted" mode adds the nodes without respecting the requirements of BST
       by BFS-based traversal for filling
    */

    fstream infile;                 // Initializes the file operation
    infile.open(path, ios::in);     // Opens the file pointer
    string buffer;
    int digit;

    // Initializing digits vector for corrupted mode only
    vector<int> digits;

    if (infile.is_open()){
        while(getline(infile,buffer)){
            // Sets the digit to -inf if buffer is null
            // Converts string to int only if not null
            if (buffer == "null"){
                digit = INT32_MIN;
            }
            else{
                digit = stoi(buffer);
            }
            if (mode == "regular"){
                bst->add(digit);
            }
            else if (mode == "corrupted"){
                digits.push_back(digit);
            }
        }
    }
    // Closes the file pointer
    infile.close();

    // Loads the vector of digits to the BT
    if (mode == "corrupted"){
        reverse(digits.begin(), digits.end());
        bst->corrupted_add(digits);
    }

}

void print_menu()
{
    cout << "Choose an operation for Binary Search Tree (BST)" << endl;
    cout << "A) Insert a number to the BST" << endl;
    cout << "B) Read numbers from a file and add them to the BST" << endl;
    cout << "C) Test whether the BST contains a number" << endl;
    cout << "P) Print the node structure in the BST with PostOrder search" << endl;
    cout << "M) Find the BST within a binary tree with maximum sum value" << endl;
    cout << "E) Exit" << endl;
    cout << "Enter a choice: {A,B,P,M,E}: ";
}

const char* bool_cast(const bool b) {
    return b ? "true" : "false";
}

bool perform_operation(BST* bst, char choice, const char* path_to_file)
{
    bool terminate = false;
    int digit;
    int maxsum;
    switch (choice)
    {
        case 'A':
        case 'a':
            // Adds a digit to a BST
            cin >> digit;
            bst->add(digit);
            break;
        case 'B':
        case 'b':
            // Reads the file and adds the digits to a BST
            readAndFill(bst, path_to_file, "regular");
            break;
        case 'C':
        case 'c':
            cin >> digit;
            cout << "BST contains digit " << digit << ": " << bool_cast(bst->contains(digit)) << endl;
            break;
        case 'P':
        case 'p':
            bst->printPostOrder();
            break;
        case 'M':
        case 'm':
            readAndFill(bst, path_to_file, "corrupted");
            maxsum = bst->maxSumBST(bst->get_root());
            cout << "Sub-BST with Maximum Sum: " << maxsum << endl;
            break;
        case 'E':
        case 'e':
            terminate = true;
            break;
        default:
            cout << "Error: You have entered an invalid choice" << endl;
            cin >> choice;
            terminate = perform_operation(bst, choice, path_to_file);
            break;
    }

    return terminate;
}

int main(int argc, char** argv){

    bool terminate = false;
    char choice;

    BST* bst = new BST();

    while(!terminate)
    {
        print_menu();
        cin >> choice;
        terminate = perform_operation(bst, choice, argv[1]);
    }
    
    delete bst;
    
    return 0;
}