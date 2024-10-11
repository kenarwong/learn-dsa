#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "headers.h"

int sumUpTo(const int n);

void printStringBackwards(std::string s);

void countDown(int n);

void writeArrayBackwards(const char anArray[], int size);

int binarySearch(const std::string *searchArray, size_t length, std::string value);

int kSmall(int k, int *anArray, size_t length);

void TowersOfHanoi(int numberOfDisks);

#endif