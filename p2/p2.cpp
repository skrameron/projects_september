#include<iostream>
#include<vector>
#include<cctype>

using namespace std;

bool is_palindrome(string s);
//void count_palindromes()
bool read_input(vector<string> &v, string s);
void clear_input(string &s, string x, string y); 

int main()
{
    string a = " ";
    string b = ",";
    string c = "!";
    string d = "-";
    string e = ".";

    //string for capital letter

    //replacement string
    string x = "";
    string s;
    vector<string> v;

    while(read_input(v, s));

    //replacement function
    clear_input(string &s, a, x);
 /*   clear_input(string &s, b, x);
    clear_input(string &s, c, x);
    clear_input(string &s, d, x);
    clear_input(string &s, e, x);
    */
    cout << is_palindrome(s) << endl;

    return 0;
}

//function clears all special characters and changes upper to lower case

void clear_input(string &s, string a, string x)
{
    for(int i = 0; i <= s.length(); i++)
        if(s[i] == a)
        {
            s.substr(s[i], x);
        } else {
        tolower(s[i]);
        }
        cout << s;
}

bool read_input(vector<string> &v, string s)
{
    getline(cin, s);
    if(s == "quit")
    {
        return false;
    }else{
        v.push_back(s);
        return true;
    }
}
    //This function should return tru if v is a palindrome
    //Function must recognize a palindrome that has white spaces, dashes, comas
    //periods, exclamation marks or when capitals are used.
bool is_palindrome(string s)
{
    // calls the size of s once instead of every time the loop interrates
    int matches = 0;
    int size = s.size();
    for(int i = 0; i < size; i++){
        // checks to see if first position is equal to last position
        if(s[i] == s[size - 1 - i]){
            matches += 1;
        }
    }
    return (matches == size);
}
    /*
void count_palindromes(vector<string> v;)
{
    for(int i = 0; i < v.size(); i++)
        if(is_palindrome())
        {
          
        }
}
    */
