#ifndef REVIEWER_HPP
#define REVIEWER_HPP

#include <iostream>
#include <map>
#include <string>
#include "fstream"
#include "assignment.hpp"
#include "IMG_Member.hpp"
#include "student.hpp"

using namespace std;

vector <Assignment> tasks;

class Reviewer:public IMG_Member
{
private:
    //I've used static because I want all the reviewers to have
    //access to the same data because at IMG any reviewer can
    //review any assignment they want to

    static int assignments; //total number of assignments
    //static map <Assignment, int* , Assignment_cmp > status_of_assignments;
    //0 ,1 and 2 store the number of students who have not reviewed,
    //pending, and completed assignments respectively
    
    static vector <Student> students;
    
public:
    //int get_no_of_students();
    void add_student(Student stud);
    // void add_link(string link);
    // void add_doubt(string doubt);
    int how_many_assignments();
    //void display_status(); //overall state
    //void display_assignment_status(Assignment assignment); //particular assignment
    void display_student_status(string name); //for particular student
    void display_student_assignment_status(Assignment assignment , string name); //particular student particular assignment
    void display_assignment_deadlines();
    void create_assignment(Assignment tmp);
    void delete_doubt(int index);
    void add_change(string name, string change, Assignment assignment);
    void change_status(string name, string new_status, Assignment assignment, string date);
    void add_change_and_change_status(Student student, string change, Assignment assignment);
    void student_functions(int i, int a, int& login);
    iteration get_status(int i , Assignment assi);
    vector <string> get_changes(int i ,Assignment assi);
    string get_date(int i ,Assignment assi);
    S_Assignment_info& get_info(string name,int i );
    void store_links(ofstream& fout);
    void store_doubts(ofstream& fout);

    
};



#endif