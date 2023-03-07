#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool Login()
{
	string username, password, un, pw;
	cout << "Enter username: "; cin >> username;
	cout << "Enter password: "; cin >> password;

	ifstream file(username + ".txt");
	getline(file, un);
	getline(file, pw);
	file.close();

	if (username == un && password == pw)
	{
		cout << "You have logged in!";
		return true;
	}
	else
	{
		cout << "Failed to log in! Please try again!";
		return false;
	}
}

int main()
{
	cout << "Log in into your account or register now.\n Please choose an option:\n 1.Register \n 2.Log in\n";
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		string username, password, confirmation;
		cout << "Select a username:"; cin >> username;
		cout << "Select a password:"; cin >> password;
		cout << "Confirm your password:"; cin >> confirmation;

		if (password != confirmation)
		{
			cout << "The password and the confirmation do not match! Please try again!\n";
			main();
		}
		else if (password == confirmation)
		{
			ofstream myfile(username + ".txt");
			myfile << username << endl;
			myfile << password << endl;
			myfile.close();
			cout << "Registration successful!\n";
			main();
		}
	}
	else if (choice == 2)
	{
		bool ok;
		ok = Login();

		if (ok == false) return 0;
		else if (ok == true) return 1;

	}
}