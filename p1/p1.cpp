#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void replace(string input);
void reverse(string input);
void upper(string input);

int main()//no semi colon needed unless its the end of a function
{
    int tries = 0;
    bool first = true;
	string input, selection;
	cout << "Welcome to editor. Please enter your first sentence or *quit* to end." << endl;
    while (true)
    {
        if (first)
            first = false;
        else
            cout << "Please enter your next sentence or *quit* to end." << endl;
        getline(cin, input);
        if (input == "quit")
            return 0;
        cout << "Please choose an editing operation:\nH to replace all characters x with characters y\nR to reverse the sentence\nU to change the sentence to upper case." << endl;
        getline(cin, selection);
        if (selection[0] == 'H')
            replace(input);
        else if (selection[0] == 'R')
            reverse(input);
        else if (selection[0] == 'U')
            upper(input);
        else if (selection == "quit")
            return 0;
        else
        {
            tries++;
            cout << "Please use H, R or U to specify the editing choice. Please try again." << endl;
            if (tries == 3)
            {
               // returns an error
               return 1;
            }
        }
    }
}

void replace(string input)
{
	string original, replacement;
	cout << "Please enter the first character" << endl;
	getline(cin, original);
	cout << "Please enter the second character:" << endl;
	getline(cin, replacement);
    
	//for(unsigned int i = 0; i < input.length(); i++)
    for(int i = 0; i < input.length(); i++)
	{
		if  (input[i] == original[0])
			input[i] = replacement[0];
	}
	cout << input << endl;
	return;
}

void reverse(string input)
{
    for(int i = input.length()-1; i >= 0; i--)
    {
        cout << input[i];
    }
    cout << endl;
    return;
}

void upper(string input)
{    
    for(int i = 0; i < input.length(); i++)
    {
        input[i] = toupper(input[i]);
        cout << input[i];
    }
    cout << endl;
    return;
}
