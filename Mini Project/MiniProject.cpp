#include <bits/stdc++.h>

using namespace std;

class student
{
    int roll;
    string name;
    int mathMarks;
    int physicsMarks;
    int biologyMarks;

    public:

    // Parameterized Constructor
    student(int roll = 0, string name = "John Doe", int mathMarks = 0, int physicsMarks = 0, int biologyMarks = 0)
    {
        if(roll <= 0)   // sets roll to zero if true
        {
            cerr << "ValueError: Roll number has to be a positive integer." << endl;
            roll = 0;
        }
        if(mathMarks < 0 or mathMarks > 100)    // sets marks to zero if true
        {
            cerr << "ValueError: Marks has to be in between [0, 100]." << endl;
            mathMarks = 0;
        }
        if(physicsMarks < 0 or physicsMarks > 100)  // sets marks to zero if true
        {
            cerr << "ValueError: Marks has to be in between [0, 100]." << endl;
            physicsMarks = 0;
        }
        if(biologyMarks < 0 or biologyMarks > 100)  // sets marks to zero if true
        {
            cerr << "ValueError: Marks has to be in between [0, 100]." << endl;
            biologyMarks = 0;
        }
        if(validateName(name))  // sets name to "John Doe" if true
        {
            cerr << "ValueError: Name cannot be an empty string or contain any digits or special characters." << endl;
            name = "John Doe";
        }

        // assigning values to the attributes
        this->roll = roll;
        this->name = name;
        this->mathMarks = mathMarks;
        this->physicsMarks = physicsMarks;
        this->biologyMarks = biologyMarks;
    }

    // Accessors
    void info()
    {
        cout << "Name: " << name << "." << endl;
        cout << "Roll: " << roll << "." << endl;
        cout << endl;
        cout << "Result:" << endl;
        cout << endl;
        cout << "\t|---------------------------------|" << endl;
        cout << "\t|    Mathematics: " << mathMarks    << "%             |" << endl;
        cout << "\t|        Physics: " << physicsMarks << "%             |" << endl;
        cout << "\t|        Biology: " << biologyMarks << "%             |" << endl;
        cout << "\t|---------------------------------|" << endl;
        cout << "\t|    Total marks: " << totalMarks()  << " out of 300. |" << endl;
        cout << "\t|  Average marks: " << average()       << "%          |" << endl;
        cout << "\t| Achieved Grade: " << grade()      << "              |" << endl;
        cout << "\t|---------------------------------|" << endl;
    }

    // Fascilitators
    int totalMarks()
    {
        return mathMarks + physicsMarks + biologyMarks;
    }

    // Fascilitators
    double average()
    {
        double totalMarks = mathMarks + physicsMarks + biologyMarks;
        double averageMarks = totalMarks / 3.0;
        return averageMarks;
    }

    // Fascilitators
    string grade()
    {
        double averageMarks = average();
        string grade = "";

        if(averageMarks >= 80.00)
            grade = "A+";
        else if(averageMarks >= 70.00)
            grade = "A";
        else if(averageMarks >= 60.00)
            grade = "A-";
        else if(averageMarks >= 50.00)
            grade = "B+";
        else if(averageMarks >= 40.00)
            grade = "B";
        else if(averageMarks >= 33.00)
            grade = "C";
        else    grade = "F";

        return grade;
    }

    // Querry
    bool validateName(string name)
    {
        if(name.empty())    return 1;

        int count = 0;

        for(auto i : name)
        {
            if(i >= 'A' and i <= 'Z')   count++;
            else if(i >= 'a' and i <= 'z')   count++;
            else if(i == ' ') continue;
            else    return 1;
        }

        return !count;
    }
};

int main()
{
    cout << setprecision(2) << fixed;

    student s(13, "Mostafa Jobbar", 80, 70, 50);

    s.info();
}