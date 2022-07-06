#include <iostream> 
#include<algorithm> 
#include"Fraction.h" 
#include"Fraction.cpp" 
using namespace std;

class FractionCalculator
{
public:
    void start(Fraction& f1)
    {
        while (true) {
            cout << "your main fraction is now equal to: "; cout << f1 << endl;
            cout << "options:\n1- adding another fraction to the main fraction\n2- subtract new fraction from the main fraction\n3- multiply by new fraction\n4- divide by new fraction\n5- reduce your main fraction\n6- exit" << endl;
            int option;
            cout << "choose an option:"; cin >> option;
            Fraction f2;
            if (option == 1)
            {
                cout << "enter the new fraction like(x/y): "; cin >> f2;
                f1 += f2;
                cout << "the result(main fraction after the operation) = f1+f2=" << f1;
            }
            else if (option == 2)
            {
                cout << "enter the new fraction like(x/y): "; cin >> f2;
                f1 -= f2;
                cout << "the result(main fraction after the operation) = f1-f2=" << f1;
            }
            else if (option == 3)
            {
                cout << "enter the new fraction like(x/y): "; cin >> f2;
                f1 *= f2;
                cout << "the result(main fraction after the operation) = f1*f2= " << f1;
            }
            else if (option == 4)
            {
                cout << "enter the new fraction like(x/y):"; cin >> f2;
                f1 /= f2;
                cout << "the result(main fraction after the operation) = f1/f2=" << f1;
            }
            else if (option == 5)
            {
                f1.ReduceFraction();
                cout << "your main fraction after reduction: " << f1;
            }
            else if (option == 6)break;
            else cout << "Invalid option!" << endl;
            cout << endl << endl;
        }

    }
};
int main()
{
    cout << "Welcome to your fraction calculator :)" << endl;
    Fraction f1;
    cout << "Enter your main fraction like that(x/y):"; cin >> f1;
    FractionCalculator obj;
    obj.start(f1);
}