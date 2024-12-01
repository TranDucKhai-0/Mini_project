#ifndef STUDENT_H
#define STUDENT_H

#include <string>   // Bao gom thu vien lam viec voi chuoi
#include <map>      // Bao gom thu vien lam viec voi bang

using namespace std;

// Lop dai dien cho sinh vien
class Student {
private:
    string id;                           // Ma sinh vien
    string name;                         // Ten sinh vien
    int age;                             // Tuoi sinh vien
    string major;                        // Nganh hoc
    float tuitionFee;                    // Hoc phi
    string password;                     // Mat khau cua sinh vien
    map<string, float> scores;           // Danh sach diem cua sinh vien (Mon/ Diem)
    map<string, string> classSchedule;   // Lich hoc cua sinh vien (Ngay : ND)

public:
    Student(string studentId, string studentName, int studentAge, string studentMajor, int fee, string pwd);
    string getId() const;                // Lay ma sinh vien
    string getName() const;// Lay ten sinh vien
    float getTuitionFee() const;        // Thong tin hp      
    bool authenticate(const string& inputPassword) const;  // Xac thuc mat khau sinh vien

    void displayPersonalInfo() const;    // Hien thi thong tin ca nhan sinh vien
    void displayTuitionFee() const;      // Hien thi hoc phi cua sinh vien
    void displayScores() const;          // Hien thi diem cua sinh vien
    void displayClassSchedule() const;   // Hien thi lich hoc cua sinh vien

    void updateScore(const string& subject, float score);  // Cap nhat diem cua sinh vien
    void updateClassSchedule(const string& date, const string& schedule);  // Cap nhat lich hoc cua sinh vien
    void removeClassSchedule(const string& date);  // Xoa lich hoc cua sinh vien
};

#endif
