#include <iostream>
#include "initialization.h"
using namespace std;

void Fraction::inputfrac() {
	cout << "Input numerator: "; cin >> numerator;
	cout << "Input denominator: "; cin >> denominator;
}

void Fraction::outputfrac() {
	cout << numerator << " / " << denominator << endl;
}

Fraction Fraction::add(Fraction other) {
	Fraction result;

	result.numerator = this->numerator * other.denominator + other.numerator * this->denominator;
	result.denominator = this->denominator * other.denominator;

	return result;
}

Fraction Fraction::minus(Fraction other) {
	Fraction result;

	result.numerator = this->numerator * other.denominator - other.numerator * this->denominator;
	result.denominator = this->denominator * other.denominator;

	return result;
}

Fraction Fraction::multiply(Fraction other) {
	Fraction result;

	result.numerator = this->numerator * other.numerator;
	result.denominator = this->denominator * other.denominator;

	return result;
}

void Fraction::divide(Fraction other) {
	double result;

	if (((double)this->denominator * (double)other.numerator) == 0) {
		cout << "Undefined" << endl;
	}
	else {
		result = ((double)this->numerator * (double)other.denominator) / ((double)this->denominator * (double)other.numerator);
		cout << "Division result: " << result << endl;
	}
}