using namespace std;
#include <iostream>
#include "fraction.h"
void lFraction:: ReduceFraction(lFraction g){
    int num1,num2;
    num1/=g.numi;
    num2/=g.deni;
    gcd(num1,num2);

}
lFraction lFraction:: operator+(lFraction f) const {
        lFraction p;
        p.deni = deni * f.deni;
        p.numi = (numi * f.deni) + (f.numi * deni);
        p.ReduceFraction(p);
        return p;
    }
    lFraction lFraction:: operator-(lFraction f) const {
        lFraction p;
        p.deni = deni * f.deni;
        p.numi = (numi * f.deni) - (f.numi * deni);
        return p;
    }
    lFraction lFraction::operator*(lFraction f) const {
        lFraction p;
        p.deni = deni * f.deni;
        p.numi = numi * f.numi;
        p.ReduceFraction(p);
        return p;
    }
    int lFraction:: gcd(int n, int d)
    {
        int remainder;
        while (d != 0)
        {
            remainder = n % d;
            n = d;
            d = remainder;
        }
        return n;
    }
    lFraction lFraction:: operator/(lFraction f)  {
        lFraction p;
        p.deni = f.numi * deni;
        p.numi = numi * f.deni;
        p.ReduceFraction(p);
        return (p);
    }
    bool lFraction:: operator==(lFraction f)
    {
        if(numi==f.numi&&deni==f.deni )
        { return  true;}
        return false;
    }
    bool lFraction:: operator!=(lFraction f)
    {
        if(numi==f.numi&&deni==f.deni )
        { return  false;}
        return true;
    }
    bool lFraction:: operator>=(lFraction f)
    {
        if((float)numi/deni>=(float)f.numi/f.deni )
        {
            return true;
        }
        return false;
    }
    bool lFraction:: operator<= (lFraction f)
    {
        if((float)numi/deni<=(float)f.numi/f.deni )
        {
            return true;
        }
        return false;
    }


