#include "Set.h" // class template from problem 2
#include <string>
using namespace std;

class Coord
{
public:
  Coord(int rr, int cc) : m_row(rr), m_col(cc) {}
  Coord() : m_row(0), m_col(0) {}
  double r() const { return m_row; }
  double c() const { return m_col; }

  bool operator==(const Coord& otherCoord) {
    return m_row == otherCoord.m_row && m_col == otherCoord.m_col;
  }

  bool operator>(const Coord& otherCoord) {
    if (m_row > otherCoord.m_row){
      return true;
    } else if (m_row == otherCoord.m_row) {
      return m_col > otherCoord.m_col;
    }
    return false;
  }

private:
  double m_row;
  double m_col;
};

void Problem3()
{
  Set<int> si;
  si.insert(21); // OK
  Set<string> ss;
  ss.insert("21 Savage"); // OK
  Set<Coord> sc;
  sc.insert(Coord(21, -21)); // error!
}