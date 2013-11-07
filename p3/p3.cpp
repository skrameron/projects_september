#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<iomanip>

using namespace std;

//instead of two arrays, name and pos, always address the objects together, 
//only interested in working with them together.
struct subject
{
    int position;
    string name;
};

void fill_vector(vector<subject> &subs, ifstream &inf);
vector<string> subject_to_names(vector<subject> subs);
void print_sorted_positions(vector<subject> subs);
void print_number_of_names(vector<subject> subs);
void print(vector<string> names, string *ptr1, string *ptr2);

int main(int argc, char* argv[])
{
    vector<subject> subs;
    ifstream inf;

    inf.open("input_names.txt");
    fill_vector(subs, inf);
    inf.close();

    print_sorted_positions(subs);
    print_number_of_names(subs);
    print(subject_to_names(subs), NULL, NULL);

    return 0;
}

void fill_vector(vector<subject> &subs, ifstream &inf)
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

vector<string> subject_to_names(vector<subject> subs)
{
    vector<string> names;
    for(int i = 0; i < subs.size(); i++)
        names.push_back(subs[i].name);
    return names;
}

void print_sorted_positions(vector<subject> subs)
{
    vector<string> sorted_subs;
    sorted_subs.resize(subs.size());
    for(int i = 0; i < subs.size(); i++)
        sorted_subs[subs[i].position - 1] = subs[i].name;
    for(int j = 0; j < sorted_subs.size(); j++)
        cout << sorted_subs[j] << endl;
}

void print_number_of_names(vector<subject> subs)
{
    ofstream outf;
    string output = "distinct_count.txt";
    outf.open(output.c_str() );

    vector<subject> sub_counts;
    for(int i = 0; i < subs.size(); i++){
        //havent found a match
        bool found = false;
        for(int j = 0; j < sub_counts.size(); j++){
            if(sub_counts[j].name == subs[i].name){
                found = true;
                sub_counts[j].position = sub_counts[j].position + 1;
            }
        }
        if(!found){
            subject newsubject;
            newsubject.name = subs[i].name;
            newsubject.position = 1;
            sub_counts.push_back(newsubject);
        }
    }
    for(int k = 0; k < sub_counts.size(); k++){
        outf << setw(20) << sub_counts[k].name << string(6,' ')
             << sub_counts[k].position << endl;
      //  cout << setw(20);
        //cout << sub_counts[k].name << string(6,' ') << sub_counts[k].position << endl;
    }
}

void print(vector<string> names, string *ptr1, string *ptr2)
{
    bool is_even = names.size() % 2 == 0;
    int middle = names.size()/2;
    string *last;

    if(!is_even)
        middle++;
    last = &names[middle];

    if(ptr1 == NULL)
        ptr1 = &names[0];
    else
        ptr1++;
    if(ptr2 == NULL)
        ptr2 = &names[names.size() - 1];
    else
        ptr2--;
    
    cout << setw(20);
    if((ptr1 == last) && !is_even){ 
        cout << *ptr1 << endl;
        return; 
    } else if((ptr2 == last) && is_even){
        cout << *ptr1 << string(6,' ') << *ptr2 << endl;
        return;
    }
    cout << *ptr1 << string(6,' ') << *ptr2 << endl;

    print(names, ptr1, ptr2);
}
