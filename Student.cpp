#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(string studentId, string studentName, int studentAge, string studentMajor, int fee, string pwd)
    : id(studentId), name(studentName), age(studentAge), major(studentMajor), tuitionFee(fee), password(pwd) {}

string Student::getId() const { return id; }                // Ma sinh vien
string Student::getName() const { return name; }            // Ten sinh vien
int Student::getTuitionFee() const { return tuitionFee; } // hoc phi
bool Student::authenticate(const string &inputPassword) const
{
    return inputPassword == password; // Xac thuc mat khau cua sinh vien
}

void Student::displayPersonalInfo() const
{
    cout << "\n\n\t\t\t\t\tID: " << id;
    cout << "\n\t\t\t\t\t";
    cout << "Name: " << name;
    cout << "\n\t\t\t\t\t";
    cout << "Age: " << age;
    cout << "\n\t\t\t\t\t";
    cout << "Major: " << major << endl; // Hien thi thong tin ca nhan
}

void Student::displayTuitionFee() const
{
    cout << "\n\n\n\n\n\t\t\t\t\t";
    cout << "Tuition Fee for " << name << " (ID: " << id << "): " << tuitionFee << " VND" << endl; // Hien thi hoc phi
}

void Student::displayScores() const
{
    if (scores.empty())
    {                                                         // Neu danh sach diem rong
        cout << "\n\n\n\n\n\t\t\t\t\tNo scores available!\n"; // Thong bao khong co diem
    }
    else
    {
        cout << "\n\n\n\n\n\t\t\t\t\tScores:\n";
        for (const auto &entry : scores)
        {                                                                          // Duyet qua danh sach diem
            cout << "\t\t\t\t\t  " << entry.first << ": " << entry.second << endl; // Hien thi diem cua tung mon hoc
        }
    }
}

void Student::displayClassSchedule() const
{
    if (classSchedule.empty())
    {                                                         // Neu lich hoc rong
        cout << "\n\t\t\t\t\tNo class schedule available!\n"; // Thong bao khong co lich hoc
    }
    else
    {
        cout << "\n\t\t\t\t\tClass Schedule:\n";
        for (const auto &entry : classSchedule)
        {                                                                          // Duyet qua lich hoc
            cout << "\t\t\t\t\t  " << entry.first << ": " << entry.second << endl; // Hien thi lich hoc theo ngay
        }
    }
}

void Student::updateScore(const string &subject, float score)
{
    scores[subject] = score; // Cap nhat diem cho mon hoc
}

void Student::updateClassSchedule(const string &date, const string &schedule)
{
    classSchedule[date] = schedule; // Cap nhat lich hoc cho ngay
}

void Student::removeClassSchedule(const string &date)
{
    if (classSchedule.erase(date))
    {                                                                                       // Xoa lich hoc theo ngay
        cout << "\n\n\n\n\n\t\t\t\t\tSchedule on " << date << " removed successfully!\n\n"; // Thong bao xoa lich hoc thanh cong
    }
    else
    {
        cout << "\n\n\n\n\n\t\t\t\t\tNo schedule found on " << date << "!\n\n"; // Thong bao khong tim thay lich hoc
    }
}
