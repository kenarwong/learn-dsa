#ifndef MATHNERD_H
#define MATHNERD_H

class MathNerd {
    public:
        MathNerd(double a, double b);
        ~MathNerd();
        int getMyValue(int x);
    private:
        double a;
        double b;
};

#endif