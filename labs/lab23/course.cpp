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



