#include <iostream>
#include <numeric>
#include "fraction.h"

using namespace std;

Fraction::Fraction(int numerator, int denominator): numerator(numerator), denominator(denominator) {
    if(denominator == 0) {
        throw invalid_argument("Denominator of fraction cannot be equal to 1");
    }
}

int Fraction::getNumerator() const{
    return this->numerator;
}
int Fraction::getDenominator() const{
    return this->denominator;
}
void Fraction::setNumerator(int newValue) {
    this->numerator = newValue;
}
void Fraction::setDenominator(int newValue) {
    if(newValue == 0) {
        throw invalid_argument("Denominator of fraction cannot be equal to 1");
    }
    this->denominator = newValue;
}

Fraction operator+(const Fraction& f1, const Fraction& f2) {
    int num1 = f1.numerator*f2.denominator;
    int den = f1.denominator*f2.denominator;
    int num2 = f2.numerator*f1.denominator;
    int resNum = num1 + num2;
    int nwd = gcd(resNum, den);
    resNum /= nwd;
    den /= nwd;
    return Fraction(resNum, den);
}
Fraction operator*(const Fraction& f1, const Fraction& f2) {
    int num = f1.numerator*f2.numerator;
    int den = f1.denominator*f2.denominator;
    int nwd = gcd(num, den);
    num /= nwd;
    den /= nwd;
    return Fraction(num, den);
}