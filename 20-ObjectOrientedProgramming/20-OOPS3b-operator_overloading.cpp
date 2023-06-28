/*
    b) operator overloading : if a single operator is used to perform more than one operation. like + is used for int addtion and float addition and complex no. addition ( we have to make our own function for that)

 */
#include <iostream>
using namespace std;

class Complex
{
    int real, img;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        img = i;
    }
    Complex operator+(Complex &obj)
    {
        Complex result;
        result.img = img + obj.img;
        result.real = real + obj.real;
        return result;
    }

    void display()
    {
        cout << real << " + " << img << "i" << endl;
    }
};
int main()
{
    Complex c1(12, 7);
    Complex c2(5, 4);
    Complex c3 = c1 + c2;
    c3.display();

    return 0;
}