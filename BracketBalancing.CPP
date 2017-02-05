#include<iostream>
#include<fstream>
#include<string>
#include<vector>

int main() {
	char ch = ' ';
	bool isError = false;
	string recentlyOpened = "";
	char charc = ' ';
	string File_Name = "manoj.txt";
	ifstream ifs;
	ifs.open(File_Name);
	while (ifs.get(ch)) {
		if (ch == '{' || ch == '(' || ch == '[') {
			push(recentlyOpened, ch);
		}
		else if (ch == '}') {
			charc = pop(recentlyOpened);

			if (charc != '{') {
				cout << "fill out the" << ch << endl;
				isError = true;
			}
		}
		else if (ch == ')') {
			charc = pop(recentlyOpened);
			if (charc != '(') {
				cout << "fill out the" << ch << endl;
				isError = true;
			}
		}
		else if (ch == ']') {
			charc = pop(recentlyOpened);
			if (charc != '[') {
				cout << "fill out the" << ch << endl;
				isError = true;
			}
		}
	}

	if (isError == false) {
		cout << "Everything is perfect" << endl;
	}
	else {
		cout << "fix out the errors" << endl;
	}
	
	return 0;
}
