#include<string>
#include<vector>

//macros
#ifndef COURSE_H
#define COURSE_H

class Course{
    public:
        Course(string aname, vector<string> prereq);

        string get_name();
        //member function that returns name
        void get_prereq(vector<string> &prereqs);
        //this function returns a copy of prerequisites by modifying
        //prereqs passed-by-reference as a parameter
        void print();
        //this function prints the courses name and its prerequisites in 
        //this format

    private:
        string name;
        vector<string> prerequisites;
};

#endif
