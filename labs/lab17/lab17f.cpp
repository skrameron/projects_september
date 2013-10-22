#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

void print_vector( vector<int> v, ofstream &outf);
void square( vector<int> &v);
void fill_vector( vector<int> &v, ifstream &inf);

int main()
{
    vector<int> v;
    ifstream inf;
    ofstream outf;
    int x;

    inf.open("numbers.txt");
    if(!inf.is_open()){
        cout << "Cannot open file!\n" << endl;
        return 1;
    }

    fill_vector(v, inf);
    inf.close();
    square(v);
    string output = "squares.txt";
    outf.open(output.c_str() );
    print_vector(v, outf);

    return 0;
}

void fill_vector( vector<int> &v, ifstream &inf)
{
    int x;
    inf >> x;
    while(!inf.eof()){
        v.push_back(x);
        inf >> x;
    }
}

void square( vector<int> &v)
{
    for(int i = 0; i < v.size(); i++)
    v[i] =  v[i] * v[i];
}

void print_vector( vector<int> v, ofstream &outf)
{
    for(int i = 0; i < v.size(); i++)
        outf << v[i] << endl;
}

