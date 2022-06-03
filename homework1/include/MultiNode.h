#pragma once
#include <string>

using namespace std;

class TSiteNode{
    private:
        string time;
        string site_name;
        TSiteNode* up;
    public:
        TSiteNode(string,string);
        void set_time(string);
        string get_time();
        void set_site_name(string);
        string get_site_name();
        void set_up(TSiteNode*);
        TSiteNode* get_up();
};

class DateNode{
    private:
        string date;
        DateNode* next;
        DateNode* prev;
        TSiteNode* up;

    public:
        DateNode(string);
        void set_date(string);
        string get_date();
        void set_next(DateNode*);
        DateNode* get_next();
        void set_prev(DateNode*);
        DateNode* get_prev();
        void set_up(TSiteNode*);
        TSiteNode* get_up();
};

