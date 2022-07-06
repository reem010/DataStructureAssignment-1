#include<iostream>
using namespace std;
#ifndef PROB2_FRACTION_H
#define PROB2_FRACTION_H
class lFraction {
private:
    int numi, deni;
public:
    lFraction(int ln = 1, int ld = 2) : numi(ln), deni(ld) {}
    lFraction operator+(lFraction f) const ;
    lFraction operator-(lFraction f) const ;
    lFraction operator*(lFraction f) const ;
    int gcd(int n, int d);
    lFraction operator/(lFraction f)  ;
    friend ostream &operator<<(ostream &out, lFraction &f) {
        cout << f.numi << " / " << f.deni;
        return out;
    }
    friend istream &operator>>(istream &in, lFraction &f1) {
        cout << "\nEnter numerator:";
        cin >> f1.numi;
        cout << "Enter denominator:";
        cin >> f1.deni;
        return in;
    }
    void ReduceFraction(lFraction g);
    bool operator==(lFraction f);
    bool operator!=(lFraction f);
    bool operator>=(lFraction f);
    bool operator<= (lFraction f);
};
#endif //PROB2_FRACTION_H
