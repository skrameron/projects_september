#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void replace(string input);
void reverse(string input);
void upper(string input);

int main()//no semi colon needed unless its the end of a function
{
	string input, selection;
	cout << "Welcome to editor. Please enter your first sentence or *quit* to end." << endl;
	getline(cin, input);
	cout << "Please choose an editing operation:\nH to replace all characters x with characters y\nR      to reverse the sentence\nU to change the sentence to upper case." << endl;
	
	cout << "Please use H, R or U to specify the editing choice. Please try again." << endl;
	getline(cin, selection);

	if (selection[0] == 'H')
	{
		replace(input);
    }
    else if (selection[0] == 'R')
    {
        reverse(input);
    }
    else if (selection[0] == 'U')
    {
        upper(input);
    }
    cout << "Please enter next sentence or *quit* to end." << endl;
	
	return 0;

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
		{
			input[i] = replacement[0];
		}
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
	return;
}
