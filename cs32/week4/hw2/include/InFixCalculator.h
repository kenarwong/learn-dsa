#ifndef INFIXCALCULATOR_H
#define INFIXCALCULATOR_H

#include "headers.h"
#include "Map.h"
#include "PostfixCalculator.h"
#include <algorithm>

class InFixCalculator {
public:
  int evaluate(std::string infix, Map& values, std::string& postfix, int& result);
  // Evaluates an integer arithmetic expression
  //   If infix is a syntactically valid infix integer expression whose
  //   only operands are single lower case letters (whether or not they
  //   appear in the values map), then postfix is set to the postfix
  //   form of the expression; otherwise postfix may or may not be
  //   changed, result is unchanged, and the function returns 1.  If
  //   infix is syntactically valid but contains at least one lower
  //   case letter operand that does not appear in the values map, then
  //   result is unchanged and the function returns 2.  If infix is
  //   syntactically valid and all its lower case operand letters
  //   appear in the values map, then if evaluating the expression
  //   (using for each letter in the expression the value in the map
  //   that corresponds to it) attempts to divide by zero, then result
  //   is unchanged and the function returns 3; otherwise, result is
  //   set to the value of the expression and the function returns 0.

private:
  std::string inFixToPostFix(const std::string& inFixExpression) const;
  bool validateSyntax(const std::string& inFixExpression) const;
  void removeSpaces(std::string& expression) const;

  bool isoperand(const char& c) const {
    // Lower case characters only
    return c >= 'a' && c <= 'z';
  }

  bool isoperator(const char& c) const {
    return c == '+' || c == '-' || c == '*' || c == '/';
  }

  bool operatorIsEqualOrGreaterPrecedenceCheck(const char& c1, const char& c2) const {
    // Multiply and divide will always have equal or higher precedence
    if (c2 == '*' || c2 == '/') {
      return true;
    } else if (c2 == '+' || c2 == '-') {
      // Add and subtract will only have equal or greater precedence over add and subtract
      return c1 == '+' || c1 == '-';
    }

    return false;
  }

  bool iswhitespace(const char& c) const {
    return c == ' ';
  }

  std::vector<std::string> split(const std::string &str) {
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
};

inline int InFixCalculator::evaluate(std::string infix, Map& values, std::string& postfix, int& result) {

  // validate syntax
  if (!validateSyntax(infix)) {
    // postfix/result unchanged
    return 1;
  }

  // convert to postfix form
  try {
    postfix = inFixToPostFix(infix);
  } catch (const std::runtime_error& e) {
    if (std::string(e.what()) == "Invalid infix expression") {
      // postfix/result unchanged
      return 1;
    }
    throw e;
  }

  // check that all operands are in values map
  for (size_t i = 0; i < infix.size(); i++) {
    if (isoperand(infix[i]) && !values.contains(infix[i])) {
      // postfix changed
      removeSpaces(postfix);
      // result unchanged
      return 2;
    }
  }

  // Create postfix expression with values
  std::vector<std::string> postfixArr = split(postfix);
  std::string postFixWithValues = "";
  for(size_t i = 0; i < postfixArr.size(); i++) {
    if (isoperand(postfixArr[i][0])) {
      postFixWithValues += std::to_string(values.get(postfixArr[i][0]));
    } else {
      postFixWithValues += postfixArr[i];
    }
    postFixWithValues += ' ';
  }
  postFixWithValues.pop_back();

  PostfixCalculator calc;
  try {
    result = calc.evaluatePostfixExpression(postFixWithValues);
    removeSpaces(postfix);
  } catch (const std::runtime_error& e) {
    // divide by zero
    if (std::string(e.what()) == "Division by zero") {
      // postfix changed
      removeSpaces(postfix);
      // result unchanged
      return 3;
    }

    if (std::string(e.what()) == "Invalid postfix expression") {
      // postfix changed
      removeSpaces(postfix);
      // result unchanged
      return 1;
    }

    throw e;
  }

  // result evaluated
  return 0;
}

inline std::string InFixCalculator::inFixToPostFix(const std::string& inFixExpression) const {
  std::string postFix = "";
  std::stack<char> operatorStack;

  for (auto it = inFixExpression.begin(); it != inFixExpression.end(); ++it) {
    if (isoperand(*it)) {
      // If operand, add to postfix
      postFix += *it;
      postFix += ' ';
    } else if (isoperator(*it)) {
      // If operator
      // Check current operator stack
      while (!operatorStack.empty()) {
        char op = operatorStack.top();

        // Check operator precedence
        // Continue until operator is lower precedence
        // Or until we reach an open parenthesis
        if (!operatorIsEqualOrGreaterPrecedenceCheck(*it, op) || op == '(') {
          break;
        }

        // Add operator to postfix
        postFix += op;
        postFix += ' ';

        operatorStack.pop();
      }

      // Add operator to stack
      operatorStack.push(*it);
    } else if (*it == '(') {
      // Push open parenthesis to stack
      operatorStack.push(*it);
    } else if (*it == ')') {
      // Pop operators until we reach an open parenthesis
      while (!operatorStack.empty()) {
        char op = operatorStack.top();
        if (op == '(') {
          operatorStack.pop();
          break;
        }

        postFix += op;
        postFix += ' ';

        operatorStack.pop();
      }
    } else if (iswhitespace(*it)) {
      // ignore
    } else {
      // invalid character
      throw std::runtime_error("Invalid infix expression");
    }
  }

  // Pop remaining operators
  while (!operatorStack.empty()) {
    postFix += operatorStack.top();
    postFix += ' ';
    operatorStack.pop();
  }

  postFix.pop_back(); // Remove last space

  return postFix;
}

inline bool InFixCalculator::validateSyntax(const std::string& inFixExpression) const {
  if (inFixExpression == "") {
    return false;
  }

  int parenthesisCount = 0;

  for(auto it = inFixExpression.begin(); it != inFixExpression.end(); ++it) {
    if (!isoperand(*it) && !isoperator(*it) && *it != '(' && *it != ')' && !iswhitespace(*it)) {
      return false;
    }

    if (*it == '(') {
      parenthesisCount++;

      // Recursive check for valid syntax within each parenthesis group
    }

    if (*it == ')') {
      parenthesisCount--;
    }
  }

  // Check for balanced parenthesis
  if (parenthesisCount != 0)
  {
    return false;
  }

  return true;
}

inline void InFixCalculator::removeSpaces(std::string& expression) const {
  // Remove spaces
  expression.erase(std::remove(expression.begin(), expression.end(), ' '), expression.end());
}

#endif