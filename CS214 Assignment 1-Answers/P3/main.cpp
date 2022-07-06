#include<iostream>
#include"Matrix.h"
class Matrixcalculator
{
public:
    void start()
    {
        cout << "Welcome to your matrix calculator :)" << endl;
        int num, r, c;
        //printing the menu
        while (true)
        {
            cout << "options:-" << endl;
            cout << "1- Perform Matrix Addition.\n2- Perform Matrix Subtraction.\n3- Perform Matrix Multiplication.\n4- Matrix Transpose.\n5- Exit." << endl;
            cout << "choose a number:"; cin >> num;
            if (num == 1)
            {
                cout << "enter the rows size and the colume size of the first matrix:"; cin >> r >> c;
                Matrix<int>m1(r, c);
                cout << "enter the first matrix:" << endl;
                cin >> m1;
                cout << "enter the rows size and the colume size of the second matrix:"; cin >> r >> c;
                Matrix<int>m2(r, c);
                cout << "enter the second matrix:" << endl;
                cin >> m2;
                cout << "the answer:" << endl << m1 + m2 << endl;
            }
            else  if (num == 2)
            {
                cout << "enter the rows size and the colume size of the first matrix:"; cin >> r >> c;
                Matrix<int>m1(r, c);
                cout << "enter the first matrix:" << endl;
                cin >> m1;
                cout << "enter the rows size and the colume size of the second matrix:"; cin >> r >> c;
                Matrix<int>m2(r, c);
                cout << "enter the second matrix:" << endl;
                cin >> m2;
                cout << "the answer:" << endl << m1 - m2 << endl;
            }
            else if (num == 3)
            {
                cout << "enter the rows size and the colume size of the first matrix:"; cin >> r >> c;
                Matrix<int>m1(r, c);
                cout << "enter the first matrix:" << endl;
                cin >> m1;

                int r2, c2;
                cout << "enter the rows size and the colume size of the second matrix:"; cin >> r2 >> c2;
                if (c != r2) {
                    cout << "we cant preform this operation :(" << endl; continue;
                }
                Matrix<int>m2(r2, c2);
                cout << "enter the second matrix:" << endl;
                cin >> m2;
                cout << "the answer:" << endl << m1 * m2 << endl;
            }
            else if (num == 4)
            {
                cout << "enter the rows size and the colume size of the matrix:"; cin >> r >> c;
                Matrix<int>m1(r, c);
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
    Matrixcalculator obj;
    obj.start();
}
