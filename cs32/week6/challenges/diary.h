#ifndef DIARY_H
#define DIARY_H

#include <string>
#include <iostream>
#include <vector>

class Diary {
  public:
    Diary(const std::string& title) : m_title(title) {}
    virtual ~Diary() {
      //std::cout << "Diary destroyed" << std::endl;
    }

    void getTitle() const {
      std::cout << m_title << std::endl;
    }
    virtual void writeEntry(const std::string& entry) {
      //std::cout << "Diary write" << std::endl;
      m_entries.push_back(entry);
    }
    virtual void read() const {
      //std::cout << "Diary read" << std::endl;
      for (const auto& it : m_entries) {
        std::cout << it << std::endl;
      }
    }

  protected:
    std::vector<std::string> getEntries() const {
      return m_entries;
    }

  private:
    std::string m_title;
    std::vector<std::string> m_entries;
};

#endif