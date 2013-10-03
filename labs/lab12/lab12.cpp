#include <iostream>
#include <vector>
#include <cmath>
#include <cctype>

using namespace std;

void str_to_upper(string &s);
void reverse(string &s);
bool is_palindrome(string s);
void fill_vector( vector<string> &v);
void print_vector( vector<string> v );
void print_palindromes( vector<string> v);
void change_to_upper(vector<string> &v);

int main() 
{ 
    const int size = 10; 
    vector<string> v(size); 
    cout << "Please enter 10 strings:" << endl << endl; 
    fill_vector(v); 
    cout << "After initialization:" << endl; 
    print_vector(v); 
    cout << endl; 
    cout << "Found palindromes in the vector:" << endl; 
    print_palindromes(v); 
    cout << endl; 
    cout << endl; 
    cout << "After changing strings to upper case:" << endl; 
    change_to_upper(v);
    cout << endl; 
    return 0;
}

void fill_vector(vector<string> &v)
{
    for(int i = 0; i < v.size(); i ++)
    {
        getline(cin,v[i]);
    }
}


bool is_palindrome(string s)
{
    string rev = s;
    reverse(rev);//now string rev is reversed of s
    if(rev == s)
    return true;
    else
    return false;
}

void print_palindromes(vector<string> v)
{
    for(int i = 0; i < v.size(); i++)
    {
        if(is_palindrome(v[i]) == true)
            cout << v[i] << endl;
    }
   // cout << endl;
}

void str_to_upper(string &s)
{
    for(int i = 0; i < s.length(); i++)
    {
    s[i] = toupper(s[i]);
    }//for
}

void change_to_upper(vector<string> &v)
{
    for(int i = 0; i < v.size(); i++)
    {
    str_to_upper(v[i]);
    cout << v[i] << endl;
     }
}

void print_vector( vector<string> v)
{
    for(int i = 0; i < v.size(); i++)
    cout << v[i] << endl;
}

void reverse(string &s)
{
    for( int i=0, j=s.length()-1; i < j; i++, j--)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
