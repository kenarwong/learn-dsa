#include "question1.h"
#include <iostream>
#include <cassert>

void h(std::map<KeyType,ValueType>* scm)
{
  Photo p(scm, "inverted fountain", 1998);
}

void TestConstructorDestructor() {
  std::map<KeyType,ValueType> scm;
  Photo p1(&scm, "subject1", 2020);
  Photo p2(&scm, "subject2", 2020);
  Photo p3(&scm, "subject1", 2020);

  assert(scm.size() == 2);  
  assert(scm["subject1"] == 2);
  assert(scm["subject2"] == 1);

  h(&scm);

  // assert inverted fountain doesn't exist in map
  assert(scm.size() == 2);
  assert(scm.find("inverted fountain") == scm.end());
}

void TestCopyConstructor() {
  std::map<KeyType,ValueType> scm;
  Photo p1(&scm, "subject1", 2020);
  Photo p2(&scm, "subject2", 2020);
  Photo p3(&scm, "subject1", 2020);

  assert(scm.size() == 2);  
  assert(scm["subject1"] == 2);
  assert(scm["subject2"] == 1);

  Photo p4(p1);

  assert(scm.size() == 2);  
  assert(scm["subject1"] == 3);
  assert(scm["subject2"] == 1);
}

void TestAssignmentOperator() {
  std::map<KeyType,ValueType> scm;
  Photo p1(&scm, "subject1", 2020);
  Photo p2(&scm, "subject2", 2020);
  Photo p3(&scm, "subject1", 2021);

  assert(scm.size() == 2);  
  assert(scm["subject1"] == 2);
  assert(scm["subject2"] == 1);

  p1 = p3; // same subject

  // no change in counts
  assert(scm.size() == 2);  
  assert(scm["subject1"] == 2);
  assert(scm["subject2"] == 1);


  p2 = p1; // different subject

  assert(scm.size() == 1);  
  assert(scm["subject1"] == 3);
}

void TestMagazine() {
  std::map<KeyType,ValueType> scm;
  Magazine m(&scm, "title", "issue", 1, 2020, "subject");
}

int main()
{
  std::cout << "Question 1" << std::endl;
  TestConstructorDestructor();
  TestCopyConstructor();
  TestAssignmentOperator();
  TestMagazine();

  return 0;
}
