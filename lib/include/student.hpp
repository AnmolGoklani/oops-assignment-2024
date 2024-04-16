#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <map>
#include <string>
#include "assignment.hpp"
#include "IMG_Member.hpp"

using namespace std;

class Student : public IMG_Member{
    public:
        Student(string name , string password);
        int how_many_pending();
        void list_pending_short();
        void list_pending_long();
        void display_assignment_details(Assignment assignment);
        void list_of_completed();
        void add_change(string change, Assignment assignment);
        void set_status(Assignment assignment , iteration status);
        void add_assignment(S_Assignment_info info , Assignment assignment);
        iteration get_status(Assignment assi);
        vector <string> get_changes(Assignment assi);
        string get_date(Assignment assi);
        //void submit(string link);
        //void ask_doubt(string doubt);

    private:
        int pending_assignments = 0;
        map <Assignment,S_Assignment_info, Assignment_cmp> list;
};



#endif