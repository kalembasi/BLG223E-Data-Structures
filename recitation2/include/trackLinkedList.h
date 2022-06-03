/* @Author
Student Name: Ömer Malik Kalembaşı
Student ID : 150180112
Date: 24.03.2022 */
#pragma once
#include <string>
#include <trackNode.h>

using namespace std;

class TrackLinkedList{
    private:
        TrackNode* head;
        TrackNode* tail;
        TrackNode* search(int);
    public:
        TrackLinkedList();
        ~TrackLinkedList();
        void add_node(TrackNode*);
        void remove_node(string);
        void print_list(bool);
        void reduce_duplicates();
        bool contains(string);
};

class KwdLinkedList{
    private:
        KwdNode* head;
        KwdNode* tail;
    public:
        KwdLinkedList();
        ~KwdLinkedList();
        void add_node(string);
        bool contains(string);
        KwdNode* search(string);
};