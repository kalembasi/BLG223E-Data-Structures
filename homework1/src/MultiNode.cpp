#include <iostream>
#include <string>
#include "MultiNode.h"
using namespace std;

DateNode::DateNode(string date)
{
    this->date= date;
    this->next=NULL;
    this->prev=NULL;
    this->up = NULL;
}

void DateNode::set_date(string date)
{
    this->date=date;
}

string DateNode::get_date()
{
    return this->date;
}

void DateNode::set_next(DateNode* next){
    this->next=next;
}

DateNode* DateNode::get_next(){
    return this->next;
}

void DateNode::set_prev(DateNode* prev){
    this->prev=prev;
}

DateNode* DateNode::get_prev(){
    return this->prev;
}

void DateNode::set_up(TSiteNode* up)
{
    this->up = up;
}

TSiteNode* DateNode::get_up()
{
    return this->up;
}

TSiteNode::TSiteNode(string time, string site_name)
{
    this->time= time;
    this->site_name = site_name;
    this->up = NULL;
}

void TSiteNode::set_time(string time)
{
    this->time = time;
}

string TSiteNode::get_time()
{
    return this->time;
}

void TSiteNode::set_site_name(string site_name)
{
    this->site_name = site_name;
}

string TSiteNode::get_site_name()
{
    return this->site_name;
}

void TSiteNode::set_up(TSiteNode* up)
{
    this->up = up;
}

TSiteNode* TSiteNode::get_up()
{
    return this->up;
}