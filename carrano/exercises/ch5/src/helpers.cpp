#include "headers.h"
#include "helpers.h"
#include <regex>

bool iswhitespace(std::string str) {
  for (auto it = str.begin(); it != str.end(); ++it) {
    if(*it != ' ') {
      return false;
    }
  }

  return true;
}

bool isoperator(char c) {
  switch (c) {
    case '+': case '-': case '*': case '/':
      return true;
    default:
      return false;
  }
}

int evaluateOperation(char op, char operand1, char operand2) {
  switch (op) {
    case '+': 
      return operand1 + operand2;
    case '-': 
      return operand1 - operand2;
    case '*':
      return operand1 * operand2;
    case '/':
      return operand1 / operand2;
    default:
      return 0;
  }
}