#ifndef QUESTION_1_
#define QUESTION_1_

#include <iostream>

using namespace std;

class Icon
{
  public:
    Icon() { cout << "I "; }
    ~Icon() { cout << "~I "; }
};

class File
{
  public:
    File() { cout << "F "; }
    ~File() { cout << "~F "; }
  private:
    Icon m_icons[2];
};

class Rectangle
{
  public:
    Rectangle() { cout << "R "; }
    ~Rectangle() { cout << "~R "; }
};

class Caption
{
  public:
    Caption() { cout << "C "; }
    ~Caption() { cout << "~C "; }
};

class Picture : public File
{
  public:
    Picture() { cout << "P "; }
    ~Picture() { cout << "~P "; }
  private:
    Caption     m_caption;
    Rectangle*  m_boundary;
};

#endif