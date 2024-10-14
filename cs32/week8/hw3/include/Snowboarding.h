#ifndef SNOWBOARDING_H
#define SNOWBOARDING_H

#include "headers.h"
#include "Sport.h"

class Snowboarding : public Sport {
public:
  Snowboarding(std::string name);

  ~Snowboarding();

  std::string getObjectName() const; 
  bool isOutdoor() const; 
  std::string icon() const; 

private:

};

Snowboarding::Snowboarding(std::string name) : Sport(name) {
}

Snowboarding::~Snowboarding() {
  std::cout << "Destroying the " << getObjectName() << " object named " << getName() << "." << std::endl;
}

bool Snowboarding::getObjectName() const {
  return "Snowboarding";
}

bool Snowboarding::isOutdoor() const {
  return true;
}

std::string Snowboarding::icon() const
{
  return "a descending snowboarder";
}

#endif