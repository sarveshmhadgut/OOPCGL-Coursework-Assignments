#include<iostream>
using namespace std;

class Complex
{
private:
    float real;
    float img;

public:

    Complex()
    {
        this->real = 0;
        this->img = 0;
    }

    Complex(float real, float img)
    {
        this->real = real;
        this->img = img;
    }

    Complex operator+(const Complex &C2)
    {
        Complex res;
        res.real = this->real + C2.real;
        res.img = this->img + C2.img;

        return res;
    }

    Complex operator*(const Complex &C2)
    {
        Complex res;
        res.real = this->real * C2.real - (this->img * C2.img);
        res.img = this->real * C2.img + this->img * C2.real;

        return res;
    }

    friend ostream &operator<<(ostream&, const Complex&);
    friend istream &operator>>(istream &, Complex &);
};

ostream &operator<<(ostream &out,const Complex &C2)
{
    if (C2.img < 0)
    {
        out << C2.real << " - " << C2.img << "i" << endl;
        return out;
    }

    out << C2.real << " + " << C2.img << "i" << endl;
        return out;
}

istream &operator>>(istream &in , Complex &C2)
{
    cout << "Enter the real part: ";
    in >> C2.real;

    cout << "Enter the imaginary part: ";
    in >> C2.img;

    return in;
}

int main() {

    Complex a, b;
    cin >> a;
    cin >> b;
    cout << "Complex no: " << a << " , " << b << endl;
    cout << "Add: " << a + b << endl;
    cout << "Multiply: " << a * b << endl;
    return 0;
}