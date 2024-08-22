#include "mathnerd.h"
#include <iostream>
using namespace std;

MathNerd::MathNerd(double a, double b) {
    this->a = a;
    this->b = b;
};

MathNerd::~MathNerd() {
    cout << "Destructor called" << endl;
};

int MathNerd::getMyValue(int x) {
    return a * x + b;
};