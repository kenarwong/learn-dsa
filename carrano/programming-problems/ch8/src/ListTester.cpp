#include "ListInterface.h"
#include "LinkedList.h"
#include "headers.h"

using namespace std;

void displayList(ListInterface<std::string>* listPtr)
{
  std::cout << "The list contains " << listPtr->getCurrentSize()
            << " items:" << std::endl;
  std::vector<std::string> listItems = listPtr->toVector();
  int numberOfEntries = listItems.size();
  for (int i = 0; i < numberOfEntries; i++)
  {
     std::cout << listItems[i] << " ";
  } // end for
  std::cout << std::endl << std::endl;
} // end displayList

void listTester(ListInterface<std::string>* listPtr)
{
  std::cout << "isEmpty: returns " << listPtr->isEmpty()
            << "; should be 1 (true)" << std::endl;
  std::string items[] = {"one", "two", "three", "four", "five", "one"};
  std::cout << "Add 6 items (1 duplicate) to the list: " << std::endl;
  for (int i = 0; i < 6; i++)
  {
     listPtr->add(items[i]);
  } // end for
  
  displayList(listPtr);
  std::cout << "isEmpty: returns " << listPtr->isEmpty()
            << "; should be 0 (false)" << std::endl;
  std::cout << "getCurrentSize returns : " << listPtr->getCurrentSize()
            << "; should be 5" << std::endl;
  std::cout << "Try to add another entry: add(\"extra\") returns "
            << listPtr->add("extra") << std::endl;
} // end listTester

int ListTester()
{
  ListInterface<std::string>* listPtr = nullptr;
  listPtr = new LinkedList<std::string>();
  std::cout << "Testing the Link-Based List:" << std::endl;
   
  std::cout << "The initial list is empty." << std::endl;
  listTester(listPtr);
  delete listPtr;
  listPtr = nullptr;
  std::cout << "All done!" << std::endl;
  
  return 0;
} // end main