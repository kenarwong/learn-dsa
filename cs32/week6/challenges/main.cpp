#include "diary.h"
#include "secretdiary.h"

int main() {
  Diary myDiary("My Diary");
  myDiary.getTitle();
  myDiary.writeEntry("I'm learning C++");
  myDiary.writeEntry("Today, we are learning about polymorphism");
  myDiary.read();

  Diary* secretDiary = new SecretDiary();
  secretDiary->getTitle();
  secretDiary->writeEntry("I'm secretly napping");
  secretDiary->writeEntry("Today, I have no idea what I'm doing");
  
  // Call base class read method
  secretDiary->Diary::read();

  // Call derived class read method
  secretDiary->read();

  delete secretDiary;

  // Challenge 3
  //SecretDiary	a;
  //a.writeEntry("Dear diary,");
  //a.writeEntry("Those CS32 professors are sure great.");
  //a.writeEntry("Signed, Ahski Issar"); 
  //Diary	*b = &a;

  //b->getTitle();
  //b->read();

  // This would return encoded if Diary's read method was not virtual
  // It would reference the base class's read method instead

  return 0;
}