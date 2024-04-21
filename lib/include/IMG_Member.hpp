#ifndef IMG_MEMBER_HPP
#define IMG_MEMBER_HPP

#include <iostream>
#include <string>

using namespace std;

class IMG_Member
{
private:
    string name;
    string password;
public:
    IMG_Member(){}
    IMG_Member(string name, string password);
    void set_name(string name, string password);
    string get_name();
};

 

#endif