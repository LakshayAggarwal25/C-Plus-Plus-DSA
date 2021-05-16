#include <iostream>
using namespace std;

class Complex
{
    int real;
    int img;

public:
    Complex()
    {
        real = 0;
        img = 0;
    }
    Complex(int r, int i)
    {
        real = r;
        img = i;
    }

    void setReal(const int r)
    {
        real = r;
    }
    void setImg(const int i)
    {
        img = i;
    }
    int getReal() const
    {
        return real;
    }
    int getImg() const
    {
        return img;
    }

    void print() const
    {
        if (img > 0)
        {
            cout << real << " + " << img << "i" << endl;
        }
        else
        {
            cout << real << " - " << -img << "i" << endl;
        }
    }

    void add(const Complex &x)
    {
        real += x.real;
        img += x.img;
    }

    // operator overloading
    void operator+(const Complex &x)  //=> now if we do c1 + c2 it would mean c1.+(c2)
    {
        real += x.real;
        img += x.img;
    }
};

istream& operator>>(istream& is, Complex &c){ // Overloading cin for complex class
    int r,i;
    is>>r>>i;
    c.setReal(r);
    c.setImg(i);
    return is;
}

ostream& operator<<(ostream& os, Complex &c){
    c.print();
    return os;
}

int main()
{
    Complex c1(2, 3);
    Complex c2;
    c2.setReal(10);
    c2.setImg(-2);
    c1.print();
    c2.print();

    c1.add(c2);
    c1.print();

    c2 + c1;
    c2.print();

    Complex c3,c4;
    cin>>c3>>c4;
    cout<<c3<<c4;
    return 0;
}