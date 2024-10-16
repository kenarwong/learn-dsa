#include "headers.h"

class SeaAnimal
{
public:
    SeaAnimal(float weight);

    virtual void makeNoise();

    float weight();
    void addWeight(float weight);

    virtual void eat(SeaAnimal* p);
private:
    float m_weight;
};

SeaAnimal::SeaAnimal(float weight) : m_weight(weight) {}

void SeaAnimal::makeNoise() {
    return;
}

float SeaAnimal::weight() {
    return m_weight;
}

void SeaAnimal::addWeight(float weight) {
    m_weight += weight;
}

void SeaAnimal::eat(SeaAnimal* p) {
    addWeight(p->weight());
    delete p;
    return;
}

class Otter : public SeaAnimal
{
public:
    Otter(float weight);
    void makeNoise();
};

Otter::Otter(float weight) : SeaAnimal(weight) {}

void Otter::makeNoise() {
    std::cout << "Bark" << std::endl;
}

class Squid : public SeaAnimal
{
public:
    Squid(float weight);
    void makeNoise();
};

Squid::Squid(float weight) : SeaAnimal(weight) {}

void Squid::makeNoise() {
    std::cout << "Squeak" << std::endl;
}

class GiantSquid : public Squid
{
public:
    GiantSquid();
    void eat(SeaAnimal* p);
};

GiantSquid::GiantSquid() : Squid(1000) {}

void GiantSquid::eat(SeaAnimal* p) {
    //SeaAnimal::eat(p);

    delete p;
    std::cout << "Burp" << std::endl;

    return;
}

void Problem2() {
  std::cout << "Problem 2" << std::endl;

  SeaAnimal *p1 = new Squid(10);
  std::cout << "Weight of p1: " << p1->weight() << std::endl;
  p1->makeNoise();

  SeaAnimal *p2 = new Otter(50);
  std::cout << "Weight of p2: " << p2->weight() << std::endl;
  p2->makeNoise();

  SeaAnimal *p3 = new GiantSquid();
  std::cout << "Weight of p3: " << p3->weight() << std::endl;
  p3->makeNoise();

  std::cout << "p2 eats p1" << std::endl;
  p2->eat(p1);
  std::cout << "Weight of p2: " << p2->weight() << std::endl;

  std::cout << "p3 eats p2" << std::endl;
  p3->eat(p2);
  std::cout << "Weight of p3: " << p3->weight() << std::endl;

  delete p3;
  return;
}