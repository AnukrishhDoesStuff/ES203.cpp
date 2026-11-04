#include <iostream>
#include <cstring>
using namespace std;

// ---------------- Base class ----------------
class Media {
protected:
    char title[64];
    char publication[64];

public:
    
    virtual void read() {
        cin.ignore(1000, '\n');
        cout << "Enter title       : ";
        cin.getline(title, 64);
        cout << "Enter publication : ";
        cin.getline(publication, 64);
    }

    virtual void show() {
        cout << "Title       : " << title << "\n";
        cout << "Publication : " << publication << "\n";
    }

    // Virtual destructor: ensures the derived class destructor runs
    // when an object is deleted through a base class pointer.
    virtual ~Media() {}
};

// ---------------- Derived class 1 ----------------
class Book : public Media {
    int pages;

public:
    void read() {                 // overrides Media::read()
        cout << "\n--- Enter Book details ---\n";
        Media::read();            // reuse base class input
        cout << "Enter number of pages : ";
        cin  >> pages;
    }

    void show() {                 // overrides Media::show()
        cout << "\n[BOOK]\n";
        Media::show();
        cout << "Pages       : " << pages << "\n";
    }
};

// ---------------- Derived class 2 ----------------
class Tape : public Media {
    float playTime;               // in minutes

public:
    void read() {                 // overrides Media::read()
        cout << "\n--- Enter Video Tape details ---\n";
        Media::read();
        cout << "Enter playing time (minutes) : ";
        cin  >> playTime;
    }

    void show() {                 // overrides Media::show()
        cout << "\n[VIDEO TAPE]\n";
        Media::show();
        cout << "Play time   : " << playTime << " minutes\n";
    }
};

int main() {
    const int MAX = 10;
    Media *items[MAX];            // array of BASE class pointers
    int count = 0;
    int choice;

    do {
        cout << "\n1. Add Book\n2. Add Video Tape\n3. Display all\n0. Exit\nChoice: ";
        cin  >> choice;

        if (choice == 1 && count < MAX) {
            items[count] = new Book();     // base pointer -> derived object
            items[count]->read();          // calls Book::read() (virtual)
            count++;
        }
        else if (choice == 2 && count < MAX) {
            items[count] = new Tape();     // base pointer -> derived object
            items[count]->read();          // calls Tape::read() (virtual)
            count++;
        }
        else if (choice == 3) {
            cout << "\n========== BOOK SHOP STOCK ==========";
            for (int i = 0; i < count; i++)
                items[i]->show();          // correct show() chosen at run time
            cout << "\n=====================================\n";
        }
        else if ((choice == 1 || choice == 2) && count >= MAX) {
            cout << "Shop is full!\n";
        }
    } while (choice != 0);

    for (int i = 0; i < count; i++)
        delete items[i];                   // virtual destructor -> proper cleanup

    return 0;
}
