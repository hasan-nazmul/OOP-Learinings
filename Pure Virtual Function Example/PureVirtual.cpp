/// Bismillahir Rahmanir Rahim

#include <bits/stdc++.h>
using namespace std;

class car
{
    public:

    /*
        Pure Virtual Functions: 
        Derived classes must define
        these functions.
    */

    virtual void start() = 0;

    virtual void stop() = 0;
};

class inova: public car
{
    public:

    void start()
    {
        cout << "Inova Started!!!" << endl;
    }

    void stop()
    {
        cout << "Inova Stopped!!!" << endl;
    }
};

class swift: public car
{
    public:

    void start()
    {
        cout << "Swift Started!!!" << endl;
    }

    void stop()
    {
        cout << "Swift Stopped!!!" << endl;
    }
};

int main()
{
    car *c = new inova;

    c->start();

    return 0;
}