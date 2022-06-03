#include <iostream>
#include <string>
#include "MultiList.h"
#include <algorithm> //to erase slashes from string

using namespace std;

MultiList::MultiList()
{
    head=NULL;
    tail=NULL;
}

MultiList::~MultiList()
{
    DateNode* p1 = head;
    DateNode* n1 = head;
    TSiteNode* p2 = NULL;
    TSiteNode* n2 = NULL;

    while(n1!=NULL){
        n2 = n1->get_up();
        p2 = n2->get_up();
        while(n2!=NULL)
        {
            n2 = p2->get_up();
            delete p2;
            p2 = n2;
        }
        n1=p1->get_next();
        delete p1;
        p1=n1;
    }
}

int MultiList::dateToInt(string date){		//converts string date to integer
    string dateStr = date;
    dateStr.erase(remove(dateStr.begin(), dateStr.end(), '/'), dateStr.end());
    int dateInt = stoi(dateStr);
    return dateInt;
}

int MultiList::timeToInt(string time){		//converts string time to integer
    string timeStr = time;
    timeStr.erase(remove(timeStr.begin(), timeStr.end(), ':'), timeStr.end());
    int timeInt = stoi(timeStr);
    return timeInt;
}

DateNode* MultiList::searchDate(string date)
{
    if(head==NULL){
        return NULL;
    }
	
	DateNode* temp = head;
	while (temp->get_date() != date && temp->get_next() != NULL){		//traverse the linked list
		temp = temp->get_next();
    }
	if (temp->get_date() != date){
		return NULL;
	}else{
        return temp;
	}
}

void MultiList::add_node(string date,string time,string site_name)
{
    //Fill here. You can add any function.
    if(searchDate(date)==NULL){
         
		 DateNode* current_node;
         DateNode* new_node = new DateNode(date);
 
		if(head == NULL){	//if the list is null
			head = new_node;
		}else if(dateToInt(head->get_date()) >= dateToInt(new_node->get_date())){	//if the node is to be inserted at the beginning of the linked list
			new_node->set_next(head);
			new_node->get_next()->set_prev(new_node);
			head = new_node;
		}else{
			current_node = head;	//find the node after which the new node is to be inserted
			while (current_node->get_next() != NULL && dateToInt(current_node->get_next()->get_date())  < dateToInt(new_node->get_date())){
				current_node = current_node->get_next();	//traverse the linked list
			}
			new_node->set_next(current_node->get_next());		//make the correction 
			if (current_node->get_next() != NULL){	//if the new node is inserted between two nodes
				new_node->get_next()->set_prev(new_node);
			}	
			current_node->set_next(new_node);	//make the correction
			new_node->set_prev(current_node);	//make the correction
		}
		
		TSiteNode* newTnode = new TSiteNode(time,site_name);	//if the new node is allready exists in the linked list, create TSiteNode to add 2nd dimention
		new_node->set_up(newTnode);

    }else{	
       	DateNode* current_address = searchDate(date);
       	TSiteNode* new_node = new TSiteNode(time,site_name);
       	TSiteNode* headUp = current_address->get_up();
       	TSiteNode* current;
		
		if (headUp == NULL || timeToInt((headUp)->get_time()) >=  timeToInt(new_node->get_time())) {	//if the new node to be inserted to the beginning or replaced with the head
			new_node->set_up(headUp);
			headUp = new_node;
			current_address->set_up(new_node);   
		}else{		//locate the node before the point of insertion 
			current = headUp;
			while (current->get_up() != NULL && timeToInt(current->get_up()->get_time()) < timeToInt(new_node->get_time()) ) {
				current = current->get_up();	//traverse the linked list
			}
			new_node->set_up(current->get_up());		//make the correction
			current->set_up(new_node);		//make the correction
		}    
    }
}
    
void MultiList::remove_node(string date,string time)
{
    DateNode* current_address = searchDate(date);	
    TSiteNode* headUp = current_address->get_up();
	TSiteNode* temp = headUp;
	TSiteNode* prev = NULL;
	
	if (temp != NULL && temp->get_time() == time){	//if head is going to be deleted
		headUp = temp->get_up();
        current_address->set_up(temp->get_up());
         
		delete temp;	//free old head
		return;
	}else{		

		while (temp != NULL && temp->get_time() != time){	//traverse the linked list
			prev = temp;
			temp = temp->get_up();
		}

		if (temp == NULL){	//if node is not a member of linked list
			return;
		}	

		prev->set_up(temp->get_up());	//remove the node from linked list
		delete temp;	//free memory	
	}
}

void MultiList::print_list()
{
    DateNode* p_hor=head;
    TSiteNode* p_ver;
    
    while(p_hor)
    {
        cout<<p_hor->get_date()<<":"<<endl;
        p_ver=p_hor->get_up();
        while(p_ver)
        {
            cout<<p_ver->get_time()<<"->"<<p_ver->get_site_name()<<endl;
            p_ver=p_ver->get_up();
        }
        p_hor=p_hor->get_next();
    }
}
