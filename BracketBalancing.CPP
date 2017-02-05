#include<iostream>
#include<fstream>
#include<string>
void push(string &str, char ch)//This Function gets the character as input and then it adds to the end of string.
{
	str.push_back(ch);
}

char pop(string &str) //pops out the last character from the string and reutrns it.
{
	if (str.length() == 0) return ' ';

	char ch = str.back();

	str.pop_back();//pops out the last character in the string
	return ch;
}

int main() {
	char ch = ' '; //Character ch is initialized.
	bool isError = false; //Boolean variable is initialized to zero.
	string recentlyOpened = " ";// string recentlyopened is declared.
	char charc = ' '; //Character charc is initialized.
	string File_Name = "manoj.txt";//string recentlyopened is initialized.
	ifstream ifs;
	ifs.open(File_Name); //OPens the file
	while (ifs.get(ch)) // Reads all the characters, until the end of file.
	{
		if (ch == '{' || ch == '(' || ch == '[')//checks whether the characte r ch is either '{' or '(' or '[' 
		{
			push(recentlyOpened, ch); //pushes the character ch into the recentlyoepned string, by calling the push function.
		}
		else if (ch == '}') // checks whether the character ch is equal to '}'
		{
			charc = pop(recentlyOpened);// pop function is called , by passing the recentlyopened string as an argument, which returns the charc. 

			if (charc != '{') //checks whether the charc is equal to '{'
			{ 
				cout << "fill out the" << ch << endl; // Displays a message to fill out the missing character 
				isError = true; // isError value is set to true
			}
		}
		else if (ch == ')') // checks whether the character ch is equal to ')'
		{
			charc = pop(recentlyOpened);//pop function is called , by passing the recentlyopened string as an argument, which returns the charc. 
			if (charc != '(')//checks whether the charc is equal to '('
			{
				cout << "fill out the" << ch << endl;// Displays a message to fill out the missing character 
				isError = true; // isError value is set to true
			}
		}
		else if (ch == ']') // checks whether the character ch is equal to ']'
		{
			charc = pop(recentlyOpened);//pop function is called , by passing the recentlyopened string as an argument, which returns the charc. 
			if (charc != '[') 
			{
				cout << "fill out the" << ch << endl;// Displays a message to fill out the missing character 
				isError = true; // isError value is set to true
			}
		}
	}

	if (isError == false) // Checks whether the value of isError is False
	{
		cout << "Everything is perfect" << endl; // Dosplays a message, saying everything is perfect.
	}
	else //Chevks wther the vale of isError isn't equal to false
	{
		cout << "fix out the errors" << endl; //Dislays a message, saying that to fix out the errors.
	}
	
	return 0;
}
