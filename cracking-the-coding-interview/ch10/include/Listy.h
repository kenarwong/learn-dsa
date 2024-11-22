#ifndef LISTY_H
#define LISTY_H

const int LISTY_MAX_SIZE = 100;
const int LISTY_MAX_RANGE = 255;

class Listy {
  public:
    Listy();
    ~Listy();
    void display() const;
    int returnRandomElement() const;
    int elementAt(int i) const;

  private:
    int size;
    int* arr;
};

#endif