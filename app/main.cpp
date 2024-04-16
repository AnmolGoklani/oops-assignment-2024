
#include "/home/anmol/IMG-Assignments/oops/lib/src/assignment.cpp"
#include "/home/anmol/IMG-Assignments/oops/lib/src/IMG_Member.cpp"
#include "/home/anmol/IMG-Assignments/oops/lib/src/reviewer.cpp"
#include "/home/anmol/IMG-Assignments/oops/lib/src/student.cpp"
#include "fstream"

Reviewer admin;

void save_student_info(vector <string> student_deets){

    ofstream fout;

    fout.open("students.txt");

    for( int i=0 ; i<student_deets.size() ; ++i){
        int j;
        fout<<endl;
        for(j=0 ; student_deets[i][j]!=32 ; ++j){
        
            fout<<student_deets[i][j];
        
        }
        fout<<endl;
        j++;
        while(student_deets[i][j]) 
            fout<<student_deets[i][j++];
        for( int k=0 ; k<tasks.size() ; ++k){
        
            iteration status = admin.get_status(i,tasks[k]);
            if(status==NOT_REVIEWED) fout<<"\nNOT_REVIEWED";
            else if(status==CHANGES_PENDING) fout<<"\nCHANGES_PENDING\n";
            else fout<<"\nCOMPLETED\n";
            vector <string> changes = admin.get_changes(i,tasks[k]);
            if(changes.size()>0){
                for( int l=0 ; l<changes.size() ; ++l){
            
                    fout<<changes[l]<<endl;
                }
                fout<<"-1";
            }
            else{
                string date = admin.get_date(i,tasks[k]);

                fout<<date;
            }
        
        }
        
    
    }
    
    fout.close();
}

vector <string> extract_student_info(){

    ifstream fin;
    string line;

    fin.open("students.txt");
    getline(fin,line);
    vector <string> student_deets;
    while(getline(fin,line)){
        //cout<<line<<endl;
        string name = line;
        getline(fin,line); //cout<<line<<endl;
        string password = line;
        Student tempo(name, password);
        line = name + " " + password;
        student_deets.push_back(line);

        for( int i=0 ; i<tasks.size() ; ++i){
            
            S_Assignment_info tmp;
            getline(fin,line);//cout<<line<<endl;
            if(line=="NOT_REVIEWED")tmp.set_status(NOT_REVIEWED);
            else if(line=="COMPLETED"){
                getline(fin,line);//cout<<line<<endl;
                tmp.set_info(COMPLETED,line);
            }
            else{
                vector <string> temp;

                while(1){
                    getline(fin,line);//cout<<line<<endl;
                    if(line == "-1") break;
                    temp.push_back(line); 
                }
                tmp.set_info(CHANGES_PENDING, temp);
            }
            tempo.add_assignment(tmp,tasks[i]);
        
        }
        admin.add_student(tempo);
        line ="";
    }

    fin.close();

    return student_deets;

}

