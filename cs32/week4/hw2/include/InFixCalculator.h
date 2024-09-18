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
  bool validateSyntax(const std::string& inFixExpression);
  bool validateSyntax(const std::string& inFixExpression, int& index, int& parenthesisCount);
  void removeSpaces(std::string& expression) const;
  std::string removeSpaces(const std::string& expression) const;

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
  int operatorCount = 0;
  for (size_t i = 0; i < infix.size(); i++) {
    if (isoperand(infix[i]) && !values.contains(infix[i])) {
      // Missing operand value
      
      // postfix changed
      removeSpaces(postfix);
      // result unchanged
      return 2;
    }

    operatorCount++;
  }

  // If only one operand, do not pass to evaluatePostfixExpression
  // evaluatePostfixExpression only handles operations
  // Just return value
  if (operatorCount == 1) {
    result = values.get(postfix[0]);
    removeSpaces(postfix);
    return 0;
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

  // Pass to PostfixCalculator
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

inline bool InFixCalculator::validateSyntax(const std::string& inFixExpression) {
  // Initial check
  if (removeSpaces(inFixExpression) == "") {
    return false;
  }

  int index = 0;
  int parenthesisCount = 0;
  return validateSyntax(inFixExpression, index, parenthesisCount);
}

inline bool InFixCalculator::validateSyntax(const std::string& inFixExpression, int& index, int& parenthesisCount) {
  // Syntax Logic
  // Initial operand/expression
  // If operand/expression is followed by operator, then an operand or a valid inner expression must follow
    // If true, then everything becomes initial operand

  // Truth Table 
  // OPAND OPTOR OPAND OPTOR OPAND OUT
  // 0     x     x     x     x     0
  // 1     0     0     0     0     1
  // 1     0     1     x     x     0
  // 1     1     0     x     x     0
  // 1     1     1     0     0     1
  // 1     1     1     0     1     0
  // 1     1     1     1     0     0
  // 1     1     1     1     1     1
  //
  // OPAND XNOR(OPTOR,OPAND) OUT
  // 0     x                 0
  // 1     0                 0
  // 1     1                 1

  // Evaluate expression
  bool opand1 = false, optor = false, opand2 = false;

  // Helper function to determine if expression is valid
  auto evaluateOperation = [&opand1, &optor, &opand2]() -> bool {
    return opand1 && !(optor ^ opand2);
  };

  // Helper function to set appropriate operand flag
  auto setOperandFlags = [&opand1, &optor, &opand2, &evaluateOperation]() -> bool {
    // Base case
    if(!opand1 && !optor && !opand2) {
      // This is first operand
      opand1 = true;
      return true;
    } else if(opand1 && optor && !opand2) {
      // Second case
      // If second operand is not already set
      // This is the second operand
      opand2 = true;

      // Evaluate expression
      if (!evaluateOperation()) {
        return false;
      } else {
        // Reset values
        opand1 = true;
        optor = false;
        opand2 = false;
        return true;
      }
    }

    // An operand cannot follow an operand
    return false;
  };

  while(index < inFixExpression.length()) {
    char it = inFixExpression[index];

    // Check for invalid characters
    // Allow whitespace (won't do anything with it)
    if (!isoperand(it) && !isoperator(it) && it != '(' && it != ')' && !iswhitespace(it)) {
      return false;
    }

    if (isoperand(it)) {
        // Set appropriate operand flag
        // Check if valid
        if (!setOperandFlags()){
          return false;
        }
    } else if (isoperator(it)) {
        // Check opand1
        if (!opand1) {
          // Operator must follow an operand
          return false;
        }

        optor = true;
    } else if (it == '(') {
        parenthesisCount++; // Increment parenthesisCount
        //int startIndex = index; // Save start index

        // Recursive call starting from after the parenthesis
        index++;
        bool result = validateSyntax(inFixExpression, index, parenthesisCount);

        // Index after returned index is the end index
        // Everything between start and end index is a valid expression (equivalent to an operand, OPAND)

        // If result is not valid then abort
        if (!result) {
          return false;
        }

        // If result is valid, then we can treat the valid expression as an operand
        // Set appropriate operand flag
        // Check if valid
        if (!setOperandFlags()){
          return false;
        }
    } else if (it == ')') {
        parenthesisCount--; // Decrement parenthesisCount

        // Parentheses not balanced
        if (parenthesisCount < 0) {
          return false;
        }

        // Evaluate expression and return from recursive call
        return evaluateOperation();
    } else {
        // Ignore whitespace
    }

    index++;
  }
  // Reached end of expression

  // Parentheses not balanced
  // Also means that an expression is not closed and we are still in a recursive call
  if (parenthesisCount != 0) {
    return false;
  }

  // Final evaluation of entire expression
  return evaluateOperation();
}

inline void InFixCalculator::removeSpaces(std::string& expression) const {
  // Remove spaces
  expression.erase(std::remove(expression.begin(), expression.end(), ' '), expression.end());
}

std::string InFixCalculator::removeSpaces(const std::string& expression) const {
    std::string result;
    for (char c : expression) {
        if (!isspace(c)) {
            result += c;
        }
    }
    return result;
}

#endif