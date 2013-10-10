#include<iostream>
#include<string>
#include<cctype>
#include<vector>

using namespace std;

void fill_vector( vector<int> &v, int size);
void print_vector(vector<int> v);
bool is_prime(int x);

void print_array( int *primes, int size );
void collect_primes(vector<int> v, int *primes, int size);
int count_primes( vector<int> v);

int main()
{
    vector<int> v;
    int size = 100;
    fill_vector(v, 100);
    cout << "After initialization v:" << endl;
    print_vector(v );
    cout << endl;
    int total = count_primes(v);
//calculate how many elements will be in the array: call count_primes
//declare int pointer and use *new* to allocate memory for an array
    int *primes = new int[total];
//collect primes from vector to array: call collect_primes function
    collect_primes(v, primes, size);
//print primes from array
    print_array(primes, total);
//use *delete* to de-allocate (release) memory  
    delete [] primes;
    return 0;                         
}

void fill_vector( vector<int> &v, int size){
        for(int i = 0; i < size; i++){
                int y = 1 + rand() % 100;
                v.push_back(y);
        }
        //for
}//fill_vector

void print_vector( vector<int> v){
        for(int i = 0; i < v.size(); i++)
        cout << v[i] << " " ;
    cout << endl;
}
bool is_prime(int x){
        if(x <= 1)
                return false;
        for(int i = 2; i < x; i++){
                if(x % i == 0){//i divides x
                        return false;
                }
        }
        return true;
}
//ADD YOUR FUNCTIONS HERE
int count_primes( vector<int> v)
{
    int total = 0;
    for(int i = 0; i < v.size(); i++){
    if(is_prime(v[i])){
    total += 1;
    }
    }
    return total;   
}

void collect_primes(vector<int> v,int *primes,int size)
{
    int  j = 0;
    for(int i = 0; i < size; i++)
    {
    if(is_prime(v[i])){
    primes[j] = v[i];
    j++;
    }
    }
    
}
void print_array(int *primes, int size)
{
    for(int i = 0; i < size; i++){
       cout <<  primes[i] << " ";
    }
       cout << endl;
}

