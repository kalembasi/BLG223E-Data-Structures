/* @Author
Student Name: Ömer Malik Kalembaşı
Student ID : 150180112
Date: 24.03.2022 */
#pragma once
#include <string>

using namespace std;

class TrackNode{
    private:
        string name;
        string artist_name;
        string kwd;
        string url;
        int views;
        TrackNode* prev;
        TrackNode* next;
    public:
        TrackNode(int, string, string, string, string);
        ~TrackNode();
        void set_name(string);
        void set_views(int);
        string get_name();
        string get_artist_name();
        string get_kwd();
        void set_kwd(string);
        int get_views();
        void set_next(TrackNode*);
        void set_prev(TrackNode*);
        TrackNode* get_next();
        TrackNode* get_prev();
        TrackNode* step_node(bool);
        void get_node_info();
};

class KwdNode{
    private:
        string kwd;
        int count=0;
        KwdNode* next;
    public:
        KwdNode(string);
        ~KwdNode();
        string get_keyword();
        void set_keyword(string);
        KwdNode* get_next();
        void set_next(KwdNode*);
        int get_count();
        void update_count(int);
};