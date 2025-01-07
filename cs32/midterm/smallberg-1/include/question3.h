#ifndef QUESTION_3_
#define QUESTION_3_

class LinkedList
{
  public:
    LinkedList();

    void push_back(int v);
    void unique();
    bool dominates(LinkedList& other) const
    { return dom(m_head, other.m_head); }

    void traverse(void (*visit)(int));
    void clear();

  private:
    struct Node
    {
      Node(int v, Node* n) : m_value(v), m_next(n) {}
      int   m_value;
      Node* m_next;
    };

    Node* m_head;
    Node* m_tail;
    bool  dom(const Node* p1, const Node* p2) const;
};

LinkedList::LinkedList() : m_head(nullptr), m_tail(nullptr) {}

void LinkedList::push_back(int v)
{
  Node* n = new Node(v, nullptr);

  if (m_tail == nullptr) {
    m_head = n;
    m_tail = n;
    return;
  } else {
    m_tail->m_next = n;
    m_tail = n;
  }
}

void LinkedList::unique() {
  if (m_head == nullptr) {
    return;
  }

  Node* cur = m_head;
  while(cur != nullptr) {
    // create a runner that will traverse the linked list and delete duplicates
    Node* runner = cur;

    while(runner != nullptr) {
      // delete all consecutive duplicates and relink

      // while next value is not null
      // and while the next value is equal to the current pointer
      while (runner->m_next != nullptr &&
        cur->m_value == runner->m_next->m_value) {
        // relink next next node to this node and delete next node
        Node* toDelete = runner->m_next;
        runner->m_next = toDelete->m_next;

        // if the value to delete is the tail
        // runner becomes new tail
        if (toDelete == m_tail) {
          m_tail = runner;
        }

        delete toDelete;
      }

      // no more consecutive duplicates, advance pointer
      runner = runner->m_next;
    }

    cur = cur->m_next;
  }
}

inline void LinkedList::traverse(void (*visit)(int))
{
  for (Node* cur = m_head; cur != nullptr; cur = cur->m_next) {
    visit(cur->m_value);
  }
}

void LinkedList::clear() {
  Node* cur = m_head;
  while(cur != nullptr) {
    Node* toDelete = cur;
    cur = cur->m_next;
    delete toDelete;
  }

  m_head = nullptr;
  m_tail = nullptr;
}

bool LinkedList::dom(const Node* p1, const Node* p2) const {
  // second element empty immediately means p1 dominates p2
  // even if p1 is empty
  if (p2 == nullptr) {
    return true;
  }

  // if p1 is empty, it does not dominate p2
  if (p1 == nullptr) {
    return false;
  }

  // both p1 and p2 exist
  if (p1->m_value < p2->m_value) {
    return false;
  } else {
    return dom(p1->m_next, p2->m_next);
  }
}

#endif