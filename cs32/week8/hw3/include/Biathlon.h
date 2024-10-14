#ifndef BIATHLON_H
#define BIATHLON_H

#include "headers.h"
#include "Sport.h"

class Biathlon : public Sport {
public:
  Biathlon(std::string name, float distance);

  ~Biathlon();

  std::string getObjectName() const; 
  bool isOutdoor() const; 
  std::string icon() const; 

private:
  float m_distance;
};

Biathlon::Biathlon(std::string name, float distance) : Sport(name) {
  m_distance = distance;
}

Biathlon::~Biathlon() {
  std::cout << "Destroying the " << getObjectName() << " object named " << getName() <<  ", distance " << m_distance << " km." << std::endl;
}

bool Biathlon::getObjectName() const {
  return "Biathlon";
}

bool Biathlon::isOutdoor() const {
  return true;
}

std::string Biathlon::icon() const
{
  return "a skier with a rifle";
}

#endif