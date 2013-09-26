#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void str_to_upper(string &s);
void reverse(string &s);
void replace(string &s, char x, char y);
void replace(string &s, string target, string replacement);
void find(string s, string target);

int main()
{
    string s;
    cout << "Welcome to editor. Please enter your first sentence or *quit* to end." << endl;
    getline(cin, s);

    while(s != "quit")
    {
        cout << "Please choose an editing operation:"
             << "\nH to replace all characters x with characters y"
             << "\nR to reverse the sentence"
             << "\nU to change the sentence to upper case."
             << "\nS to replace substrings s1 with s2." << endl;
        char inp;
        cin >> inp;
        cin.ignore();
        int counter = 1;
        while(inp != 'H' && inp != 'R' && inp != 'U' && inp != 'S' )
        {
            if(counter >= 3)
            {
                return 0;
            }//if
            cout << "Please use H, R, U, or S to specify the editing choice. Please try again." << endl;
            counter++;
            cin >> inp;
            cin.ignore();
        }//while
        switch(inp)
        {
            case 'H':
                cout << "Please enter the first character:" << endl;
                char x, y;
                cin >> x;
                cout << "Please enter the second character" ;
                cin >> y;
                cin.ignore();
                replace(s, x, y);
                cout << s << endl;
            break;
            case 'R':
                reverse(s);
                cout << s << endl;
            break;
            case 'U':
                str_to_upper(s);
                cout << s << endl;
            break;
            case 'S':
                string target;
                string replacement;
                cout << "Please enter the first substring" << endl;
                getline(cin, target);
                cout << "Please enter the second substring" << endl;
                getline(cin, replacement);
                //replace(s, target, replacement);
                find(s, target);
                //replace(s, target, replacement);
                cout << endl;
            break;
        }
        cout << "Please enter next sentence or *quit* to end." << endl;
        getline(cin, s);
    }//while

    return 0;
}

void str_to_upper(string &s)
{
    for(int i = 0; i < s.length(); i++)
    {
        s[i] = toupper(s[i]);
    }//for
}//str_to_upper()

//this will return a pointer to the first ARRAYA
int possible_matches(string s, string target)
{
    if(s.length() < target.length())
        return 0;
    return (s.length() - target.length() + 1);
}

void replace(string &s, char x, char y)
{
    for(int i = 0; i < s.length(); i++)
    {
        if (s[i] == x)
            s[i] = y;
    }
}

void replace(string &s, string target, string replacement)
{
    string before = s.substr(s.length, target.length);
    string after = s.substr(start_after, len_after);

    for(int i = 0; i <= s.length() - target.length(); i++)
    {
        string current  = s.substr(i, target.length());
        if(current == target)
        {
            start_before = 0;
            start_after = target.length() + i;
            len_before = target[0];  
            len_after = len_before  
            before = s.substr(start_before, len_before);
            after = s.substr(start_after, len_after);
            s = before + replacement + after;
            i = i + replacement.length() - 1;
        }
        cout << s;
    }
}
*/
void reverse(string &s)
{
    for( int i=0, j=s.length()-1; i < j; i++, j--)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
