#ifndef LOADING_H
#define LOADING_h

#include <iostream>
#include <windows.h>
#include "adminFunction.h"

using namespace std;

void mainMenu(void);

const string PASSWORD = "Khaideptrai" ;


void loadingBar()
{
	system("cls");
	system("color 3F");

	char a = 177, b = 219;
	cout << "\n\n\n\n\n\t\t\t\t\tStudent's Data Management System";
	cout << "\n\t\t\t\t\tProject By Ajay Singh";
	cout << "\n\n\n\t\t\t\t\tLoading...\n"
		 << endl;
	cout << "\t\t\t\t\t";

	for (int i = 0; i < 26; i++)

		cout << a;

	cout << "\r";
	cout << "\t\t\t\t\t";
	for (int i = 0; i < 26; i++)
	{
		cout << b;
		Sleep(200);
	}
	Sleep(1000); // chờ 1 giây
    mainMenu();

}

#endif