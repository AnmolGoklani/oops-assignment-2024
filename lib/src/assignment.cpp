#include <iostream>
#include <string>
#include "/home/anmol/IMG-Assignments/oops/lib/include/assignment.hpp"

using namespace std;

int Assignment::total_assignments = 0;

Assignment::Assignment(string name , string deadline){
            this->name = name;
            this->deadline = deadline;
            total_assignments++;
            this->number = total_assignments;
}

Assignment::Assignment(){};

const string Assignment::get_name()const{
    return name;
}

void Assignment::set(string name , string deadline){
    this->name = name;
    this->deadline = deadline;
}

string Assignment::get_deadline(){
    return this->deadline;
}

void S_Assignment_info::display(){
    cout<<"status :";
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
    if(status == CHANGES_PENDING){
        cout<<"changes to be made :"<<endl;
        for( int i=0 ; i<changes.size() ; ++i){

            cout<<(i+1)<<". "<<changes[i]<<endl;

        }
    }
    
}

// S_Assignment_info::S_Assignment_info(iteration status , vector <string> changes){
//     this->status = status;
//     this->changes = changes;
//     string tmp;
//     completion_date = tmp;
//}

// void S_Assignment_info::set_info(iteration status , vector <string> changes){
//     this->status = status;
//     this->changes = changes;
// }

// void S_Assignment_info::set_status(iteration status){
//     this->status = status;
//     if(status==COMPLETED) changes.clear();
// }

// void S_Assignment_info::add_change(string change){
//     changes.push_back(change);
// }

iteration S_Assignment_info::get_status(){
    return status;
}

string S_Assignment_info::get_date(){
    return completion_date;
}

S_Assignment_info::S_Assignment_info(){}

// void S_Assignment_info::set_info(iteration status, string date){
//     this->status = status;
//     completion_date = date;
    
// }

vector <string> S_Assignment_info::get_changes(){
    return changes;
}

void S_Assignment_info::display_submissions(){
    for( int i=0 ; i<submitted_links.size() ; ++i){
    
        cout<<submitted_links[i]<<endl;   
    
    }
}


void S_Assignment_info::display_doubts(){
    for( int i=0 ; i<doubts.size() ; ++i){
    
        cout<<doubts[i]<<endl;   
    
    }
}

// void Reviewer::delete_doubt(int index){
//     doubts.erase(doubts.begin() + index - 1);
// }

void S_Assignment_info::store_links(ofstream& fout){
    for( int i=0 ; i<submitted_links.size() ; ++i){
    
        fout<<submitted_links[i]<<endl;
    
    }
}

void S_Assignment_info::store_doubts(ofstream& fout){
    for( int i=0 ; i<doubts.size() ; ++i){
    
        fout<<doubts[i]<<endl;
    
    }
}



const int Assignment::get_number()const{
    return this->number;
}

bool Assignment_cmp::operator()(const Assignment &a , const Assignment &b)const{
    
      return a.get_number() < b.get_number() ;

}

