#include<iostream>
#include<sstream>
#include<fstream>

using namespace std;

struct subject
{
    int position;
    string name;
};

void fill_vector(vector<subject> subs, ifstream &inf);

int main(int argc, char* argv[])
{
    vector<subject> subs;
    ifstream inf;

    inf.open("input_names.txt");
    fill_vector(subs, inf);
    inf.close();
    for(int i = 0; i < subs.length(); i++)
        cout << subs[i] << endl;
    return 0;
}

void fill_vector(vector<subject> subs, ifstream &inf)
{
    string s;
    while(getline(inf, s)){    
        istringstream instr(s);
        while(!instr.eof()){
            subject newsub;
            instr >> newsub.position;
            if(instr.eof())
                break;
            instr >> newsub.name;
            subs.push_back(newsub);
        }
    }   
}
