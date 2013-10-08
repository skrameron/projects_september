#include<iostream>
#include<string>
#include<cctype>
#include<vector>

using namespace std;

void fill_vector( vector< vector<int> > &v);
void print_vector( vector< vector<int> > v );
int total_elements( vector< vector<int> > v);
void print_array( int *ptr, int rows, int columns);

int main()
{
    vector< vector<int> > v;
    cout << "Please enter rows of numbers" << endl 
    <<"Enter -1 at the end of each row, and -2 to quit" << endl;
    fill_vector(v);

    cout << "After initialization:" << endl;
    print_vector(v );//pointer is passed by value
    cout << endl;

    int size = total_elements(v);
    cout << "total elements = " << size << endl << endl;

    //another way to initialize 2D-array:
    int rows = 3, columns = 2;
    int a[3][2] = { {1, 2}, {11, 12}, {21, 22} };

    int *ptr = &a[0][0];//to the first element in the first row
    print_array(ptr, rows, columns);

    return 0;                         
}

void fill_vector( vector< vector<int> > &v)
{
    int i = 0;
    while(true){ 
    bool quit = true;
    vector<int> temp;
    while(true){
        int x;
        cin >> x; 
        if(x == -2){
            quit = false;
            //check if temp is not empty, add it to v
            if(temp.size() != 0)
                v.push_back(temp);
            break;
        }//if
        else if(x == -1)
            break;
        temp.push_back(x);
    }//while
    if(quit == false)
        break;
    v.push_back(temp);
    i++;//we don't use this, just for explanation
   }//while
}//fill_vector

void print_vector(vector< vector<int> > v ){
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            cout << v[i][j] << " " ;
        }//for j
        cout << endl;//after each row
    }//for i
}
int total_elements(vector< vector<int> > v ){
    int total = 0;
    for(int i = 0; i < v.size(); i++){
        total += v[i].size();
    }
    return total;
}

void print_array( int *ptr, int rows, int col)
{
   // for(int i = 0; i < col; i++)
   // *ptr = &col[0];
   //{

   //}
      cout << &ptr[0][0];
}//print_array

