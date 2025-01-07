#ifndef QUESTION_2_
#define QUESTION_2_

class Picture;

class Circle
{
  public:
    Circle(Picture* pp, double x, double y, double r)
      : m_picture(pp), m_x(x), m_y(y), m_radius(r)
    {}

    void setPicture(Picture* pp) { m_picture = pp; }
    double centerX() const { return m_x; }
    double centerY() const { return m_y; }
    double radius() const { return m_radius; }
  private:
    Picture* m_picture;
    double m_x;
    double m_y;
    double m_radius;
};

class Picture
{
  public:
    Picture() : m_nCircles(0) {}
    ~Picture();
    Picture(const Picture& other);
    Picture& operator=(const Picture& other);

    void addCircle(double x, double y, double r) {
      if (m_nCircles < 100) {
      m_Circles[m_nCircles++] = new Circle(this, x, y, r);
      }
    }

    Circle* getCircle(int i) {
      return m_Circles[i];
    }

  private:
    Circle* m_Circles[100];
    int     m_nCircles;
};

Picture::~Picture() {
  for (int i = 0; i < m_nCircles; i++) {
    delete m_Circles[i];
    // m_Circles[i] = nullptr;                        // Object is being destroyed, nullifying pointer has no effect
  }

  // delete[] m_Circles;                              // Invalid, m_Circles is statically allocated
}

// Picture::Picture(const Picture& other) {
//   m_nCircles = other.m_nCircles;                   // Can be assigned in constructor definition
//   m_Circles = new Circle*[100];                    // Invalid, m_Circles is statically allocated
//   for(int i = 0; i < m_nCircles; i++) {
//     Circle* otherC = other.m_Circles[i];
//     Circle* c = new Circle(this,                   // Without exception handling, this opens up possibility for memory leak 
//       otherC->centerX(),
//       otherC->centerY(),
//       otherC->radius());
//     m_Circles[i] = c;
//   }
// }

Picture::Picture(const Picture& other) : m_nCircles(other.m_nCircles) {
  for (int i = 0; i < m_nCircles; i++) {
    Circle* otherC = other.m_Circles[i];
    m_Circles[i] = new Circle(
      this, otherC->centerX(), otherC->centerY(), otherC->radius());
  }
}

// Picture& Picture::operator=(const Picture& other) {
//   if (this == &other) {
//     return *this;
//   }
// 
//   // delete[] m_Circles;                            // Invalid, m_Circles is statically allocated. Need to deallocate individual items (which are dynamically allocated).
// 
//   m_nCircles = other.m_nCircles;
//   for(int i = 0; i < m_nCircles; i++) {
//     Circle* otherC = other.m_Circles[i];
//     Circle* c = new Circle(this,
//       otherC->centerX(),
//       otherC->centerY(),
//       otherC->radius());
//     m_Circles[i] = c;
//   }
// 
//   return *this;
// }

Picture& Picture::operator=(const Picture& other) {
  if (this == &other) {
    return *this;
  }

  // Clean up existing circles
  for (int i = 0; i < m_nCircles; i++) {
    delete m_Circles[i];
    m_Circles[i] = nullptr;
  }

  m_nCircles = other.m_nCircles;

  // Copy new circles
  for (int i = 0; i < m_nCircles; i++) {
    Circle* otherC = other.m_Circles[i];
    m_Circles[i] = new Circle(
      this, otherC->centerX(), otherC->centerY(), otherC->radius());
  }

  return *this;
}


#endif