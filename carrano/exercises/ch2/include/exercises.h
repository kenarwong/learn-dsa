#ifndef EXERCISES_H
#define EXERCISES_H

#include "headers.h"

int sumUpTo(const int n, int array[]);

int sumRange(int start, int end);

void writeBackward(const std::string str) ;

void printNum(int n);

void printNumUp(int n);

int sumOfSquares(int n);

void writeDecimalReverse(int n);

void writeLine(char c, int n);
void writeBlock(char c, int n, int m);

int getValue(int a, int b, int n);

int search(int first, int last, int n);
int mystery(int n);

void displayAsOctal(int n);

int f(int n);

void recurseByValue(int x, int y);
void recurseByReference(int& x, int y);

int binarySearch(int array[], int search, int n);

#endif