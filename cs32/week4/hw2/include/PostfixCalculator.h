#ifndef POSTFIX_CALCULATOR_H
#define POSTFIX_CALCULATOR_H

#include "headers.h"
#include <stack>

class PostfixCalculator
{
public:
   int evaluatePostfixExpression(const std::string& postfixExpression);

private:
    std::stack<int> istack;

    std::vector<std::string> split(const std::string& str) {
      std::vector<std::string> result;
      std::string current = "";
      for (auto it = str.begin(); it != str.end(); ++it) {
        if (iswhitespace(*it)) {
          if (current != "") {
            result.push_back(current);
            current = "";
          }
        } else {
          current += *it;
        }
      }
      if (current != "") {
        result.push_back(current);
      }
      return result;
    }

    bool isdigit(std::string s) {
      if (s[0] == '-') {
        // Negative number
        if (s.size() == 1) {
          // Negative operator
          return false;
        }
        s = s.substr(1);
      }
      for(auto c : s) {
        if (!std::isdigit(c)) {
          return false;
        }
      }
      return true;
    }

    bool iswhitespace(char c) {
      return c == ' ';
    }
};

int PostfixCalculator::evaluatePostfixExpression(const std::string& postfixExpression) {
  if (postfixExpression == "") {
    throw std::runtime_error("Invalid postfix expression");
  }

  std::vector<std::string> strArr = split(postfixExpression);

  for (size_t i = 0; i < strArr.size(); i++) {
    if (isdigit(strArr[i])) {
      istack.push(std::stoi(strArr[i]));
    } else if (iswhitespace(strArr[i][0])) {
      continue;
    } else {
      if (istack.size() < 2) {
        throw std::runtime_error("Invalid postfix expression");
      }
      int operand2 = istack.top(); istack.pop();
      int operand1 = istack.top(); istack.pop();
      switch (strArr[i][0]) {
        case '+':
          istack.push(operand1 + operand2);
          break;
        case '-':
          istack.push(operand1 - operand2);
          break;
        case '*':
          istack.push(operand1 * operand2);
          break;
        case '/':
          if (operand2 == 0) {
            throw std::runtime_error("Division by zero");
          }
          istack.push(operand1 / operand2);
          break;
        default:
          throw std::runtime_error("Invalid operator in postfix expression");
      }
    }
  }

  if (istack.size() != 1) {
    throw std::runtime_error("Invalid postfix expression");
  }

  int result = istack.top();
  istack.pop(); // Clear stack

  return result;
}

#endif