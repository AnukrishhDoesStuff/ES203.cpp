#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;


class Student {
protected:
    int rollNo;
    char name[64];
    int age;
    char gender[10];
    char course[50];

public:

    void getStudentData() {
        cout << "Enter Roll No : ";
        cin >> rollNo;

        cout << "Enter Name     : ";
        cin.ignore();
        cin.getline(name, 64);

        cout << "Enter Age      : ";
        cin >> age;

        cout << "Enter Gender   : ";
        cin >> gender;

        cout << "Enter Course   : ";
        cin >> course;
    }

    void showStudentData() {
        cout << "Roll No  : " << rollNo << "\n";
        cout << "Name     : " << name << "\n";
        cout << "Age      : " << age << "\n";
        cout << "Gender   : " << gender << "\n";
        cout << "Course   : " << course << "\n";
    }
};



class Exam : public Student {
protected:
    float marks[6];

public:

    void getExamData() {
        cout << "\nEnter marks in 6 subjects (out of 100 each):\n";

        for (int i = 0; i < 6; i++) {
            cout << "Subject " << (i + 1) << " : ";
            cin >> marks[i];
        }
    }

    void showExamData() {
        cout << "\nMarks Obtained:\n";

        for (int i = 0; i < 6; i++) {
            cout << "Subject " << (i + 1)
                 << " : " << marks[i] << "\n";
        }
    }
};




class Result : public Exam {
private:
    float totalMarks;
    float percentage;
    char grade;

    void calculateResult() {
        totalMarks = 0;

        for (int i = 0; i < 6; i++) {
            totalMarks += marks[i];
        }

        percentage = totalMarks / 6.0f;

        if (percentage >= 90)
            grade = 'A';
        else if (percentage >= 75)
            grade = 'B';
        else if (percentage >= 60)
            grade = 'C';
        else if (percentage >= 40)
            grade = 'D';
        else
            grade = 'F';
    }

public:

    void processResult() {
        getStudentData();     
        getExamData();        
        calculateResult();    
    }

    void displayResult() {

        cout << "\n========================================\n";
        cout << "              RESULT SHEET              \n";
        cout << "========================================\n";

        showStudentData();    
        showExamData();      

        cout << fixed << setprecision(2);

        cout << "\nTotal Marks : " << totalMarks
             << " / 600\n";

        cout << "Percentage  : " << percentage
             << "%\n";

        cout << "Grade       : " << grade << "\n";

        cout << "========================================\n";
    }
};




int main() {

    int n;

    cout << "Enter number of students: ";
    cin >> n;

    Result *res = new Result[n];

    
    for (int i = 0; i < n; i++) {

        cout << "\n----------- Student " << (i + 1)
             << " -----------\n";

        res[i].processResult();
    }

   
    cout << "\n\n############ FINAL RESULTS ############\n";

    for (int i = 0; i < n; i++) {

        cout << "\n----------- Student " << (i + 1)
             << " -----------\n";

        res[i].displayResult();
    }

    
    delete[] res;

    return 0;
}