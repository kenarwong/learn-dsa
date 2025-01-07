#ifndef QUESTION_5_
#define QUESTION_5_

class Wallet
{
  public:
    Wallet(const double& dollars);
    virtual ~Wallet();

    bool isEmpty() const;
    virtual void deposit(const double& dollars);
    virtual double value() const;
  
  private:
    double  m_dollars;
};

Wallet::Wallet(const double& dollars)
{
  if (dollars < 0)
  {
    m_dollars = 0;
  }
  else
  {
    m_dollars = dollars;
  }
}

Wallet::~Wallet() {}

bool Wallet::isEmpty() const {
  if (m_dollars == 0) {
    return true;
  }

  return false;

}

void Wallet::deposit(const double& dollars) {
  if (dollars < 0)
  {
    return;
  }

  m_dollars += dollars;
}

double Wallet::value() const {
  return m_dollars;
}

class UKWallet : public Wallet
{
  public:
    UKWallet(const double& conversion);
    void deposit(double pounds);        // deposit in pounds
    double value();                     // return in pounds

  private:
    double m_conversion;                // dollars per pound
};

UKWallet::UKWallet(const double& conversion) : Wallet(0) {
  if(conversion <= 0) {
    m_conversion = 1.65;
  } else {
    m_conversion = conversion;
  }
}

void UKWallet::deposit(double pounds) {
  Wallet::deposit(pounds*m_conversion);
}

double UKWallet::value() {
  return Wallet::value()/m_conversion;
}

#endif