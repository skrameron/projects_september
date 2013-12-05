#include<string>
#include<vector>

#ifndef CONTAINER_H
#define CONTAINER_H

using namespace std;

template<typename T>
class Container{ 
    public: 
        Container(string input_file);
        void print();
    private:
        vector<T> my_container;
};

#endif

