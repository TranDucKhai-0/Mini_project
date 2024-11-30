#include <iostream>
#include <windows.h>
#include "giaodien.h"
#include "Admin.h" // Bao gom tieu de cua lop StudentManager

using namespace std;

void loadingBar()
{
    Cursor(false);
    system("cls");
    system("color 70");

    char a = 177, b = 219;
    cout << "\n\n\n\n\n\t\t\t\t\tStudent's Data Management System";
    cout << "\n\t\t\t\t\tProject By Ajay Singh";
    cout << "\n\t\t\t\t\tRework by Sunless Team";
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
        Sleep(70);
    }
    Sleep(700); // chờ 0.7 giây
}

int main()
{
    loadingBar();
    StudentManager manager; // Tao doi tuong StudentManager

    int choice; // Chon

    do
    {
        system("cls");
        string nameMenu = "===== Student Management System =====";
        string Menu[] = {
            "Admin",
            "Student",
            "Exit"};                            // xuất menu có thể thao tác bằng phím
        int n = sizeof(Menu) / sizeof(Menu[0]); // lấy độ dài mảng
        choice = menu(nameMenu, Menu, n);       // chọn mục chức năng

        TextColor(MAUNEN);

        system("cls");
        if (choice == 1)
        { // Dang nhap admin
            Cursor(true);
            string adminPassword; // Bien mat khau admin
            cout << "\n\n\n\n\n\t\t\t\t\tEnter Admin Password: ";
            cin >> adminPassword; // Nhap mat khau admin pass: Admin123

            system("cls");
            if (manager.authenticateAdmin(adminPassword))
            {                    // Kiem tra mat khau admin
                int adminChoice; // Bien chon menu admin
                do
                {
                    Cursor(false); // tắt con trỏ
                    string nameMenu = "===== Admin Menu =====";
                    string Menu[] = {
                        "Add Student",           // Menu them sinh vien
                        "Update Scores",         // Menu cap nhat diem
                        "Update Class Schedule", // Menu cap nhat lich hoc
                        "Remove Class Schedule", // Menu xoa lich hoc
                        "View All Students",     // Menu xem danh sach sinh vien
                        "View All Tuition Fees by ID and Name",
                        "View All Class Schedules by ID and Name",
                        "Find Student by ID Name",
                        "Logout" // Dang xuat
                    }; // xuất menu có thể thao tác bằng phím
                    int n = sizeof(Menu) / sizeof(Menu[0]); // lấy độ dài mảng
                    adminChoice = menu(nameMenu, Menu, n);  // chọn mục chức năng

                    system("cls");
                    if (adminChoice == 1)
                    { // Them sinh vien moi
                        string id, name, major, password;
                        int age;
                        float tuitionFee;
                        Cursor(true); // bật con trỏ

                        cout << "\n\n\n\n\n\t\t\t\t\tEnter ID (MSV): ";
                        cin >> id; // Nhap ma sinh vien
                        cout << "\t\t\t\t\tEnter Name (Ten): ";
                        cin.ignore();
                        getline(cin, name); // Nhap ten sinh vien
                        cout << "\t\t\t\t\tEnter Age (Tuoi): ";
                        cin >> age; // Nhap tuoi sinh vien
                        cout << "\t\t\t\t\tEnter Major (Nganh hoc): ";
                        cin.ignore();
                        getline(cin, major); // Nhap nganh hoc sinh vien
                        cout << "\t\t\t\t\tEnter Tuition Fee (Hoc phi): ";
                        cin >> tuitionFee; // Nhap hoc phi
                        cout << "\t\t\t\t\tSet Password: ";
                        cin >> password; // Dat mat khau

                        Student newStudent(id, name, age, major, tuitionFee, password); // Tao sinh vien moi
                        manager.addStudent(newStudent);                                 // Them sinh vien vao danh sach
                        Sleep(400);
                        cout << "\n\t\t\t\t\tStudent added successfully!\n\n\t\t\t\t\t"; // Thong bao thanh cong

                        system("pause");
                    }
                    else if (adminChoice == 2)
                    {
                        string id, subject;
                        float score;
                        Cursor(true); // bật con trỏ
                        cout << "\n\n\n\n\n\t\t\t\t\tEnter Student ID: ";
                        cin >> id;

                        system("cls");
                        Student *student = manager.findStudent(id);
                        if (student)
                        {
                            cout << "\n\n\n\n\n\t\t\t\t\tStudent: " << student->getName() << endl;
                            cout << "\n\n\n\n\n\t\t\t\t\tEnter Subject: ";
                            cin >> subject;
                            cout << "\n\n\n\n\n\t\t\t\t\tEnter Score: ";
                            cin >> score;
                            student->updateScore(subject, score);
                            Sleep(400);
                            cout << "\n\n\n\n\n\t\t\t\t\tScore updated successfully!\n\n\t\t\t\t\t";
                            system("pause");
                        }
                        else
                        {
                            Cursor(false); // tat con trỏ
                            Sleep(200);
                            cout << "\n\n\n\n\n\t\t\t\t\tStudent not found!\n\t\t\t\t\t";
                            system("pause");
                        }
                    }
                    else if (adminChoice == 3)
                    {
                        string id, date, schedule;

                        Cursor(true); // bật con trỏ

                        cout << "\n\n\n\n\n\t\t\t\t\tEnter Student ID: ";
                        cin >> id;

                        system("cls");
                        Student *student = manager.findStudent(id);
                        if (student)
                        {
                            cout << "\n\n\n\n\n\t\t\t\t\tStudent: " << student->getName() << endl;
                            cout << "\n\n\n\n\n\t\t\t\t\tEnter Date: ";
                            cin >> date;
                            cout << "\n\n\n\n\n\t\t\t\t\tEnter New Schedule: ";
                            cin.ignore();
                            getline(cin, schedule);
                            student->updateClassSchedule(date, schedule);
                            Sleep(400);
                            cout << "\n\n\n\n\n\t\t\t\t\tSchedule updated successfully!\n\n\t\t\t\t\t";
                            system("pause");
                        }
                        else
                        {
                            Cursor(false); // tat con trỏ
                            Sleep(200);
                            cout << "\n\n\n\n\n\t\t\t\t\tStudent not found!\n\n\t\t\t\t\t";
                            system("pause");
                        }
                    }
                    else if (adminChoice == 4)
                    {
                        string id, date;

                        Cursor(true); // bật con trỏ

                        cout << "\n\n\n\n\n\t\t\t\t\tEnter Student ID: ";
                        cin >> id;

                        system("cls");
                        Student *student = manager.findStudent(id);
                        if (student)
                        {
                            cout << "\n\n\n\n\n\t\t\t\t\tStudent: " << student->getName() << endl;
                            cout << "\n\n\n\n\n\t\t\t\t\tEnter Date to Remove Schedule: ";
                            cin >> date;
                            student->removeClassSchedule(date);
                        }
                        else
                        {
                            Cursor(false); // tat con trỏ
                            Sleep(200);
                            cout << "\n\n\n\n\n\t\t\t\t\tStudent not found!\n\n\t\t\t\t\t";
                            system("pause");
                        }
                    }
                    else if (adminChoice == 5)
                    {
                        manager.displayAllStudents();
                        cout << "\n\t\t\t\t\t";
                        system("pause");
                    }
                    else if (adminChoice == 6)
                    {
                        manager.displayAllTuitionFees();
                        cout << "\n\t\t\t\t\t";
                        system("pause");
                    }
                    else if (adminChoice == 7)
                    {
                        manager.displayAllClassSchedules();
                        cout << "\n\t\t\t\t\t";
                        system("pause");
                    }
                    else if (adminChoice == 8)
                    {
                        Cursor(true); // bật con trỏ
                        string input;
                        cout << "\n\n\n\n\n\t\t\t\t\tEnter Student ID / Name : ";
                        cin.ignore();
                        getline(cin, input);

                        Student *student = manager.findStudent(input);
                        if (student)
                        {
                            Cursor(false);
                            student->displayPersonalInfo();
                            cout << "\n\t\t\t\t\t";
                            system("pause");
                        }
                        else
                        {
                            Cursor(false); // tat con trỏ
                            Sleep(200);
                            cout << "\n\n\n\n\n\t\t\t\t\tNot found! \n\n\t\t\t\t\t";
                            system("pause");
                        }
                    }
                } while (adminChoice != 9); // nếu chọn 9 là logout
            }
            else
            {
                Sleep(100);
                cout << "\n\n\n\n\n\t\t\t\t\tIncorrect admin password!\n\n\t\t\t\t\t";
                system("pause");
            }
        }
        else if (choice == 2)
        {
            Cursor(true); // bat con tro
            string studentId, password;
            cout << "\n\n\n\n\n\t\t\t\t\tEnter Student ID: ";
            cin >> studentId;

            Student *student = manager.findStudent(studentId);
            if (student)
            {
                system("cls");
                cout << "\n\n\n\n\n\t\t\t\t\tEnter Password: ";
                cin >> password;

                if (student->authenticate(password))
                {
                    system("cls");
                    Cursor(false);
                    int studentChoice;
                    do
                    {
                        string Menu[] = {
                            "View Personal Information",
                            "View Tuition Fee",
                            "View Scores",
                            "View Class Schedule",
                            "Logout"};                          // xuất menu có thể thao tác bằng phím
                        int n = sizeof(Menu) / sizeof(Menu[0]); // lấy độ dài mảng
                        string nameMenu = "===== Student Menu =====";
                        studentChoice = menu(nameMenu, Menu, n); // chọn mục chức năng

                        system("cls");
                        Cursor(false);
                        if (studentChoice == 1)
                        {
                            student->displayPersonalInfo();
                            cout << "\n\n\t\t\t\t\t";
                            system("pause");
                        }
                        else if (studentChoice == 2)
                        {
                            student->displayTuitionFee();
                            cout << "\n\n\t\t\t\t\t";
                            system("pause");
                        }
                        else if (studentChoice == 3)
                        {
                            student->displayScores();
                            cout << "\n\n\t\t\t\t\t";
                            system("pause");
                        }
                        else if (studentChoice == 4)
                        {
                            student->displayClassSchedule();
                            cout << "\n\n\t\t\t\t\t";
                            system("pause");
                        }
                    } while (studentChoice != 5); // chon 5 là logout
                }
                else
                {
                    Cursor(false);
                    cout << "\n\n\n\n\n\t\t\t\t\tIncorrect password!\n\n\t\t\t\t\t";
                    system("pause");
                }
            }
            else
            {
                Cursor(false);
                cout << "\n\n\n\n\n\t\t\t\t\tStudent not found!\n\n\t\t\t\t\t";
                system("pause");
            }
        }
    } while (choice != 3);

    system("cls");
    cout << "\n\n\n\n\n\t\t\t\t\tExiting program. Goodbye!\n";
    Sleep(1000);
    return 0;
}
