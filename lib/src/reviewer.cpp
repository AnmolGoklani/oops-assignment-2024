#include <iostream>
#include <string>
#include "/home/anmol/IMG-Assignments/oops/lib/include/reviewer.hpp"

using namespace std;

int Reviewer::assignments = 0;
//map <Assignment, int* , Assignment_cmp > Reviewer::status_of_assignments;
vector <string> Reviewer::submitted_links; 
vector <string> Reviewer::doubts;
vector <Student> Reviewer::students;
vector <Reviewer> reviewers;

int Reviewer::how_many_assignments(){
    return assignments;
}

// void Reviewer::display_status(){
//     for(auto it : status_of_assignments){
//         Assignment tmp = it.first;
//         cout<<tmp.get_name()<<" :\n";
//         cout<<"Not Reviewed : "<<it.second[0]<<endl;
//         cout<<"Changes Pending : "<<it.second[1]<<endl;
//         cout<<"Completed : "<<it.second[2]<<endl;
//     }
// } 

// void Reviewer::display_assignment_status(Assignment assignment){
//     cout<<assignment.get_name()<<" :\n";
//     cout<<"Not Reviewed : "<<status_of_assignments[assignment][0]<<endl;
//     cout<<"Changes Pending : "<<status_of_assignments[assignment][1]<<endl;
//     cout<<"Completed : "<<status_of_assignments[assignment][2]<<endl;
// } 

void Reviewer::display_student_status(string name){
    Student stu = students[0];
    int i = 1;
    while(stu.get_name()!=name){
        stu = students[i++];
    }
    stu.list_pending_short();
} 

void Reviewer::display_student_assignment_status(Assignment assignment , string name){
    Student stu = students[0];
    int i = 1;
    while(stu.get_name()!=name){
        stu = students[i++];
    }
    stu.display_assignment_details(assignment);
}

void Reviewer::display_assignment_deadlines(){
    for( int i=0 ; i<tasks.size() ; ++i){
    
        cout<<tasks[i].get_number()<<". "<<tasks[i].get_name()<<" - "<<tasks[i].get_deadline()<<endl;
    
    }
}

void Reviewer::create_assignment(Assignment tmp){
    // int a[3] = {students.size(),0,0}; 
    // status_of_assignments[tmp] = a; 
    tasks.push_back(tmp);
    S_Assignment_info tempo;
    for(int i = 0 ; i < students.size() ; i++){
        students[i].add_assignment(tempo, tmp);
    }
    assignments++;
}

void Reviewer::display_submissions(){
    for( int i=0 ; i<submitted_links.size() ; ++i){
    
        cout<<submitted_links[i]<<endl;   
    
    }
}

void Reviewer::display_doubts(){
    for( int i=0 ; i<doubts.size() ; ++i){
    
        cout<<doubts[i]<<endl;   
    
    }
}

void Reviewer::delete_doubt(int index){
    doubts.erase(doubts.begin() + index - 1);
}

void Reviewer::add_change(string name, string change, Assignment assignment){
    Student stu = students[0];
    int i = 1;
    while(stu.get_name()!=name){
        stu = students[i++];
    }
    stu.add_change(change , assignment);
    stu.set_status(assignment, CHANGES_PENDING);

}

void Reviewer::change_status(string name, string new_status, Assignment assignment){
    if(new_status=="not reviewed"){
        Student stu = students[0];
        int i = 1;
        while(stu.get_name()!=name){
            stu = students[i++];
        }
        stu.set_status(assignment, NOT_REVIEWED);
    }
    else if(new_status=="changes pending"){
        Student stu = students[0];
        int i = 1;
        while(stu.get_name()!=name){
            stu = students[i++];
        }
        stu.set_status(assignment, CHANGES_PENDING);
    }
    else{
        Student stu = students[0];
        int i = 1;
        while(stu.get_name()!=name){
            stu = students[i++];
        }
        stu.set_status(assignment, COMPLETED);
    }

    
}

void Reviewer::add_change_and_change_status(Student student, string change, Assignment assignment){
    student.add_change(change , assignment);
    student.set_status(assignment, CHANGES_PENDING);
}

//int Reviewer::get_no_of_students(){ return students.size();}

void Reviewer::add_student(Student stud){
    students.push_back(stud);
}

void Reviewer::add_link(string link){
    submitted_links.push_back(link);
}
void Reviewer::add_doubt(string doubt){
    doubts.push_back(doubt);
}
    
void Reviewer::student_functions(int i, int a , int& login){
    switch (a)
    {
        case 1:
            cout<<students[i].how_many_pending()<<endl<<endl<<endl;
            break;
        case 2:
            students[i].list_pending_short();
            break;
        case 3:
            students[i].list_pending_long();
            break;
        case 4:
            cout<<"Enter assignment number: ";
            int b;
            cin>>b;
            students[i].display_assignment_details(tasks[b-1]);
            break;
        case 5:
            students[i].list_of_completed();
            break;
        case 6:
            cout<<"Enter project link:\n";
            {string lin;
            cin>>lin;
            add_link(lin);}
            break;
        case 7:
            cout<<"Enter doubt (with name):\n";
            {string doub;
            cin>>doub;
            add_doubt(doub);}
            break;
        case 8:
            login = 0;
            break;
        default:
            cout<<"WRONG INPUT\n\n";
            break;
    }
}

iteration Reviewer::get_status(int i , Assignment assi){
    return students[i].get_status(assi);
}

vector <string> Reviewer::get_changes(int i ,Assignment assi){
    return students[i].get_changes(assi);
}

string Reviewer::get_date(int i ,Assignment assi){
    return students[i].get_date(assi);
}

void Reviewer::store_links(ofstream& fout){
    for( int i=0 ; i<submitted_links.size() ; ++i){
    
        fout<<submitted_links[i]<<endl;
    
    }
}

void Reviewer::store_doubts(ofstream& fout){
    for( int i=0 ; i<doubts.size() ; ++i){
    
        fout<<doubts[i]<<endl;
    
    }
}