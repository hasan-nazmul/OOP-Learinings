#include <bits/stdc++.h>

using namespace std;

class rectangle
{
    int length;
    int width;

    public:

    // Constructors
    inline rectangle(int length = 10, int width = 10);
    inline rectangle(rectangle &r);

    // Accessors
    int getLength() {return length;}
    int getWidth()  {return width;}

    // Mutators
    inline void setLength(int l);
    inline void setWidth(int w);

    // Fascilitators
    int area()  {return length * width;}
    int perimeter() {return 2 * (length + width);}

    // Querry
    bool isSquare() {return length == width;}

    // Destructor
    inline ~rectangle();
};

int main()
{
    rectangle r(5, 10);

    cout << "Length: " << r.getLength() << endl;
    cout << "Width: " << r.getWidth() << endl;
    cout << "Area: " << r.area() << endl;
    cout << "Perimeter: " << r.perimeter() << endl;
    cout << "Square? " << r.isSquare() << endl;
}

rectangle::rectangle(int length, int width)
{
    setLength(length);
    setWidth(width);
}

rectangle::rectangle(rectangle &r)
{
    length = r.length;
    width = r.width;
}

void rectangle::setLength(int length)
{
    if(length < 0)
    {
        cerr << "Invalid Length" << endl;
        length = 10;
    }
    this->length = length;
}

void rectangle::setWidth(int width)
{
    if(width < 0)
    {
        cerr << "Invalid Width" << endl;
        width = 10;
    }
    this->width = width;
}

rectangle::~rectangle()
{
    cout << "Rectangle object destroyed" << endl;
}
