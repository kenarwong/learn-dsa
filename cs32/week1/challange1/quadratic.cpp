#include "quadratic.h"
#include <iostream>
using namespace std;

Quadratic::Quadratic(double a, double b, double c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

Quadratic::~Quadratic() {
    cout << "Destructor called" << endl;
}

void Quadratic::displayFormula()
{
    cout << "The formula is " << a << "x^2 + " << b << "x + " << c << endl;
}