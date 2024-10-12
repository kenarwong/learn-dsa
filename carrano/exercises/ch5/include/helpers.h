#ifndef HELPERS_H
#define HELPERS_H

#include "headers.h"

bool iswhitespace(std::string str);

bool isoperator(char c);
int evaluateOperation(char op, char operand1, char operand2);

#endif