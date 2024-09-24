#ifndef QUADRATIC_INCLUDED
#define QUADRATIC_INCLUDED

class Quadratic
{
public:
    Quadratic(double a, double b, double c);

    ~Quadratic();

    void displayFormula();

private:
    double a;
    double b;
    double c;
};

#endif