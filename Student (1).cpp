#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

struct Student {
    int id;
    string name;
    int age;
    string subject;
    float midtermScore;
    float finalScore;
};

void addStudent(vector<Student>& students) {
    Student newStudent;
    bool isDuplicateID = false;
    
    do {
        cout << "ID: ";
        cin >> newStudent.id;
        
        isDuplicateID = false;
        for (size_t i = 0; i < students.size(); ++i) {
            if (students[i].id == newStudent.id) {
                isDuplicateID = true;
                cout << "ID bi trung. Hay nhap ID khac." << endl;
                break;
            }
        }
    } while (isDuplicateID);
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    
    cout << "Ten sinh vien: ";
    getline(cin, newStudent.name);
    
    cout << "Tuoi: ";
    cin >> newStudent.age;
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << "Mon hoc: ";
    getline(cin, newStudent.subject);
    
    cout << "Diem giua ky: ";
    cin >> newStudent.midtermScore;
    
    cout << "Diem cuoi ky: ";
    cin >> newStudent.finalScore;
    
    students.push_back(newStudent);
}

string getGrade(float averageScore) {
    if (averageScore >= 8.5) {
        return "A";
    }else if (averageScore >= 7.0) {
        return "B";
    }else if (averageScore >= 5.5) {
        return "C";
    }else if (averageScore >= 4.0) {
        return "D";
    }else {
        return "F";
    }
}

void printStudents(const vector<Student>& students) {
    cout << "ID\tName\tAge\tSubject\tMidterm\tFinal\tTotal\tAverage\tGrade" << endl;
    for (vector<Student>::const_iterator it = students.begin(); it != students.end(); ++it) {
        const Student& student = *it;
        float totalScore = student.midtermScore + student.finalScore;
        float averageScore = totalScore / 2.0;
        string grade = getGrade(averageScore);
        
        cout << student.id << "\t"
            << student.name << "\t"
            << student.age << "\t"
            << student.subject << "\t"
            << student.midtermScore << "\t"
            << student.finalScore << "\t"
            << totalScore << "\t"
            << averageScore << "\t"
            << grade << endl;
    }
}



void calculateGrade(const vector<Student>& students) {
    cout << "Nhap ID sv can tim: ";
    int id;
    cin >> id;
    
    bool found = false;
    for (vector<Student>::const_iterator it = students.begin(); it != students.end(); ++it) {
        const Student& student = *it;
        if (student.id == id) {
            found = true;
            float totalScore = student.midtermScore + student.finalScore;
            float averageScore = totalScore / 2.0;
            
            cout << "Student Name: " << student.name << endl;
            cout << "Subject: " << student.subject << endl;
            cout << "Total Score: " << fixed << setprecision(2) << totalScore << endl;
            cout << "Average Score: " << fixed << setprecision(2) << averageScore << endl;
            
            break;
        }
    }
    
    if (!found) {
        std::cout << "Sinh vien voi id la " << id << " khong tim thay." << std::endl;
    }
}


void findStudentByID(const vector<Student>& students) {
    cout << "Nhap ID sv can tim: ";
    int id;
    cin >> id;
    
    bool found = false;
    for (vector<Student>::const_iterator it = students.begin(); it != students.end(); ++it) {
        const Student& student = *it;
        if (student.id == id) {
            found = true;
            cout << "ID: " << student.id << endl;
            cout << "Name: " << student.name << endl;
            cout << "Age: " << student.age << endl;
            cout << "Subject: " << student.subject << endl;
            cout << "Midterm Score: " << student.midtermScore << endl;
            cout << "Final Score: " << student.finalScore << endl;
            break;
        }
    }
    
    if (!found) {
        cout << "Sinh vien voi id la " << id << " khong tim thay." << endl;
    }
}





int main() {
    vector<Student> students;
    char choice;
    
    do {
        cout << "1. Them sinh vien" << endl;
        cout << "2. Xem danh sach sinh vien" << endl;
        cout << "3. Tinh diem mon hoc" << endl;
        cout << "4. Tim ID sinh vien" << endl;
        cout << "5. Thoat" << endl;
        cout << "Lua chon cac hinh thuc tren: ";
        cin >> choice;
        
        switch (choice) {
            case '1':
                addStudent(students);
                break;
            case '2':
                printStudents(students);
                break;
            case '3':
                calculateGrade(students);
                break;
            case '4':
                findStudentByID(students);
                break;
            case '5':
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                cout << "Khong co trong su lua chon. Vui l�ng chon lai (1,2,3,4,5)." << endl;
                break;
        }
        
        cout << endl;
    } while (choice != '5');
    
    return 0;
}

