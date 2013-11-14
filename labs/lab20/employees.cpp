#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<iomanip>

using namespace std;

struct employee
{
    string last;
    string first;
    double salary;
};

void double_salary( vector< employee > &employees);
void change_salary( vector< employee > &employees);
void print( vector< employee > employees, ofstream &out);

int main()
{
    vector<employee> employees;
    ifstream inf;
    ofstream out;
    string output = "updated_employees.txt";
    out.open(output.c_str() );

    inf.open("employees.txt");
    /*
    string s;
    while(getline(inf, s)){
        istringstream(s);
        */
        while(!inf.eof()){
            employee emp;
            inf >> emp.last;
            inf >> emp.first;
            inf >> emp.salary;
            employees.push_back(emp);
    }
    double_salary(employees);
    change_salary(employees);
    print(employees, out);

    inf.close();

    return 0;
}

void double_salary( vector< employee > &employees)
{
    for(int i = 0; i < employees.size(); i++){
        employees[i].salary = employees[i].salary * 2;
        cout << employees[i].salary << endl;
    }
}

void change_salary( vector< employee > &employees)
{
    string lastn;
    string firstn;
    double salaryn;

    cout << "enter last name, first name, and new salary" << " " << endl;
    cin >> lastn >> firstn >> salaryn;

    for(int i = 0; i < employees.size(); i++){
        if((employees[i].last == lastn) && (employees[i].first == firstn)){
            employees[i].salary = salaryn;
        }
    }
}


void print( vector< employee > employees, ofstream &out)
{
    employee *ptr = &employees[0];

    for(int i = 0; i < employees.size(); i++){
        out << setw(15) << std::right << ptr->last << ptr->first << ptr->salary << endl;
        ptr ++;
        }
}

