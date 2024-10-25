#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;

namespace Problem1dNamespace
{

  vector<int> destroyedOnes;

  class Restaurant
  {
    public:
      Restaurant(int s) : m_stars(s) {}
      ~Restaurant() { destroyedOnes.push_back(m_stars); }
      int stars() const { return m_stars; }
    private:
      int m_stars;
  };

  // Remove the restaurants in v with 2 or fewer stars and destroy them.
  // It is acceptable if the order of the remaining restaurants is not
  // the same as in the original vector.
  void removeBad(vector<Problem1dNamespace::Restaurant *> &v)
  {
    for (auto it = v.begin(); it != v.end();)
      if ((*it)->stars() <= 2)
        {
          delete (*it);
          it = v.erase(it);
        }
      else
      {
        ++it;
      }
  }

  void test()
  {
    int a[9] = {2, 4, 3, 2, 4, 1, 1, 5, 2};
    vector<Problem1dNamespace::Restaurant *> x;
    for (int k = 0; k < 9; k++)
      x.push_back(new Problem1dNamespace::Restaurant(a[k]));
    assert(x.size() == 9 && x.front()->stars() == 2 && x.back()->stars() == 2);
    removeBad(x);
    assert(x.size() == 4 && destroyedOnes.size() == 5);
    vector<int> v;
    for (int k = 0; k < 4; k++)
      v.push_back(x[k]->stars());
    sort(v.begin(), v.end());
    int expect[4] = {3, 4, 4, 5};
    for (int k = 0; k < 4; k++)
      assert(v[k] == expect[k]);
    sort(destroyedOnes.begin(), destroyedOnes.end());
    int expectGone[5] = {1, 1, 2, 2, 2};
    for (int k = 0; k < 5; k++)
      assert(destroyedOnes[k] == expectGone[k]);
    for (vector<Problem1dNamespace::Restaurant *>::iterator p = x.begin(); p != x.end(); p++)
      delete *p;
  }
}

void Problem1d()
{
    Problem1dNamespace::test();
    cout << "Passed" << endl;
}