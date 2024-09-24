#ifndef SECRET_DIARY_H
#define SECRET_DIARY_H

#include "diary.h"

class SecretDiary : public Diary {
  public:
    SecretDiary() : Diary("TOP-SECRET") {};
    virtual ~SecretDiary() {
      //std::cout << "Secret Diary destroyed" << std::endl;
    };
    
    virtual void writeEntry(const std::string& entry) {
      //std::cout << "SecretDiary write" << std::endl;
      Diary::writeEntry(encode(entry));
    }
    
    virtual void read() const {
      std::cout << "SecretDiary read" << std::endl;
      for (auto it : getEntries()) {
        std::cout << decode(it) << std::endl;
      }
    }

  private:
    std::string encode(const std::string& s) {
      //std::cout << "Encoding..." << std::endl;

      std::string encoded = s;
      for (auto& c : encoded) {
        c += 1;
        //std::cout << static_cast<int>(c) << std::endl;
      }

      return encoded;
    }
    std::string decode(const std::string& s) const {
      std::string decoded = s;
      for (auto& c : decoded) {
        //std::cout << c << std::endl;
        c -= 1;
      }
      return decoded;
    }
};

#endif