
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdexcept>
using namespace std;

// Abstract class
class Advisory
{
public:
    virtual void giveAdvice() = 0;
    virtual ~Advisory() {}
};

// Base class
class Crop
{
protected:
    string name, season;
    double area, yieldPerAcre;

public:
    static int cropCount;

    // Default constructor
    Crop()
    {
        name = "Unknown";
        season = "Unknown";
        area = 0;
        yieldPerAcre = 0;
        cropCount++;
    }

    // Parameterized constructor
    Crop(string n, double a, string s, double y)
    {
        if (a <= 0 || y < 0)
            throw invalid_argument("Invalid area or yield!");

        name = n;
        area = a;
        season = s;
        yieldPerAcre = y;
        cropCount++;
    }

    virtual double calculateYield() const
    {
        return area * yieldPerAcre;
    }

    virtual void display() const
    {
        cout << "\nCrop Name       : " << name;
        cout << "\nArea (acres)    : " << area;
        cout << "\nSeason          : " << season;
        cout << "\nYield per Acre  : " << yieldPerAcre;
        cout << "\nTotal Yield     : " << calculateYield() << endl;
    }

    // Operator overloading
    bool operator>(const Crop &c) const
    {
        return calculateYield() > c.calculateYield();
    }

    // Virtual destructor
    virtual ~Crop() {}

    static void showCount()
    {
        cout << "\nTotal Crops Registered: " << cropCount << endl;
    }
};

int Crop::cropCount = 0;

// Derived class: CerealCrop
class CerealCrop : public Crop, public Advisory
{
    string fertilizerType;

public:
    // Default constructor
    CerealCrop() : Crop()
    {
        fertilizerType = "Not Specified";
    }

    // Parameterized constructor
    CerealCrop(string n, double a, string s,
               double y, string f)
        : Crop(n, a, s, y)
    {
        fertilizerType = f;
    }

    double calculateYield() const override
    {
        return area * yieldPerAcre;
    }

    void giveAdvice() override
    {
        cout << "Advice: Use balanced fertilizers and "
             << "maintain proper irrigation for cereals.\n";
    }

    void display() const override
    {
        cout << "\n--- Cereal Crop Details ---";
        Crop::display();
        cout << "Fertilizer Type  : " << fertilizerType << endl;
    }

    ~CerealCrop() {}
};

// Derived class: VegetableCrop
class VegetableCrop : public Crop, public Advisory
{
    int irrigationFrequency;

public:
    // Default constructor
    VegetableCrop() : Crop()
    {
        irrigationFrequency = 0;
    }

    // Parameterized constructor
    VegetableCrop(string n, double a, string s,
                  double y, int i)
        : Crop(n, a, s, y)
    {
        if (i < 0)
            throw invalid_argument("Invalid irrigation frequency!");

        irrigationFrequency = i;
    }

    double calculateYield() const override
    {
        return area * yieldPerAcre;
    }

    void giveAdvice() override
    {
        cout << "Advice: Maintain regular irrigation "
             << "and monitor vegetables for pests.\n";
    }

    void display() const override
    {
        cout << "\n--- Vegetable Crop Details ---";
        Crop::display();
        cout << "Irrigation Frequency (per week): "
             << irrigationFrequency << endl;
    }

    ~VegetableCrop() {}
};

// Main function
int main()
{
    try
    {
        CerealCrop c1("Wheat", 5, "Rabi", 20, "Urea");
        VegetableCrop v1("Tomato", 3, "Kharif", 15, 4);

        // Runtime polymorphism
        Crop *ptr;

        cout << fixed << setprecision(2);

        cout << "\n===== SMART FARM MANAGEMENT SYSTEM =====\n";

        ptr = &c1;
        ptr->display();

        ptr = &v1;
        ptr->display();

        // Farming advice
        cout << "\n===== FARMING ADVISORY =====\n";
        c1.giveAdvice();
        v1.giveAdvice();

        // Operator overloading
        cout << "\n===== YIELD COMPARISON =====\n";

        if (c1 > v1)
            cout << "Wheat produces more total yield.\n";
        else if (v1 > c1)
            cout << "Tomato produces more total yield.\n";
        else
            cout << "Both crops produce equal yield.\n";

        // Static member
        Crop::showCount();

        // File handling: Writing data
        ofstream fout("FarmData.txt");

        if (!fout)
            throw runtime_error("Unable to open file for writing!");

        fout << "SMART FARM MANAGEMENT SYSTEM\n";
        fout << "Crop Name: Wheat, Area: 5 acres, "
             << "Season: Rabi, Total Yield: "
             << c1.calculateYield() << endl;

        fout << "Crop Name: Tomato, Area: 3 acres, "
             << "Season: Kharif, Total Yield: "
             << v1.calculateYield() << endl;

        fout.close();

        cout << "\nCrop data saved successfully!\n";

        // File handling: Reading data
        ifstream fin("FarmData.txt");

        if (!fin)
            throw runtime_error("Unable to open file for reading!");

        cout << "\n===== SAVED FARM DATA =====\n";

        string line;

        while (getline(fin, line))
        {
            cout << line << endl;
        }

        fin.close();
    }
    catch (const exception &e)
    {
        cout << "\nError: " << e.what() << endl;
    }

    return 0;
}
