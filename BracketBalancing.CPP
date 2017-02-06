#include<iostream>
#include<fstream>
#include<string>

using namespace std;

/*
This Function gets the character as input and then it adds to the end of string.
*/
void push(string &str, char ch)
{
	str.push_back(ch);
}

/*
This Function gets the character as input and then it adds to the end of string.
*/
char pop(string &str)
{
	if (str.length() == 0) return ' ';
	char ch = str.back();
	
     //pops out the last character in the string
	str.pop_back();
	return ch;
}

int main() {
	//Character ch is initialized.
	char ch = ' '; 
	//Boolean variable is initialized to zero.
	bool isError = false; 
	// string recentlyopened is declared.
	string recentlyOpened = "";
	//Character charc is initialized.
	char charc = ' '; 
	//string file_name is initialized.
	string File_Name = "source.txt";
	
	ifstream file(File_Name);
	//Checks whether the file is valid
	if (file.good()) {
		ifstream ifs;
		//opens the file
		ifs.open(File_Name);
		// Reads all the characters, until the end of file. 
		
		while (ifs.get(ch)) 
		{
			//checks whether the characte r ch is either '{' or '(' or '[' 
			if (ch == '{' || ch == '(' || ch == '[')
			{
				//pushes the character ch into the recentlyoepned string, by calling the push function.
				push(recentlyOpened, ch); 
			}
			 // checks whether the character ch is equal to '}'
			else if (ch == '}')
			{
				// pop function is called , by passing the recentlyopened string as an argument, which returns the charc.
				charc = pop(recentlyOpened); 
	             //checks whether the charc is equal to '{'
				if (charc != '{') 
				{
				// Displays a message to fill out the missing character 
					cout << "fill out the" << ch << endl;  
					// isError value is set to true
					isError = true; 
				}
			}
			// checks whether the character ch is equal to ')'
			else if (ch == ')') 
			{
				//pop function is called , by passing the recentlyopened string as an argument, which returns the charc. 
				charc = pop(recentlyOpened);
				//checks whether the charc is equal to '('
				if (charc != '(')
				{
					// Displays a message to fill out the missing character
					cout << "fill out the" << ch << endl; 
					// isError value is set to true
					isError = true; 
				}
			}
			// checks whether the character ch is equal to ']'
			else if (ch == ']') 
			{
				//pop function is called , by passing the recentlyopened string as an argument, which returns the charc. 
				charc = pop(recentlyOpened);
				if (charc != '[') 
				{
					// Displays a message to fill out the missing character
					cout << "fill out the" << ch << endl;
					//isError value is set to true 
					isError = true; // 
				}
			}
		}
		
		if(recentlyOpened.length() != 0 ) {
			while(recentlyOpened.length() != 0) {
				charc = pop(recentlyOpened);
				cout << charc << " is not properly closed" << endl;
			}
			isError = true;
		}
		
		// Checks whether the value of isError is False
		if (isError == false) 
		{
			// Dosplays a message, saying everything is perfect.
			cout << "Everything is perfect" << endl; 
		}
		//Chevks wther the vale of isError isn't equal to false
		else 
		{
			//Dislays a message, saying that to fix out the errors.
			cout << "fix all errors" << endl; 
		}
	} else {
		cout << "File does not exist";
	}
	
	return 0;
}

