#include <iostream>
#include <stack>
#include <list>
#include <queue>
#include "BST.h"
#include "BSTNode.h"

using namespace std;

BST::BST()
{
    //fill
    this->root=NULL;
}

BST::~BST()     //uses postorder destruct 
{
    //fill
    if(this->root != NULL)
        this->postorder_destruct(this->root);
    
    this->root=NULL;
}

Node* BST::get_root()       //returns the current root
{
    return this->root;
}

void BST::add(int data)     //adds the node which is its data is given variable, acccording to BST construct
{
    //fill   
    Node* newNode = new Node(data);

    if(this->root == NULL){     //if tree is empty, adds the node as root
        root=newNode;
        return;
    }
    
    Node* t = root;     //creates node temp t to traverse the tree

    while(t!=NULL){     //adds the node according to construct of BST
        if(t->get_data()>data){
            if(t->get_left()==NULL){
                t->set_left(newNode);
                return;
            }
            t = t->get_left();
        }
        else if(t->get_data()<data){
            if(t->get_right()==NULL){
                t->set_right(newNode);
                return;
            }
            t = t->get_right();
        }
        else{       //if the node is exists already in the tree, deletes the node
            delete newNode;
            return;
        }
    }
}

void BST::corrupted_add(vector<int> data)
{
    queue<Node*> q;
    Node* temp;
    int turn = 0;    // Suggests the left turn
    while (!data.empty()){
        int num = data.back();
        data.pop_back();

        if (num == INT32_MIN){
            q.pop();
            continue;
        }

        Node* n = new Node(num);

        if (root == nullptr){
            root = n;
            q.push(root);
            q.push(root);
        }
        else{
            temp = q.front();
            q.pop();
            if(turn == 0){
                temp->set_left(n);
                turn = 1;
            }
            else if(turn == 1){
                temp->set_right(n);
                turn = 0;
            }
            q.push(n);
            q.push(n);
        }
    }
}

bool BST::contains(int data)    //checks if a node exist in the tree which has the data given as a variable
{
    //fill
    if(this->root == NULL)  //if roots in null, returns false
        return false;
    
    Node* t = root;     //creates a node temp t to traverse
    
    while(t!=NULL){     //traversal to find particular node data
        if(t->get_data()>data)
            t = t->get_left();
        
        else if(t->get_data()<data)
            t = t->get_right();
        
        else{       //else condition progress if only data == t->get_data()
            return true;
        }
    }

    return false;
}

void BST::postorder_traverse(Node* n)       //recursively postorder traverse
{
    //fill
    if(n!=NULL){
        this->postorder_traverse(n->get_left());
        this->postorder_traverse(n->get_right());
        cout<<n->get_data()<<" ";
    }
}

void BST::postorder_destruct(Node* n)       //recursively postorder destruct
{
    //fill
    if(n!=NULL){
        this->postorder_destruct(n->get_left());
        this->postorder_destruct(n->get_right());
        delete n;
    }
}

void BST::printPostOrder()
{
    this->postorder_traverse(this->root);
    cout<<endl;
}

int BST::maxSumBST(Node* node){     //finds the max sub tree which has construct of BST in a BT
    // Find the sum of the Binary Search Tree with the maximum sum within the Binary Tree
    int sum = 0;
    sum = findMaxSubBST(node, sum);     //uses recursively postorder traverse helper function findMaxSubBST()
    return sum;
}

int BST::findMaxSubBST(Node* node, int& sum){   //helper function for maxSumBST(), postorder travels the nodes and checks BST conditions, recursively
    if (node == NULL)
        return 0;
    else{
        int left = findMaxSubBST(node->get_left(), sum);    
        int right = findMaxSubBST(node->get_right(), sum);
        int nodeSum = left + right + node->get_data();      //calculates the current sum

        if((left < node->get_data() || left == 0) && (node->get_data() < right || right == 0)){     //or statements comes from status of the leefs
            sum = max(nodeSum, sum);
            return nodeSum;
        }

        return sum;
    }
}