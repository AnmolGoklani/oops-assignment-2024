#include <iostream>
#include <string>
#include "/home/anmol/IMG-Assignments/oops/lib/include/student.hpp"

using namespace std;

int Student::how_many_pending(){
    return pending_assignments;
}

void Student::list_pending_short(){

    for( auto it : list ){
    
        iteration status = it.second.get_status();
        if(status != COMPLETED){
            Assignment temp = it.first;
            cout<<temp.get_number()<<". "<<temp.get_name()<<" : ";
            switch (status)
            {
            case NOT_REVIEWED:
                cout<<"NOT REVIEWED\n";
                break;

            case CHANGES_PENDING:
                cout<<"CHANGES PENDING\n";
                break;

            case COMPLETED:
                cout<<"COMPLETED\n";
                break;
            
            default:
                break;
            }
            //cout<<it.first.get_name()<<" : "<<status<<endl;  
            //this gives error...WHY?
        }
    
    }
}

void Student::list_pending_long(){
    for( auto it : list ){
    
        iteration status = it.second.get_status();
        if(status != COMPLETED){
            Assignment temp = it.first;
            cout<<temp.get_name()<<endl;
            cout<<"Deadline : "<<temp.get_deadline()<<endl;
            it.second.display();
            
        }

    }
}

void Student::display_assignment_details(Assignment assignment){
    
    cout<<assignment.get_name()<<endl;
    cout<<"Deadline : "<<assignment.get_deadline()<<endl;
    list[assignment].display();
    
}

void Student::list_of_completed(){
    for( auto it : list ){
    
        iteration status = it.second.get_status();
        if(status == COMPLETED){
            Assignment temp = it.first;
            cout<<temp.get_name()<<endl;
            cout<<"completed on : "<<it.second.get_date()<<endl;
        }
    }
}

void Student::add_change(string change , Assignment assignment){
    list[assignment].add_change(change);
}

void Student::set_status(Assignment assignment , iteration status){
    list[assignment].set_status(status);
    if(status == COMPLETED) pending_assignments--;
    else if(status == NOT_REVIEWED) pending_assignments++;
}

void Student::add_assignment(S_Assignment_info info , Assignment assignment){
    list[assignment] = info;
    pending_assignments++;
}

Student::Student(string name, string password){
    
    set_name(name, password);
   
}

iteration Student::get_status(Assignment assi){
    return list[assi].get_status();
}

vector <string> Student::get_changes(Assignment assi){
    return list[assi].get_changes();
}

string Student::get_date(Assignment assi){

    return list[assi].get_date();

}