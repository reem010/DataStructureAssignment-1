#ifndef FRACTION_H_INCLUDED 
#define FRACTION_H_INCLUDED 
#include<iostream> 
#include <algorithm> 
using namespace std;
class  Fraction
{
    int numerator;
    int denominator;
public:
    Fraction();
    void ReduceFraction();
    void operator+=(const Fraction& fraction);
    void operator-=(const Fraction& fraction);
    void operator*=(const Fraction& fraction);
    void operator/=(const Fraction& fraction);
    // comparing operations (for all the comparison we will change the fractions to double value and compare between them 
    bool operator<(const Fraction& frac);
    bool operator<=(const Fraction& frac);
    bool operator>(const Fraction& frac);
    bool operator>=(const Fraction& frac);
    bool operator==(const Fraction& frac);
    friend ostream& operator << (ostream& out, Fraction frac);
    friend istream& operator >> (istream& in, Fraction& frac);
private:
    // a private method which will help us with the comparison operations 
    double makeItDouble(int num, int den)
    {
        double temp = (double)num / den;
        return temp;
    }
};
#endif //FRACTION_H_INCLUDED