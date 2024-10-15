#include "headers.h"
#include <queue>
#include <stack>

bool isQueue(const std::vector<int>& seq1, const std::vector<int>& seq2)
{
    std::queue<int> q;

    for (auto it = seq1.begin(); it != seq1.end(); ++it) {
        q.push(*it);
    }

    for (auto it = seq2.begin(); it != seq2.end(); ++it) {
        if (*it != q.front()) {
            return false;
        }

        q.pop();
    }

    return true;
}

bool isStack(const std::vector<int>& seq1, const std::vector<int>& seq2)
{
    std::stack<int> s;

    for (auto it = seq1.begin(); it != seq1.end(); ++it) {
        s.push(*it);
    }

    for (auto it = seq2.begin(); it != seq2.end(); ++it) {
        if (*it != s.top()) {
            return false;
        }

        s.pop();
    }

    return true;
}

void Problem1() {
  std::cout << "Problem 1" << std::endl;
  std::cout << "Enter the number of values in the sequence: ";

  int numberOfValues;
  while (std::cin >> numberOfValues) // leave loop if there is no next test case
  {
    std::cout << "Enter the values in the first sequence: ";
    std::vector<int> v1, v2;
    for (int i = 0; i < numberOfValues; i++)
    {
      int value;
      std::cin >> value;
      v1.push_back(value);
    }
    std::cout << "Enter the values in the second sequence: ";
    for (int i = 0; i < numberOfValues; i++)
    {
      int value;
      std::cin >> value;
      v2.push_back(value);
    }
    bool s = isStack(v1, v2);
    bool q = isQueue(v1, v2);
    if (s)
    {
      if (q)
        std::cout << "Either a Stack or a Queue!" << std::endl;
      else
        std::cout << "This is a Stack!" << std::endl;
    }
    else
    {
      if (q)
        std::cout << "This is a Queue!" << std::endl;
      else
        std::cout << "Neither a Stack or a Queue!" << std::endl;
    }

    // Ask if want to continue
    std::cout << "Press 1 to continue, 0 to stop: ";
    int cont;
    std::cin >> cont;
    if (cont == 0)
      break;

    std::cout << "Next test case: ";
  }
}