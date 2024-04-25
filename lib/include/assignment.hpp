#ifndef ASSIGNMENT_HPP
#define ASSIGNMENT_HPP

#include <iostream>
#include <string>
#include <vector>
#include "fstream"



using namespace std;

enum iteration
{
    NOT_REVIEWED ,
    CHANGES_PENDING ,
    COMPLETED
    
};


class Assignment{
    public:
        Assignment();
        Assignment(string name , string deadline);
        const string get_name()const;
        string get_deadline();
        void set(string name, string deadline);
        const int get_number()const;
    

    private:
        int number;
        static int total_assignments;
        string name;
        string deadline;
};

class S_Assignment_info{
    public:
    S_Assignment_info();

    vector <string> submitted_links; //vector of github links submitted by students
    vector <string> doubts; //vector of doubts sent by students

    //S_Assignment_info(iteration status);
    // void set_info(iteration status , vector <string> changes);
    // void set_info(iteration status , string date);
    // void set_status(iteration status);
    // void add_change(string change);
    void display();
    iteration get_status();
    string get_date();
    vector <string> get_changes();
    void display_submissions();
    void display_doubts();
    void store_links(ofstream& fout);
    void store_doubts(ofstream& fout);

    friend class Reviewer;
    friend vector <string> extract_student_info();

    private:
    iteration status = NOT_REVIEWED;
    vector <string> changes; //changes to be made
    string completion_date; //for completed assignments

};

class Assignment_cmp{
  
   public:
   bool operator()(const Assignment &a , const Assignment &b)const;
   

};

#endif