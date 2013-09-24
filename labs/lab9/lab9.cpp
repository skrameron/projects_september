#include<iostream>
#include<string>
#include<cctype>
using namespace std;

void str_to_upper(string &s);
void reverse(string &s);
void replace(string &s, char x, char y);

int main()
{
    string s;
    cout << "Welcome to editor. Please enter your first sentence or *quit* to end." << endl;
    getline(cin, s);

    while(s != "quit"){
        cout << "Please choose an editing operation:"
             << "\nH to replace all characters x with characters y"
             << "\nR to reverse the sentence"
             << "\nU to change the sentence to upper case."
             << "\nS to replace substrings s1 with s2." << endl;
        char inp;
        cin >> inp;
        cin.ignore();
        int counter = 1;
        while(inp != 'H' && inp != 'R' && inp != 'U'){
            if(counter >= 3)
            {
                return 0;
            }//if
            cout << "Please use H, R or U to specify the editing choice. Please try again." << endl;
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
        }
        /*
        case 'S':
            string one;
            string two;
            cout << "Please enter the first substring" << endl;
            getline(cin, one);
            cout << "Please enter the second substring" << endl;
            getline(cin, two);
            replace(s, one, two);
            cout << endl;
         //end of switch
        */
        cout << "Please enter next sentence or *quit* to end." << endl;
        getline(cin, s);
    }//while

    return 0;
}

void str_to_upper(string &s){
    for(int i = 0; i < s.length(); i++){
            s[i] = toupper(s[i]);
        }//for
}//str_to_upper()

void replace(string &s, char x, char y){
    for(int i = 0; i < s.length(); i++){
            if(s[i] == x)
                    s[i] = y;
        }//for
}//replace()
/*
void replace(string &s, string over, string load)
{
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == over[i])
        i++;
        char temp = over[i];
    }

}
*/
void reverse(string &s){
    for( int i=0, j=s.length()-1; i < j; i++, j--){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
