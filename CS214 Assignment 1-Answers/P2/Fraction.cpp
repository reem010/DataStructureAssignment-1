#include<iostream>
#include <algorithm>
#include"Fraction.h"
using namespace std;

Fraction::Fraction()
{
    numerator = 1;
    denominator = 1;
}
void Fraction::ReduceFraction()
{
    // we will use the __gcd() built in function to get the greatest common divisor and divide both the numerator and denominator by this value
    int  key = __gcd(numerator, denominator);
    numerator /= key;
    denominator /= key;
}
void Fraction :: operator+=(const Fraction& fraction)
{
    numerator = ((numerator * fraction.denominator) + (denominator * fraction.numerator));
    denominator = (denominator * fraction.denominator);

}
void Fraction :: operator-=(const Fraction& fraction)
{
    numerator = ((numerator * fraction.denominator) - (denominator * fraction.numerator));
    denominator = (denominator * fraction.denominator);

}
void Fraction:: operator*=(const Fraction& fraction)
{
    numerator *= fraction.numerator;
    denominator *= fraction.denominator;
}
void Fraction:: operator/=(const Fraction& fraction)
{
    denominator *= fraction.numerator;
    numerator *= fraction.denominator;
}
bool Fraction:: operator<(const Fraction& frac)
{
    double mainFrac = makeItDouble(numerator, denominator);
    double otherFrac = makeItDouble(frac.numerator, frac.denominator);
    if (mainFrac < otherFrac)
        return true;
    return false;
}
bool Fraction:: operator<=(const Fraction& frac)
{
    double mainFrac = makeItDouble(numerator, denominator);
    double otherFrac = makeItDouble(frac.numerator, frac.denominator);
    if (mainFrac <= otherFrac)
        return true;
    return false;
}
bool Fraction:: operator>(const Fraction& frac)
{
    double mainFrac = makeItDouble(numerator, denominator);
    double otherFrac = makeItDouble(frac.numerator, frac.denominator);
    if (mainFrac > otherFrac)
        return true;
    return false;
}
bool Fraction:: operator>=(const Fraction& frac)
{
    double mainFrac = makeItDouble(numerator, denominator);
    double otherFrac = makeItDouble(frac.numerator, frac.denominator);
    return mainFrac >= otherFrac;
}
bool Fraction::operator==(const Fraction& frac)
{
    double mainFrac = makeItDouble(numerator, denominator);
    double otherFrac = makeItDouble(frac.numerator, frac.denominator);
    return mainFrac == otherFrac;

}
ostream& operator << (ostream& out, Fraction frac)
{
    // if the numerator is zero -> zero / any number= zero so we just print zero
    if (frac.numerator == 0) { out << 0; return out; }
    // if the denominator is 1 -> any number / 1 = that any number so we just print the numerator
    if (frac.denominator == 1) { out << frac.numerator; return out; }

    //other wise we print the fraction normally
    out << frac.numerator << "/" << frac.denominator;
    return out;
}
istream& operator >> (istream& in, Fraction& frac)
{
    int nu, de; char slash;
    //we will take the slash as and input but we will ignore it (we wont use it at all)
    in >> nu >> slash >> de;

    // if the denominator is zero we have to ignore it
    if (de == 0)
    {
        return in;
    }
    if (de < 0)
    {
        nu *= -1;
        de *= -1;
    }
    frac.denominator = de;
    frac.numerator = nu;
    return in;
}
