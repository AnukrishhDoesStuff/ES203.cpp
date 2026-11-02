#include <iostream>
using namespace std;

class Complex {
    float real;
    float imag;

public:
    // Constructors
    Complex() : real(0), imag(0) {}
    Complex(float r, float i) : real(r), imag(i) {}

    // ---------- (a) Unary operator overloading ----------

    // Pre-increment (++c): increases both real and imag by 1
    Complex operator ++ () {
        real = real + 1;
        imag = imag + 1;
        return Complex(real, imag);
    }

    // Post-increment (c++): note the dummy int parameter
    Complex operator ++ (int) {
        Complex temp(real, imag);   // save old value
        real = real + 1;
        imag = imag + 1;
        return temp;                // return value before increment
    }

    // Pre-decrement (--c)
    Complex operator -- () {
        real = real - 1;
        imag = imag - 1;
        return Complex(real, imag);
    }

    // Post-decrement (c--)
    Complex operator -- (int) {
        Complex temp(real, imag);
        real = real - 1;
        imag = imag - 1;
        return temp;
    }

    // ---------- (b) Binary operator overloading ----------

    Complex operator + (const Complex &c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator - (const Complex &c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    void display() const {
        cout << real;
        if (imag >= 0)
            cout << " + " << imag << "i" << endl;
        else
            cout << " - " << -imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);

    cout << "c1 = "; c1.display();
    cout << "c2 = "; c2.display();

    // (a) Unary operators
    cout << "\n--- Unary operator tests ---\n";
    Complex c3 = ++c1;             // pre-increment
    cout << "After ++c1, c1 = "; c1.display();
    cout << "Returned value  = "; c3.display();

    Complex c4 = c2++;             // post-increment
    cout << "\nAfter c2++, c2 = "; c2.display();
    cout << "Returned value (old c2) = "; c4.display();

    Complex c5 = --c1;             // pre-decrement
    cout << "\nAfter --c1, c1 = "; c1.display();
    cout << "Returned value  = "; c5.display();

    Complex c6 = c2--;             // post-decrement
    cout << "\nAfter c2--, c2 = "; c2.display();
    cout << "Returned value (old c2) = "; c6.display();

    // (b) Binary operators
    cout << "\n--- Binary operator tests ---\n";
    Complex sum = c1 + c2;
    cout << "c1 + c2 = "; sum.display();

    Complex diff = c1 - c2;
    cout << "c1 - c2 = "; diff.display();

    return 0;
}
