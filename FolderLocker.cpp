#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <conio.h>


int Lock();
int Unlock();
std::string getPassword();

int main() {

	std::cout << "Welcome to Folder Locker: ....\nWhat do you want to do?"
		<< "\n1: Look\n2: Unlock\n> ";
	char choice;
	choice = _getch();
	if (choice == '1') {
		Lock();
	}
	else if (choice == '2') {
		std::string pass = "";
		std::cout << "\nEnter your Password: ";
		pass = getPassword();
		if (pass == "1234") {
			Unlock();
		}
		else {
			std::cout << "Password is incorrect";
		}
	}
	else {
		std::cout << "\n Invalid Choice";
	}

	return 0;
}


int Lock() {
	system("ren Folder.zip Keeper.ans");
	system("attrib +h +s Keeper.ans");
	return 0;
}

int Unlock() {
	system("attrib -s -h Keeper.ans");
	system("ren Keeper.ans Folder.zip");
	return 0;
}

std::string getPassword() {
	std::string password = "";
	char ch;
	ch = _getch();
	while (ch != 13) {
		if (ch != 8) {
			password.push_back(ch);
			std::cout << "*";
		}
		else if (password.length() > 0) {
			password.pop_back();
			std::cout << "\b \b";
		}
		ch = _getch();
	}

	return password;
}


