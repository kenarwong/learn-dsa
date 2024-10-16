#include "headers.h"

struct Node {
    int val;
    Node *next1, *next2;
};

int find_max(Node *p) {
    if (p == nullptr) {
        return -1;
    }

    int val1 = find_max(p->next1);
    int val2 = find_max(p->next2);

    if (p->val >= val1 && p->val >= val2) {
        return p->val;
    } else if (val1 >= p->val && val1 >= val2) {
        return val1;
    } else {
        return val2;
    }
}

void Problem1() {
  std::cout << "Problem 1" << std::endl;

  Node *p = new Node;
  p->val = 1;
  p->next1 = new Node;
  p->next1->val = 2;
  p->next1->next1 = new Node;
  p->next1->next1->val = 3;
  p->next1->next1->next1 = nullptr;
  p->next1->next2 = new Node;
  p->next1->next2->val = 4;
  p->next1->next2->next1 = nullptr;
  p->next1->next2->next2 = nullptr;
  p->next2 = new Node;
  p->next2->val = 5;
  p->next2->next1 = nullptr;
  p->next2->next2 = nullptr;

  int max = find_max(p);
  assert(max == 5);
  std::cout << "Max: " << max << std::endl;
}