#include <iostream>
#include <string>
#include "/home/anmol/IMG-Assignments/oops/lib/include/IMG_Member.hpp"

using namespace std;

IMG_Member::IMG_Member(string name, string password)
{
    this->name = name;
    this->password = password;
}

void IMG_Member::set_name(string name , string password){
    this->name = name;
    this->password = password;
}

string IMG_Member::get_name(){
    return name;
}