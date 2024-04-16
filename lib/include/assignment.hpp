#ifndef ASSIGNMENT_HPP
#define ASSIGNMENT_HPP

#include <iostream>
#include <string>
#include <vector>



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
    //S_Assignment_info(iteration status);
    void set_info(iteration status , vector <string> changes);
    void set_info(iteration status , string date);
    void set_status(iteration status);
    void add_change(string change);
    void display();
    iteration get_status();
    string get_date();
    vector <string> get_changes();

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