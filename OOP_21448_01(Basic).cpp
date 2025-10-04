#include <iostream>
using namespace std;

class Complex //* Creation of class Complex.
{
public:
    int real, img;

    Complex() //* Constructor with default real & img values.
    {
        real = 0;
        img = 0;
    }

    void Default() //* prints default complex number.
    {
        cout << "\nDefault complex number is:\n0 + 0i\n\n";
    }
    void assignment() //* assigns real & img values.
    {
        cout << "Enter the real part of complex number: ";
        cin >> real;

        cout << "Enter the imaginary part of complex number: ";
        cin >> img;
    }

    void Print() //* prints complex number.
    {
        cout << real << " + " << img << "i" << endl;
    }

    void Addition(Complex C1, Complex C2) //* adds two complex numbers
    {
        int addR = C1.real + C2.real;
        int addI = C1.img + C2.img;

        cout << "Addition of entered complex numbers is:\n"
             << addR << " + " << addI << "i" << endl;
    }
    Complex operator+(Complex &C2)
    {
        Complex C3;
        C3.real = real + C2.real;
        C3.img = img + C2.img;

        return C3;
    }

    Complex operator-(Complex &C5)
    {
        Complex C6;
        C6.real = real - C5.real;
        C6.img = img - C5.img;

        return C6;
    }

    Complex operator*(Complex &C8)
    {
        Complex C9;
        C9.real = real * C8.real - img * C8.img;
        C9.img = real * C8.img + img * C8.real;
    }
    Complex Subtraction(Complex C3, Complex C4) //* subtracts two complex numbers.
    {
        int SubR = C3.real - C4.real;
        int SubI = C3.img - C4.img;

        Complex Result;
        Result.real = SubR;
        Result.img = SubI;

        return Result;
    }

    void Multiplication(Complex C6)
    {
        int MultiR = real + C6.real;
        int MultiI = img + C6.img;

        cout << "Multiplication of entered numbers is:\n"
             << MultiR << " + " << MultiI << "i" << endl;
    }
    friend ostream &operator<<(ostream &out, Complex &C10)
    {
        if (C10.img < 0)
        {
            out << C10.real << " - " << abs(C10.img) << "i" << endl;
        }

        else
        {
            out << C10.real << " + " << abs(C10.img) << "i" << endl;
        }
    }
};

int main()
{
    int i = 0;
    int ObjNum;
    bool Condt = true;

    Complex Samp; //* object to access & print default complex number.
    Samp.Default();

    cout << "Enter number of complex numbers to store:\n";
    cin >> ObjNum;
    Complex CompAr[ObjNum];

    for (int i = 0; i < ObjNum; i++)
    {
        CompAr[i].assignment();
        cout << "\n";
    }

    cout << "Entered complex numbers:\n";
    for (int i = 0; i < ObjNum; i++)
    {
        cout << "Your " << i << "(st/nd/th) indexed complex number is:";
        CompAr[i].Print();
    }
    while (Condt == true)
    {
        int Opern = 0;
        cout << "Enter \'1\' for complex addition.\nEnter\'2\' for complex subtraction.\nEnter\'3\' for complex multiplication.\nEnter\'4\' to exit operations.";
        cin >> Opern;
        switch (Opern)
        {

        case (1):
        {
            int Temp1, Temp2;
            cout << "Enter the index of 1st complex number to perform addition: ";
            cin >> Temp1;

            cout << "Enter the index of 2nd complex number to perform addition: ";
            cin >> Temp2;

            cout << "\n";
            Complex Comp1 = CompAr[Temp1];
            Complex Comp2 = CompAr[Temp2];

            Comp1.Addition(Comp1, Comp2);
            break;
        }

        case (2):
        {
            int Temp3, Temp4;

            cout << "Enter index of complex number from whom to subtract: ";
            cin >> Temp3;

            cout << "Enter index of complex number which is to be subtracted: ";
            cin >> Temp4;

            Complex Sub1 = CompAr[Temp3];
            Complex Sub2 = CompAr[Temp4];

            Complex Result = Sub1.Subtraction(Sub1, Sub2);

            cout << "Subtraction of entered numbers is\n"
                 << Result.real << " + " << Result.img << "i" << endl;

            break;
        }
        case (3):
        {
            int Temp5, Temp6;

            cout << "Enter index of 1st complex number to be multiplied: ";
            cin >> Temp5;

            cout << "Enter index of 2nd complex number to be multiplied: ";
            cin >> Temp6;

            Complex M1 = CompAr[Temp5];
            Complex M2 = CompAr[Temp6];

            M1.Multiplication(M2);
        }
        case (4):
        {
            Opern = false;
        }
        default:
        {
            cout << "Enter valid input.";
        }
        }
    }
    return 0;
}