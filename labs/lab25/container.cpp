#include<string>
#include<iostream>
#include<ifstream>

using namespace std;

#include "container.h"

template<typename T>
Container<T>::Container(string input_file){
    ifstream inf;
    inf.open( input_file.c_str() );
    T object;
    inf >> object;
    while( !inf.eof()){
        my_container.push_back(object);
        inf >> object;
    }
    inf.close();
}

template<typename T>
void Container<T>::print()
{
    for(int i = 0; i < my_container.size(); i++)
        cout << my_container[i] << endl;
}

