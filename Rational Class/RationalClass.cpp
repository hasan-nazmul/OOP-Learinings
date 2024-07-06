#include <bits/stdc++.h>

using namespace std;

class rational
{
    int p;
    int q;

    public:

    rational(int p = 1, int q = 1)
    {
        if(!q)
        {
            cerr << "ValueError: denominator can not be zero." << endl;
            q = 1;
        }
        this->p = p;
        this->q = q;
    }

    int get_p()
    {
        return p;
    }

    int get_q()
    {
        return q;
    }

    rational operator+ (rational r)
    {
        rational t;

        t.q = (q * r.get_q()) / __gcd(q, r.get_q());
        t.p = p * (t.q / q) + r.get_p() * (t.q / r.get_q());

        int g = __gcd(abs(t.p), abs(t.q));

        t.p /= g;
        t.q /= g;

        return t;
    }

    rational operator- (rational r)
    {
        rational t;

        t.q = (q * r.get_q()) / __gcd(q, r.get_q());
        t.p = p * (t.q / q) - r.get_p() * (t.q / r.get_q());

        int g = __gcd(abs(t.p), abs(t.q));

        t.p /= g;
        t.q /= g;

        return t;
    }

    rational operator* (rational r)
    {
        rational t;

        t.p = p * r.get_p();
        t.q = q * r.get_q();

        int g = __gcd(abs(t.p), abs(t.q));

        t.p /= g;
        t.q /= g;

        return t;
    }

    rational operator/ (rational r)
    {
        rational t;

        t.p = p * r.get_q();
        t.q = q * r.get_p();

        int g = __gcd(abs(t.p), abs(t.q));

        t.p /= g;
        t.q /= g;

        return t;
    }

    friend ostream& operator<< (ostream& o, rational r);
};

ostream& operator<< (ostream& o, rational r)
{
    o << r.p << "/" << r.q;
    return o;
}

int main()
{
    rational a(3, 4), b(2, 5);

    cout << "            a = " << a << endl;
    cout << "            b = " << b << endl;
    cout << "     Summation: " << a+b << endl;
    cout << "   Subtraction: " << a-b << endl;
    cout << "Multiplication: " << a*b << endl;
    cout << "      Divition: " << a/b << endl;
}