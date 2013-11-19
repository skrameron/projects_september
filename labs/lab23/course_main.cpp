#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

#include "course.h"

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        cout << "Enter input file" << endl;
        exit(0);
    }

    vector<string> temp;

    string input_file = argv[1];
    ifstream inf;
    inf.open(input_file.c_str());

    string s;
    string name;
    string prereq;

    while(getline(inf, s)){
        istringstream instr(s);

        instr >> name;
        while(!instr.eof()){
            if(instr.eof())
                break;
            instr >> prereq;
            temp.push_back(prereq);
        }
    }
   
    Course newCourse (name, temp);
    cout << newCourse.get_name() << " ";

    vector<string> ptr;
    newCourse.get_prereq(ptr);
    for(int i = 0; i < ptr.size(); i++){
        cout << ptr.at(i) << " ";
    } 
    cout << endl;

    newCourse.print();
}