int main(){

    

    //caching
    ifstream fin;
    fin.open("assignments.txt");
    string line;
    getline(fin,line);
    while(getline(fin,line)){
        string name , deadline;
        name = line;
        getline(fin,line);
        deadline=line;
        Assignment tmp(name,deadline);
        tasks.push_back(tmp);
    }
    fin.close();

    // for( int i=0 ; i<tasks.size() ; ++i){
    
    //     cout<<tasks[i].get_name()<<endl;
    
    // }

    line = "";
    //cout<<tasks.size();

    vector <string> student_deets = extract_student_info();
    
    fin.open("reviewers.txt",ios::app);
    vector <string> reviewer_deets;

    while(1){
        getline(fin,line);
        if(line=="-1") break;
        reviewer_deets.push_back(line);
    }

    line = "";

    while(1){
        getline(fin,line);
        if(line=="-1") break;
        admin.add_link(line);
    }

    while(1){
        getline(fin,line);
        if(line=="-1") break;
        admin.add_doubt(line);
    }



    bool exit = false;

    fin.close();

    

    while(!exit){

        cout<<"Welcome to ReviewEz!!\n\n\n";
        cout<<"Press:\n";
        cout<<"1 to LOG IN as STUDENT"<<endl;
        cout<<"2 to SIGN UP as STUDENT\n";
        cout<<"3 to LOG IN as REVIEWER"<<endl;
        cout<<"4 to SIGN UP as REVIEWER\n";
        cout<<"5 to EXIT\n";

        int a;
        cin>>a;

        if(a==1){
            cout<<"Enter your name: ";
            string name;
            cin>>name;
            cout<<"Enter password: ";
            string password;
            cin>>password;
            int flag = 1;
            for( int i=0 ; i<student_deets.size() && flag ; ++i){
                string tmp = name + " " + password;
                if(student_deets[i]==tmp){
                    flag = 0;
                    int login = 1;
                    while(login){

                        cout<<"\n\nWelcome "<<name<<"!\n";
                        cout<<"Press:\n";
                        cout<<"1 to see number of pending assignments\n";
                        cout<<"2 to see details of pending assignments in short\n";
                        cout<<"3 to see details of pending assignments in long\n";
                        cout<<"4 to see details of a particular assignment\n";
                        cout<<"5 to see list of completed assignments\n";
                        cout<<"6 to submit an assignment\n";
                        cout<<"7 to ask a doubt\n";
                        cout<<"8 to log out\n";
                        
                        cin>>a;
                        
                        student_deets = extract_student_info();
                        admin.student_functions(i,a,login);

                    }
                    

                }
            
            }
            if(flag) cout<<"WRONG ID OR PASSWORD\n\n";
        }
        else if(a==2){

            cout<<"Enter your name: ";
            string name;
            cin>>name;
            cout<<"Enter password: ";
            string password;
            cin>>password;

            Student tmp(name, password);

            admin.add_student(tmp);
            student_deets.push_back(name+" "+password);

            save_student_info(student_deets);

            // ofstream fout;
            // fout.open("students.txt", ios::app);
            // fout<<name<<endl;
            // fout<<password<<endl;


        }
        else if(a==3){
            cout<<"Enter your name: ";
            string name;
            cin>>name;
            cout<<"Enter password: ";
            string password;
            cin>>password;
            int flag = 1;
            for( int i=0 ; i<reviewer_deets.size() && flag ; ++i){
                string tmp = name + " " + password;
                if(reviewer_deets[i]==tmp){
                    flag = 0;
                    int login = 1;
                    while(login){
                        cout<<"\n\nWelcome "<<name<<"!\n\n";
                        cout<<"Press:\n";
                        cout<<"1 to see total number of assignments.\n";
                        cout<<"2 to display student status\n";
                        cout<<"3 to display student status of an assignment\n";
                        cout<<"4 to display assignment deadlines\n";
                        cout<<"5 to create an assignment\n";
                        cout<<"6 to display submissions\n";
                        cout<<"7 to display doubts\n";
                        cout<<"8 to delete a doubt\n";
                        cout<<"9 to add a change to assignment for a student\n";
                        cout<<"10 to change the progress status of a student for an assignment\n";
                        cout<<"11 to logout\n";

                        cin>>a;
                        int b;
                        string s1;
                        string s2;
                        Assignment tmp;
                        switch (a)
                        {
                        case 1:
                            cout<<tasks.size()<<endl;
                            break;
                        case 2:
                            cout<<"Enter student name: ";
                            cin>>s1;
                            admin.display_student_status(s1);
                            break;
                        case 3:
                            cout<<"Enter student name: ";
                            cin>>s1;
                            cout<<"Enter assignment number: ";
                            cin>>b;
                            student_deets = extract_student_info();
                            cout<<"Enter name of assignment: ";
                            cin>>s1;
                            cout<<"Enter deadline: ";
                            cin>>s2; 
                            tmp.set(s1 , s2);
                            tasks.push_back(tmp);
                            admin.create_assignment(tmp);
                            break;
                        case 6:
                            admin.display_submissions();
                            break;
                        case 7:
                            admin.display_doubts();
                            break;
                        case 8:
                            cout<<"Enter the doubt number: ";
                            cin>>b;
                            admin.delete_doubt(b);
                            break;
                        case 9:
                            cout<<"Enter name of student: ";
                            cin>>s1;
                            cout<<"Enter assignment number: ";
                            cin>>b;
                            cout<<"Enter change to be added:\n";
                            cin>>s2; 
                            admin.add_change(s1,s2,tasks[b-1]);
                            save_student_info(student_deets);
                            break;
                        case 10:
                            cout<<"Enter new progress status(not reviewed ,changes pending or completed): ";
                            cin>>s2;
                            cout<<"Enter assignment number: ";
                            cin>>b;
                            cout<<"Enter name of student: ";
                            cin>>s1;
                            admin.change_status(s1,s2,tasks[b-1]);
                            break;
                        case 11:
                            login = 0;
                            break;
                        default:
                            cout<<"WRONG INPUT\n\n";
                            break;
                        }
                    
                    }

                }
            
            }
            if(flag) cout<<"WRONG ID OR PASSWORD\n\n\n";
        }
        else if(a==4){

            cout<<"Enter your name: ";
            string name;
            cin>>name;
            cout<<"Enter password: ";
            string password;
            cin>>password;

            string tmp = name + " " + password;
            reviewer_deets.push_back(tmp);

        }
        else if(a==5){
            exit = true;
        }
        else{
            cout<<"ERROR...Wrong Input\n\n\n";
        }
    }

    ofstream fout;

    fout.open("assignments.txt");

    for( int i=0 ; i<tasks.size() ; ++i){
    
        fout<<endl<<tasks[i].get_name()<<endl;
        fout<<tasks[i].get_deadline();
    
    }
    fout.close();

    save_student_info(student_deets);

    fout.open("reviewers.txt");
    for( int i=0 ; i<reviewer_deets.size() ; ++i){
    
        fout<<reviewer_deets[i]<<endl;
    
    }
    fout<<"-1\n";

    admin.store_links(fout);
    fout<<"-1\n";

    admin.store_doubts(fout);
    fout<<"-1";
    fout.close();

    return 0;
}