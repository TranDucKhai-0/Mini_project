#include "Admin.h"
#include <iostream>  
using namespace std;

bool StudentManager::authenticateAdmin(const string& inputPassword) const {
    return inputPassword == adminPassword;  // Xac thuc mat khau admin
}

void StudentManager::addStudent(const Student& student) {
    students.push_back(new Student(student));  // Them sinh vien vao danh sach
}

bool StudentManager::removeStudent(const string& id_delete) {
    for (auto it = students.begin(); it != students.end(); ++it) {
        if ((*it)->getId() == id_delete) {
            delete *it;               // Xóa bộ nhớ của đối tượng
            students.erase(it);       // Xóa con trỏ khỏi vector
            return true;                    // Thoát khỏi vòng lặp (vì chỉ xóa một phần tử)
        }
    }
    return false; // xóa không thành công
}


Student* StudentManager::findStudent(const string& studentId) {
    for (auto& student : students) {  // Duyet qua danh sach sinh vien
        if (student->getId() == studentId) {  // So sanh ma sinh vien
            return student;  // Tra ve sinh vien tim thay
        }
    }
    return nullptr;  // Neu khong tim thay sinh vien
}

void StudentManager::displayAllStudents() const {
    if (students.empty()) {  // Neu danh sach sinh vien rong
        cout << "\n\n\n\n\n\t\t\t\t\tNo students found!\n";  // Thong bao khong co sinh vien
    } else {
        cout << "\n\n\n\n\n\t\t\t\t\tStudent List:\n\n\n";
        for (const auto& student : students) {  // Duyet qua danh sach sinh vien
            student->displayPersonalInfo();  // Hien thi thong tin ca nhan cua sinh vien
        }
    }
}

void StudentManager::displayAllTuitionFees() const{
    if (students.empty()) {
        cout << "\n\n\n\n\n\t\t\t\t\tNo students found!\n";
    } else {
        cout << "\n\n\n\n\n\t\t\t\t\tTuition Fees of All Students:\n\n";
        for (const auto& student : students) {
            cout << "\n\t\t\t\t\tID: " << student->getId();
            cout << "\n\t\t\t\t\t";
            cout << "Name: " << student->getName();
            cout << "\n\t\t\t\t\t";
            cout << fixed <<"Tuition Fee: " << student->getTuitionFee() << " VND"<< endl;
        }
    }
}

void StudentManager::displayAllClassSchedules() const {
    if (students.empty()) {  // KTDS SV
        cout << "\n\n\n\n\n\t\t\t\t\tNo students found!\n";
    } else {
        cout << "\n\n";
        for (const auto& student : students) {  // Kiem tung SV
            cout << "\n\t\t\t\t\tClass Schedule for Student ID: " << student->getId() << endl; 
            cout << "Name: " << student->getName() << ":\n";
            student->displayClassSchedule();  // Lich hoc
        }
    }
}
