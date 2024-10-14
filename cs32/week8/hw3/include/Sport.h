#ifndef SPORT_H
#define SPORT_H

#include "headers.h"

class Sport {
public:
  Sport(std::string name);

  virtual ~Sport();

  // outputs name
  std::string name() const;

  // outputs object name
  virtual std::string getObjectName() const = 0; 

  // outputs bool 
  virtual bool isOutdoor() const = 0;

  // outputs icon name
  virtual std::string icon() const = 0; 

private:
  std::string m_name;
};

Sport::Sport(std::string name) : m_name(name) {
}

Sport::~Sport() {}

std::string Sport::name() const {
  return m_name;
}

#endif