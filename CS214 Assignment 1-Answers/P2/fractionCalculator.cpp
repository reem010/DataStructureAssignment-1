#include "fractionCalculator.h"
void fractionCalculator::calculate() {
    int num;
    lFraction f1,f2,f3;
    bool mode= true;
    cout<<"\nWelcome in Fraction Calculator \n";
    cout<<"........................................\n";
    cout<<"Enter your First Fraction";
    cin>>f1;
    cout<<"\nEnter your Second Fraction";
    cin>>f2;
    cout<<".........................................\n";
    while (mode==true){
        cout<<"\n1-Addition \n"<<
              "2-Subtraction\n"<<
              "3-Multiplication\n"<<
              "4-Division\n"
              <<"5-Equal\n"
              <<"6-Greater fraction\n"
              <<"7-Exit\n"<<endl;
        cout<<"Enter number of operator you need\n";
        cin>>num;
        switch (num) {
            case 1:
            {
                f3=f1+f2;
                cout<<"Addition is: "<<f3;
                break;
            }
            case 2:
            {
                f3=f1-f2;
                cout<<"Subtraction is: "<<f3;
                break;
            }
            case 3:
            {
                f3=f1*f2;
                cout<<"Multiplication is: "<<f3;
                break;
            }
            case 4:
            {
                f3=f1/f2;
                cout<<"Division is: "<<f3;
                break;
            }
            case 5:{
                if(f1==f2){
                    cout<<"f1 equal f2\n";
                    break;
                }
                else{
                    cout<<"f1 not equal f2\n";
                    break;
                }
            }
            case 6:{
                 if(f1>=f2){
                    cout<<"f1 greater than or equal f2\n";
                    break;
                }
                else{
                    cout<<"f2 greater than f1"<<endl;
                    break;
                }
            }
            case 7:
            {
                mode= false;
                break;
            }
            default:
            {
                cout<<"Enter number between 1 and 7\n";
            }
        }
    }
}
