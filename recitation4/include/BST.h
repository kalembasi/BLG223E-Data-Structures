#pragma once

#ifndef BST_DEF
#define BST_DEF

#include <vector>
#include "BSTNode.h"

using namespace std;

class BST{
    private:
        Node* root;

        void postorder_traverse(Node*);
        void postorder_destruct(Node*);

    public:
        BST();
        ~BST();

        Node* get_root();
        void add(int);
        void corrupted_add(vector<int>);
        bool contains(int);
        int maxSumBST(Node*);

        void printPostOrder();
        //fill
        int findMaxSubBST(Node*, int&); //helper function for maxSumBST()

};

#endif
