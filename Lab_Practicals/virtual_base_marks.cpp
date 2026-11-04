
#include <iostream>
#include <cstring>
using namespace std;

// ---------------- Base class ----------------
class Student {
protected:
    int  rollNo;
    char name[64];

public:
    void getStudent() {
        cout << "Enter Roll No : ";
        cin  >> rollNo;
        cout << "Enter Name    : ";
        cin.ignore(1000, '\n');
        cin.getline(name, 64);
    }

    void showStudent() {
        cout << "Roll No : " << rollNo << "\n";
        cout << "Name    : " << name   << "\n";
    }
};

// ---------------- Intermediate class 1 ----------------
// "virtual" here makes Test share ONE copy of Student with other classes
class Test : virtual public Student {
protected:
    float theory[3];          // marks in 3 theory subjects

public:
    void getTestMarks() {
        cout << "Enter marks in 3 theory subjects (out of 100):\n";
        for (int i = 0; i < 3; i++) {
            cout << "  Subject " << (i + 1) << " : ";
            cin  >> theory[i];
        }
    }
};

// ---------------- Intermediate class 2 ----------------
class Sports : virtual public Student {
protected:
    float sportsMarks;        // marks in sports (out of 100)

public:
    void getSportsMarks() {
        cout << "Enter sports marks (out of 100) : ";
        cin  >> sportsMarks;
    }
};

// ---------------- Final derived class ----------------
// Inherits from BOTH Test and Sports (diamond shape).
// Without "virtual" above, Result would contain two copies of Student
// and rollNo/name would be ambiguous.
class Result : public Test, public Sports {
    float total;

public:
    void calculate() {
        total = theory[0] + theory[1] + theory[2] + sportsMarks;
    }

    void display() {
        showStudent();        // unambiguous: only one Student sub-object exists
        cout << "Theory Marks : " << theory[0] << ", "
             << theory[1] << ", " << theory[2] << "\n";
        cout << "Sports Marks : " << sportsMarks << "\n";
        cout << "TOTAL MARKS  : " << total << " / 400\n";
    }
};

int main() {
    Result r;

    r.getStudent();       // from the single shared Student
    r.getTestMarks();     // from Test
    r.getSportsMarks();   // from Sports
    r.calculate();

    cout << "\n=========== RESULT ===========\n";
    r.display();
    cout << "==============================\n";

    return 0;
}
