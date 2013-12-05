#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

#include "course.h"
#include "container.h"

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        cout << "Enter input file" << endl;
        exit(0);
    }
    string input_file = argv[1];

    Container<Course> courses(input_file);
    courses.print();

    return 0;
}

