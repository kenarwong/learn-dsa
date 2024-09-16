#ifndef POINT_H
#define POINT_H

class Coord {
public:
  Coord(int rr, int cc) : m_r(rr), m_c(cc) {}

  int r() const { 
    return m_r;
  }
  int c() const { 
    return m_c;
  }
  
private:
  int m_r;
  int m_c;
};

#endif