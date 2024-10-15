#include "headers.h"
#include <stack>

using namespace std;

bool balanced(const string &exp) {
    std::stack<int> paren;
    std::stack<int> curly;
    std::stack<int> square;

    for (int i = 0; i < exp.length(); i++) {
        switch (exp[i]) {
            case '(':
                paren.push(i);
                break;
            case ')':
                if (paren.size() != 0) {
                  paren.pop();
                } else {
                  return false;
                }

                break;
            case '{':
                curly.push(i);
                break;
            case '}':
                if (curly.size() != 0) {
                  curly.pop();
                } else {
                  return false;
                }

                break;
            case '[':
                square.push(i);
                break;
            case ']':
                if (square.size() != 0) {
                  square.pop();
                } else {
                  return false;
                }

                break;
        }
    }

    return paren.size() == 0 && curly.size() == 0 && square.size() == 0;
}