#ifndef FIGURESKATING_H
#define FIGURESKATING_H

#include "headers.h"
#include "Sport.h"

class FigureSkating : public Sport {
public:
  FigureSkating(std::string name);

  ~FigureSkating();
  
  std::string getObjectName() const; 
  bool isOutdoor() const; 
  std::string icon() const; 

private:

};

FigureSkating::FigureSkating(std::string name) : Sport(name) {
}

FigureSkating::~FigureSkating() {
  std::cout << "Destroying the " << getObjectName() << " object named " << getName() << "." << std::endl;
}

bool FigureSkating::getObjectName() const {
  return "FigureSkating";
}

bool FigureSkating::isOutdoor() const {
  return false;
}

std::string FigureSkating::icon() const
{
  return "a skater in the Biellmann position";
}

#endif