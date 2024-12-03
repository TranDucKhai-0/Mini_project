#ifndef ADMIN_H
#define ADMIN_H

#include <vector>    
#include "Student.h"
#include <iomanip>

using namespace std;

// Lop quan ly sinh vien
class StudentManager {
private:
    vector<Student*> students;  // Danh sach sinh vien
    string adminPassword = "admin123"; // Mat khau cua admin

public:
    bool authenticateAdmin(const string& inputPassword) const;  // Xac thuc admin
    void addStudent(const Student& student);  // Them sinh vien moi
    bool removeStudent(const string& id);
    Student* findStudent(const string& studentId);  // Tim sinh vien theo ma
    void displayAllStudents() const;  // Hien thi danh sach sinh vien
    void displayAllTuitionFees() const; // Tat ca học phi
    void displayAllClassSchedules() const; // All lich hoc
};

#endif
