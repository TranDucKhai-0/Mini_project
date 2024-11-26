#include <iostream>
#include "loading.h"
#include <string>
#include <Windows.h>
#include "adminFunction.h"

using namespace std;

void passwordVerification(void);
void mainMenu(void);

//Xác thực Trước khi mở chương trình chính
void passwordVerification()
{
    system("cls");

    string password;

    cout << "\n\n\n\n\n\t\t\t\t\t";
    cout << "\n\n\n\t\t\t\t\tEnter Password : ";

    do
    {
        cin >> password;

        if (password != "password")
        {
            system("cls");
            cout << "\n\n\n\n\n\t\t"
                 << "wrong password!, try again or type 'quit' / 'exit' to Quit The program.";
            cout << "\n\n\n\t\t\t\t\tEnter Password : ";
        }

        if (password == "Quit" || password == "quit" || password == "exit" || password == "Exit" || password == "QUIT" || password == "EXIT")
        {
            system("cls");
            cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\tQuitting The Program";

            for (int i = 0; i < 4; i++)
            {

                Sleep(1000); // Tạm dừng 1 giây;
                cout << ".";
            }

            exit(0);
        }

    }

    while (password != "password");
    mainMenu(); // chức năng menu chính nằm trong Header File adminFunction.h 
}

int main() {
    // fast io
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    loadingBar(); // loadingBar() nằm trong tiêu đề loading.h để tải hoạt ảnh.
    system("color 9F");

    passwordVerification();
    return 0;
}
