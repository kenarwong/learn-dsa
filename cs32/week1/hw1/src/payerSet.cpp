#include "payerSet.h"

PayerSet::PayerSet() {
  // Create an empty payer set.
}

bool PayerSet::add(unsigned long accountNum) {
  // If specified account number is not currently in this payer set
  // and there is room in the payer set, add that account number to
  // the payer set and return true.  Otherwise, make no change to
  // this payer set and return false.
  return m_set.insert(accountNum);
}

int PayerSet::size() const {
  // Return the number of account numbers in the PayerSet.
  return m_set.size();
}

void PayerSet::print() const {
  // Write to cout every account number in the PayerSet exactly
  // once, one per line.  Write no other text.  The lines need
  // not be in any particular order.
  unsigned long accountNum;
  for (int i = 0; i < m_set.size(); i++) {
    m_set.get(i, accountNum);
    std::cout << accountNum << std::endl;
  }
}