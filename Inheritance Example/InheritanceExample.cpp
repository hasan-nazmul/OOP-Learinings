#include <bits/stdc++.h>

using namespace std;

class rectangle
{
    int length;
    int width;

    public:

    rectangle(int length = 10, int width = 10)
    {
        setLength(length);
        setWidth(width);
    }

    rectangle(rectangle& r)
    {
        setLength(r.getLength());
        setWidth(r.getWidth());
    }

    void setLength(int length)
    {
        if(length < 0)  length = 10;
        this->length = length;
    }

    void setWidth(int width)
    {
        if(width < 0)  width = 10;
        this->width = width;
    }

    int getLength()
    {
        return length;
    }

    int getWidth()
    {
        return width;
    }

    int area()
    {
        return length * width;
    }

    int perimeter()
    {
        return 2 * (length + width);
    }

    bool isSquare()
    {
        return length == width;
    }
};

class cuboid: public rectangle
{
    int height;

    public:

    cuboid(int length = 10, int width = 10, int height = 10): rectangle(length, width)
    {
        setHeight(height);
    }

    cuboid(rectangle& r, int height = 10): rectangle(r)
    {
        setHeight(height);
    }

    cuboid(cuboid& c): rectangle(c.getLength(), c.getWidth())
    {
        setHeight(c.getHeight());
    }

    void setHeight(int height)
    {
        if(height < 0)  height = 10;
        this->height = height;
    }

    int getHeight()
    {
        return height;
    }

    int volume()
    {
        return area() * height;
    }

    bool isCube()
    {
        return getLength() == getWidth() and getWidth() == height;
    }
};

int main()
{
    cout << "---Rectangle---" << endl;

    rectangle r(10, 15);

    cout << "   Length : " << r.getLength() << endl;
    cout << "    Width : " << r.getWidth() << endl;
    cout << "     Area : " << r.area() << endl;
    cout << "Perimeter : " << r.perimeter() << endl;
    cout << "   Square ? " << r.isSquare() << endl;

    cout << endl;

    cout << "---Cuboid---" << endl;

    cuboid c(r, 12);

    cout << "   Length : " << c.getLength() << endl;
    cout << "    Width : " << c.getWidth() << endl;
    cout << "   Height : " << c.getHeight() << endl;
    cout << "   Volume : " << c.volume() << endl;
    cout << "     Area : " << c.area() << endl;
    cout << "Perimeter : " << c.perimeter() << endl;
    cout << "     Cube ? " << c.isCube() << endl;
}