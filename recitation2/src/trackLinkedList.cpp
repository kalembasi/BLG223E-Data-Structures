/* @Author
Student Name: Ömer Malik Kalembaşı
Student ID : 150180112
Date: 24.03.2022 */
#include "trackLinkedList.h"
#include <stdio.h>
#include <iostream>

using namespace std;


TrackLinkedList::TrackLinkedList()
{
    //fill
    head=NULL;
    tail=NULL;
}

TrackLinkedList::~TrackLinkedList()
{
    //fill
    TrackNode* p = head;
    TrackNode* n = head;

    while(n!=NULL){
        n=p->get_next();
        delete p;
        p=n;
    }
}

void TrackLinkedList::print_list(bool isReverse)
{
    TrackNode* p;
    TrackNode* target;
    if (isReverse){
        p = this->tail;
        target = this->head;
    }
    else{
        p = this->head;
        target = this->tail;
    }
    
    if (p == NULL)
        return;

    int d = 0;
    while (p->step_node(isReverse) != target->step_node(isReverse)){
        cout << "----------------------" << d << "----------------------" << endl;
        p->get_node_info();
        p = p->step_node(isReverse);
        d++;
    }
    cout << "----------------------" << d << "----------------------" << endl;
    p->get_node_info();
}

TrackNode* TrackLinkedList::search(int view)
{
    //fill
    TrackNode* p = head;

    if(view >= head->get_views())//
        return NULL;
    else{
        while(p->get_next()){
            if(p->get_next()->get_views()<=view)//
                return p;
            p=p->get_next();
        }
        return p;
    } 
}

void TrackLinkedList::add_node(TrackNode* node)
{
    //fill
    if(head==NULL){//if there is no node in the list
        head=node;
        tail=node;
    }
    else{
        TrackNode* prev = this->search(node->get_views());

        if(prev==NULL){//if the new node will be inserted of the top of the list
            node->set_next(head);
            head->set_prev(node);
            head=node;
        }
        else if(prev==tail){// if the new node will be inserted of the end of the list
            tail->set_next(node);
            node->set_prev(tail);
            tail=node;
        }
        else{//if the new node will be inserted of the between of two nodes
            TrackNode* old_next = prev->get_next();
            node->set_next(old_next);
            node->set_prev(prev);
            prev->set_next(node);
            old_next->set_prev(node);
        }
    }
}

void TrackLinkedList::reduce_duplicates()
{  
    TrackNode *ptr1, *ptr2; 
    ptr1 = head; 
  
    while (ptr1 != NULL && ptr1->get_next() != NULL) { 
        ptr2 = ptr1; 
        
        while (ptr2->get_next() != NULL) { 
            if (ptr1->get_kwd() == ptr2->get_next()->get_kwd()){ 
                
                int dup = ptr2->get_next()->get_views();
                ptr1->set_views( ptr1 -> get_views() + dup);
    
                if (head == ptr2->get_next())
                    head = ptr2->get_next()->get_next();
 
                if (ptr2->get_next()->get_next() != NULL)
                    ptr2->get_next()->get_next()->set_prev(ptr2->get_next()->get_prev());
            
                if (ptr2->get_next()->get_prev() != NULL)
                    ptr2->get_next()->get_prev()->set_next(ptr2->get_next()->get_next());
            }else 
                ptr2 = ptr2->get_next(); 
        } 
        ptr1 = ptr1->get_next(); 
        tail = ptr1;
    } 
}

KwdLinkedList::KwdLinkedList()
{
    //fill
    head=NULL;
    tail=NULL;
}

KwdLinkedList::~KwdLinkedList()
{
    //fill
    KwdNode* p = head;
    KwdNode* n = head;

    while(n!=NULL){
        n=p->get_next();
        delete p;
        p=n;
    }
}

KwdNode* KwdLinkedList::search(string kwd)
{
    //fill
    KwdNode* p=head;
    while(p->get_next()){
        if(p->get_keyword()==kwd){
            return p;
        }
        p=p->get_next();
    }
    return NULL;
}

void KwdLinkedList::add_node(string kwd)//BAKILACAK
{
    //fill
    KwdNode* p = new KwdNode(kwd);
    if(head==NULL){
        head = p;
        tail = p;
    }else{
        if(!contains(kwd)){//if KwdLinkedList does not contain this type kwdNode
            tail->set_next(p);
            tail=p;
            p->set_next(NULL);
        }
        else{
            KwdNode* current = this->search(kwd);
            current->update_count(current->get_count()+1);
        }
    }
}

bool KwdLinkedList::contains(string kwd)
{
    //fill
    if(head==NULL){
        return false;
    }else{
        KwdNode* p = head;

        while(p->get_next()){
            if(p->get_keyword()==kwd){
                return true;
            }
            p=p->get_next();
        }
        return false;
    }
}