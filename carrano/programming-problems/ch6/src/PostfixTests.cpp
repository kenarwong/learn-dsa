#include "PostfixCalculator.h"
#include <cassert>
#include <iostream>

void testPostfixCalculator() {
  PostfixCalculator calc;

  // Test 1: Simple addition
  assert(calc.evaluatePostfixExpression("3 4 +") == 7);
  std::cout << "Test 1 passed: 3 4 + == 7" << std::endl;

  // Test 2: Simple subtraction
  assert(calc.evaluatePostfixExpression("10 5 -") == 5);
  std::cout << "Test 2 passed: 10 5 - == 5" << std::endl;

  // Test 3: Simple multiplication
  assert(calc.evaluatePostfixExpression("6 7 *") == 42);
  std::cout << "Test 3 passed: 6 7 * == 42" << std::endl;

  // Test 4: Simple division
  assert(calc.evaluatePostfixExpression("8 2 /") == 4);
  std::cout << "Test 4 passed: 8 2 / == 4" << std::endl;

  // Test 5: Complex expression
  assert(calc.evaluatePostfixExpression("5 1 2 + 4 * + 3 -") == 14);
  std::cout << "Test 5 passed: 5 1 2 + 4 * + 3 - == 14" << std::endl;

  // Test 6: Division by zero
  try {
    calc.evaluatePostfixExpression("4 0 /");
    std::cout << "Test 6 failed: Division by zero not handled" << std::endl;
  } catch (const std::runtime_error& e) {
    std::cout << "Test 6 passed: Division by zero handled" << std::endl;
  }

  // Test 7: Negative result
  assert(calc.evaluatePostfixExpression("3 5 -") == -2);
  std::cout << "Test 7 passed: 3 5 - == -2" << std::endl;

  // Test 8: Multiple operations
  assert(calc.evaluatePostfixExpression("2 3 + 5 *") == 25);
  std::cout << "Test 8 passed: 2 3 + 5 * == 25" << std::endl;

  // Test 9: Single operand
  assert(calc.evaluatePostfixExpression("42") == 42);
  std::cout << "Test 9 passed: 42 == 42" << std::endl;

  // Test 10: Invalid expression
  try {
    calc.evaluatePostfixExpression("2 +");
    std::cout << "Test 10 failed: Invalid expression not handled" << std::endl;
  } catch (const std::runtime_error& e) {
    std::cout << "Test 10 passed: Invalid expression handled" << std::endl;
  }
}