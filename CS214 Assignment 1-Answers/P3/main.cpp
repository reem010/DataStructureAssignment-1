#include<iostream>
#include "matrix.h"
using namespace std;

class MatrixCalculator
{
public:

    void printMatrixCalculator()
    {cout << "Welcome to your Matrix Calculator" << endl;
        cout << "----------------------------------------" << endl;
        int num,r,c;
        while(true){
            cout << "1- Perform Matrix Addition\n"
                    "2- Perform Matrix Subtraction\n"
                    "3- Perform Matrix Multiplication\n"
                    "4- Matrix Transpose\n"
                    "5- Exit" << endl;
            cin>>num;
            if (num == 1)
            {
                cout << "enter the rows size and the colum size of the first matrix:"; cin >> r >> c;
                matrix<int>m1(r, c);
                cout << "enter the first matrix:" << endl;
                cin >> m1;
                cout << "enter the rows size and the colum size of the second matrix:"; cin >> r >> c;
                matrix<int>m2(r, c);
                cout << "enter the second matrix:" << endl;
                cin >> m2;
                cout << "the answer:" << endl << m1 + m2 << endl;
            }
            else  if (num == 2)
            {
                cout << "enter the rows size and the colum size of the first matrix:"; cin >> r >> c;
                matrix<int>m1(r, c);
                cout << "enter the first matrix:" << endl;
                cin >> m1;
                cout << "enter the rows size and the colum size of the second matrix:"; cin >> r >> c;
                matrix<int>m2(r, c);
                cout << "enter the second matrix:" << endl;
                cin >> m2;
                cout << "the answer:" << endl << m1 - m2 << endl;
            }
            else if (num == 3)
            {
                cout << "enter the rows size and the colum size of the first matrix:"; cin >> r >> c;
                matrix<int>m1(r, c);
                cout << "enter the first matrix:" << endl;
                cin >> m1;

                int r2, c2;
                cout << "enter the rows size and the colum size of the second matrix:"; cin >> r2 >> c2;
                if (c != r2) {
                    cout << "we cant preform this operation :(" << endl; continue;
                }
                matrix<int>m2(r2, c2);
                cout << "enter the second matrix:" << endl;
                cin >> m2;
                cout << "the answer:" << endl << m1 * m2 << endl;
            }
            else if (num == 4)
            {
                cout << "enter the rows size and the colum size of the matrix:"; cin >> r >> c;
                matrix<int>m1(r, c);
                cout << "enter the matrix:" << endl;
                cin >> m1;
                m1.transpose();
                cout << "the answer:" << endl;
                cout << m1 << endl;
            }
            else if (num == 5)
            {
                cout << "Thank you." << endl;
                break;
            }
            else
                cout << "Invalid!" << endl;
        }

    }
};

int main()
{
    MatrixCalculator obj;
    obj.printMatrixCalculator();
}

