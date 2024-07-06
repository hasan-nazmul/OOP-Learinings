/// Bismillahir Rahmanir Rahim

#include <bits/stdc++.h>
using namespace std;

class base
{
    public:

    /*
        If we want to execute derived class display function,
        when we take a derived class object in base class pointer,
        virtual need to be written in front of function declaration.
        Otherwise base class display function will be executed by default.
    */ 

    virtual void display()
    {
        cout << "Display of base class." << endl;
    }
};

class derived: public base
{
    public:

    void display()
    {
        cout << "Display of derived class" << endl;
    }
};

int main()
{
    derived d;
    
    d.display();

    d.base::display();

    base* b = new derived;

    b->display();
}
