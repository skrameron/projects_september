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
    string s;
    while(getline(inf, s)){
        istringstream(s);
        while(!inf.eof()){
            employee emp;
            inf >> emp.last;
            inf >> emp.first;
            inf >> emp.salary;
            employees.push_back(emp);
    }
    }
    double_salary(employees);
    change_salary(employees);
    print(employees, out);

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

    cout << "enter last name" << " " << endl;
    cin >> lastn;
    cout << "enter first name" << " " << endl;
    cin >> firstn;

    for(int i = 0; i < employees.size(); i++){
        if((lastn == employees[i].last) && firstn == employees[i].first){
            cout << "enter new salary" << " " << endl;
            cin >> salaryn;
            employees[i].salary = salaryn;
        }
        cout << employees[i].salary << endl;
    }
}


void print( vector< employee > employees, ofstream &out)
{
    employee *ptr;

    for(int i = 0; i < employees.size(); i++){
        ptr->last[i]->first[i]->salary[i];
        }
}

