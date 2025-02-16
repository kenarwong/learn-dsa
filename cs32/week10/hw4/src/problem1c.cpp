#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;

namespace Problem1cNamespace
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

  // Remove the restaurants in li with 2 or fewer stars and destroy them.
  // It is acceptable if the order of the remaining restaurants is not
  // the same as in the original list.
  void removeBad(list<Problem1cNamespace::Restaurant *> &li)
  {
    for (auto it = li.begin(); it != li.end();)
      if ((*it)->stars() <= 2)
        {
          delete (*it);
          it = li.erase(it);
        }
      else
      {
        ++it;
      }
  }

  void test()
  {
    int a[9] = {2, 4, 3, 2, 4, 1, 1, 5, 2};
    list<Problem1cNamespace::Restaurant *> x;
    for (int k = 0; k < 9; k++)
      x.push_back(new Problem1cNamespace::Restaurant(a[k]));
    assert(x.size() == 9 && x.front()->stars() == 2 && x.back()->stars() == 2);
    removeBad(x);
    assert(x.size() == 4 && destroyedOnes.size() == 5);
    vector<int> v;
    for (list<Problem1cNamespace::Restaurant *>::iterator p = x.begin(); p != x.end(); p++)
    {
      Problem1cNamespace::Restaurant *rp = *p;
      v.push_back(rp->stars());
    }
    // Aside:  Since C++11, the above loop could be
    //     for (auto p = x.begin(); p != x.end(); p++)
    //     {
    //         Problem1cNamespace::Restaurant* rp = *p;
    //         v.push_back(rp->stars());
    //     }
    // or
    //     for (auto p = x.begin(); p != x.end(); p++)
    //     {
    //         auto rp = *p;
    //         v.push_back(rp->stars());
    //     }
    // or
    //     for (Problem1cNamespace::Restaurant* rp : x)
    //         v.push_back(rp->stars());
    // or
    //     for (auto rp : x)
    //         v.push_back(rp->stars());
    sort(v.begin(), v.end());
    int expect[4] = {3, 4, 4, 5};
    for (int k = 0; k < 4; k++)
      assert(v[k] == expect[k]);
    sort(destroyedOnes.begin(), destroyedOnes.end());
    int expectGone[5] = {1, 1, 2, 2, 2};
    for (int k = 0; k < 5; k++)
      assert(destroyedOnes[k] == expectGone[k]);
    for (list<Problem1cNamespace::Restaurant *>::iterator p = x.begin(); p != x.end(); p++)
      delete *p;
  }
}

void Problem1c()
{
  Problem1cNamespace::test();
  cout << "Passed" << endl;
}