#include <iostream>
#include <string>
#include "/home/anmol/IMG-Assignments/oops/lib/include/reviewer.hpp"

using namespace std;

int Reviewer::assignments = 0;
//map <Assignment, int* , Assignment_cmp > Reviewer::status_of_assignments;

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





void Reviewer::add_change(string name, string change, Assignment assignment){
    Student* stu = &students[0];
    int i = 1;
    while(stu->get_name()!=name){
        stu = &students[i++];
    }
    S_Assignment_info& tmp = stu->get_info(assignment);
    tmp.changes.push_back(change);
    tmp.status = CHANGES_PENDING;

}

void Reviewer::change_status(string name, string new_status, Assignment assignment, string date){
    
    Student* stu = &students[0];
    int i = 1;
    while(stu->get_name()!=name){
        stu = &students[i++];
    }

    S_Assignment_info& tmp = stu->get_info(assignment);
    
    if(new_status=="not reviewed"){
        tmp.status = NOT_REVIEWED;
    }
    else if(new_status=="changes pending"){
        tmp.status = CHANGES_PENDING;
    }
    else if(new_status=="completed"){
        tmp.status=COMPLETED;
        tmp.completion_date = date;
        tmp.changes.clear();
    }

    
}

void Reviewer::add_change_and_change_status(Student student, string change, Assignment assignment){
    S_Assignment_info& tmp = student.get_info(assignment);
    tmp.changes.push_back(change);
    tmp.status = CHANGES_PENDING;
}

//int Reviewer::get_no_of_students(){ return students.size();}

void Reviewer::add_student(Student stud){
    students.push_back(stud);
}

// void Reviewer::add_link(string link){
//     submitted_links.push_back(link);
// }
// void Reviewer::add_doubt(string doubt){
//     doubts.push_back(doubt);
// }
    
void Reviewer::student_functions(int i, int a , int& login){

    string b;
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
            cout<<"Enter assignment number: ";
            cin>>b;
            cout<<"Enter project link:\n";
            {string lin;
            cin>>lin;
            S_Assignment_info& tmp = get_info(students[i].get_name(),b);
            tmp.submitted_links.push_back(lin);}
            break;
        case 7:
            cout<<"Enter assignment number: ";
            cin>>b;
            cout<<"Enter doubt:\n";
            {string doub;
            cin>>doub;
            S_Assignment_info& tmp = get_info(students[i].get_name(),b);
            tmp.doubts.push_back(doub);}
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

S_Assignment_info& Reviewer::get_info(string name,int b ){
    Student* stu = &students[0];
    int i = 1;
    while(stu->get_name()!=name){
        stu = &students[i++];
    }
    return stu->get_info(tasks[b-1]);
}

void Reviewer::store_links(ofstream& fout){
    for(auto it : students){
        string name = it.get_name();
        for( int i=0 ; i<tasks.size() ; ++i){
            int a = tasks[i].get_number();
            S_Assignment_info tmp = get_info(name,a);
            if(tmp.submitted_links.size()){
                fout<<endl<<name<<endl;
                fout<<to_string(a)<<endl;
                tmp.store_links(fout);
                fout<<"-1";
                
            }
        }
    }
    fout<<"\n-1";
}

void Reviewer::store_doubts(ofstream& fout){
    for(auto it : students){
        string name = it.get_name();
        for( int i=0 ; i<tasks.size() ; ++i){
            S_Assignment_info tmp = get_info(name,i+1);
            if(tmp.doubts.size()){
                fout<<endl<<name<<endl;
                fout<<to_string(i+1)<<endl;
                tmp.store_doubts(fout);
                fout<<"-1";
            }
        }
    }
    fout<<"\n-1";
}


void Reviewer::display_submissions(){
    for(auto it : students){
        int print = 0;
        for( int i=0 ; i<tasks.size() ; ++i){
        
            S_Assignment_info tmp = get_info(it.get_name(),i+1);
            
            if(tmp.submitted_links.size()){
                if(!print){
                    cout<<it.get_name()<<endl;
                    print = 1;
                }
                cout<<i+1<<". "<<tasks[i].get_name()<<": "<<endl;
                tmp.display_submissions();
            }
        
        }
    }
}

void Reviewer::display_doubts(){
    for(auto it : students){
        int print = 0;
        for( int i=0 ; i<tasks.size() ; ++i){
        
            S_Assignment_info tmp = get_info(it.get_name(),i+1);
            
            if(tmp.doubts.size()){
                if(!print){
                    cout<<it.get_name()<<endl;
                    print = 1;
                }
                cout<<i+1<<". "<<tasks[i].get_name()<<": "<<endl;
                tmp.display_doubts();
            }
        
        }
    }
}


void Reviewer::clear_students(){
    students.clear();
}