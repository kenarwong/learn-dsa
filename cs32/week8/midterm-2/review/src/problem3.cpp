#include "headers.h"
#include <stack>

bool Balanced(const std::string exp, int& maxDepth) {
  std::stack<char> paren;
  std::stack<char> curly;
  std::stack<char> square;

  int depth = 0;
  for (auto it = exp.begin(); it != exp.end(); it++) {
    switch (*it) {
      case '(':
        paren.push(*it);
        depth++;
        break;
      case '{':
        curly.push(*it);
        depth++;
        break;
      case '[':
        square.push(*it);
        depth++;
        break;
      case ')':
        if (paren.empty()) {
          maxDepth = 0;
          return false;
        }
        paren.pop();
        depth--;
        break;
      case '}':
        if (curly.empty()) {
          maxDepth = 0;
          return false;
        }
        curly.pop();
        depth--;
        break;
      case ']':
        if (square.empty()) {
          maxDepth = 0;
          return false;
        }
        square.pop();
        depth--;
        break;
    }

    if (depth > maxDepth) {
      maxDepth = depth;
    }
  }

  if (paren.empty() && curly.empty() && square.empty()) {
    return true;
  }

  maxDepth = 0;
  return false;
}

void Problem3() {
  std::cout << "Problem 3" << std::endl;

  std::string test1 = "bletch";                 // MaxDepth = 0
  int depth1 = 0;
  bool assert1 = true;

  std::string test2 = "{}";                     // MaxDepth = 1
  int depth2 = 1;
  bool assert2 = true;

  std::string test3 = "[( )( )]";               // MaxDepth = 2
  int depth3 = 2;
  bool assert3 = true;
  
  std::string test4 = "{goober[{face}]}";       // MaxDepth = 3
  int depth4 = 3;
  bool assert4 = true;

  std::string test5 = "(a(b((c)))d)[(ef{g})]";  // MaxDepth = 4
  int depth5 = 4;
  bool assert5 = true;

  std::string test6 = "Snitch[";                // MaxDepth = 0, unbalanced
  int depth6 = 0;
  bool assert6 = false;

  std::string test7 = "[fe[fi[fo}fum]ack)";     // MaxDepth = 0, unbalanced
  int depth7 = 0;
  bool assert7 = false;

  std::string test8 = "((start()())";           // MaxDepth = 0, unbalanced
  int depth8 = 0;
  bool assert8 = false;

  int nTests = 8;
  std::string tests[] = {test1, test2, test3, test4, test5, test6, test7, test8};
  bool asserts[] = {assert1, assert2, assert3, assert4, assert5, assert6, assert7, assert8};
  int depths[] = {depth1, depth2, depth3, depth4, depth5, depth6, depth7, depth8};

  for (int i = 0; i < nTests; i++) {
    int depth = 0;
    bool balanced = Balanced(tests[i], depth);
    std::cout << "Expression: " << tests[i] << std::endl;

    std::cout << "Expected Max Depth: " << depths[i] << std::endl;
    std::cout << "Actual Max Depth: " << depth << std::endl;

    std::cout << "Expected balanced result: " << asserts[i] << std::endl;
    std::cout << "Actual balanced result: " << balanced << std::endl;

    assert(depth == depths[i]);
    assert(balanced == asserts[i]);

    std::cout << std::endl;
  }
}