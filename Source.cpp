#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
* takes in username and password and creates .txt file
* checks if username and passwrod are match
**/

bool loggedIn()
{
	string username;
	string password;
	string user;
	string pass;

	cout << "Enter username: "; cin >> username;
	cout << "Enter passwordL "; cin >> password;

	ifstream read(username + ".txt");
	getline(read, user);
	getline(read, pass);
	
	if (user == username && pass == password)
	{
		return true;
	}
	else
	{
		return false;
	}


}

/**
* takes in username and password and creates .txt file
**/

int main()
{
	int choice;

	cout << "1: Sign up \n";
	cout << "2. Login \n";
	cout << "Your choice: ";
	cin >> choice;

	if (choice == 1)
	{
		string username;
		string password;

		cout << "select a username: ";
		cin >> username;
		cout << "select a password ";
		cin >> password;

		ofstream file;
		file.open(username + ".txt");
		file << username << endl << password;
		file.close();

		main();
	}

/**
* checks if username and passwrod are valid, if so,
* then continue on with file creation
**/

	else if (choice == 2)
	{
		bool status = loggedIn();

		if (!status)
		{
			cout << "Wrong username or password" << endl;
			system("PAUSE");
			return 0;
		}
		else
		{
			cout << "succesfully logged in!" << endl;
			system("PAUSE");
			return 1;
		}
	}
}
