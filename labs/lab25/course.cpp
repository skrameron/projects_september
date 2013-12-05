#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

#include "course.h"

Course::Course(string aname, vector<string> prereq){
    name = aname;
    prerequisites = prereq;
}

string Course::get_name(){
    return name;
}

void Course::get_prereq(vector<string> &prereqs){
    for(int i = 0; i < prerequisites.size(); i++)
        prereqs.push_back(prerequisites.at(i));
}

void Course::print(){
    cout << "Course: " << name << endl;
    cout << "Prerequisites: ";

    for(int i = 0; i < prerequisites.size(); i++){
        cout << prerequisites.at(i) << " ";
    } 
    cout << endl;
}

ifstream &operator>>(ifstream &input, Course &some){
    string s;
    getline(input, s);
    istringstream istr(s);
    istr >> some.name;
    vector<string> prereqs;
    while(!istr.eof()){
        istr >> s;
        if(s != "")
            prereqs.push_back(s);            
    }

    some.prerequisites = prereqs;
    return input;
}

ostream &operator<<(ostream &out, Course &some){
    out << "Course: " << some.name << endl;
    out << "Prerequisites: ";
    
    for(int i = 0; i < some.prerequisites.size(); i++){
        out << some.prerequisites.at(i) << " ";
    }
    out << endl;
}
   
/*
bool Course::operator<( courseTwo &newCourse ){
    if(get_name() < newCourse.get_name())
        return true;
    else
        return false;
}
*/

