#ifndef QUESTION_1_
#define QUESTION_1_

#include <map>
#include <string>

typedef std::string KeyType;
typedef int ValueType;

class Photo
{
  public:
    Photo(std::map<KeyType,ValueType>* scm, std::string subj, int yr);
    ~Photo();
    Photo(const Photo& other);
    Photo& operator=(const Photo& other);

    std::string subject() const { return m_subject; };
    int year() const { return m_year; };

  private:
    std::map<KeyType,ValueType>*   m_map;
    std::string m_subject;
    int         m_year;
};

Photo::Photo(std::map<KeyType,ValueType>* scm, std::string subj, int yr) : m_map(scm), m_subject(subj), m_year(yr) {
  auto item = scm->find(subj);
  if (item != scm->end()) {
    item->second++;
  } else {
    scm->insert(make_pair(subj,1));
  }
}

Photo::~Photo() {
  auto item = m_map->find(m_subject);
  if (item->second == 1) {
    m_map->erase(m_subject);
  } else {
    item->second--;
  }
}

Photo::Photo(const Photo& other) : m_map(other.m_map), m_subject(other.m_subject), m_year(other.m_year) {
  auto item = m_map->find(m_subject);
  item->second++;
}

Photo& Photo::operator=(const Photo& other){
  if (this == &other) {
    return *this;
  } 

  // only update if a different subject
  if (m_subject != other.m_subject) {
    // increment other subject's count
    auto item = m_map->find(other.m_subject);
    item->second++;

    // decrement this subject's count
    item = m_map->find(m_subject);
    if (item->second == 1) {
      m_map->erase(m_subject);
    } else {
      item->second--;
    }
  }

  m_map = other.m_map;
  m_subject = other.m_subject;
  m_year = other.m_year;

  return *this;
}

class Magazine
{
  public:
    Magazine(std::map<KeyType,ValueType>* scm, std::string t, std::string i, int pg, int yr, std::string subj);
  private:
    std::map<KeyType,ValueType>* m_map;
    std::string m_title;
    std::string m_issue;
    Photo m_coverPhoto;
    int m_pages;
};


Magazine::Magazine(std::map<KeyType, ValueType> *scm, std::string t, std::string i, int pg, int yr, std::string subj)
  : m_map(scm), m_title(t), m_issue(i), m_coverPhoto(scm, subj, yr), m_pages(pg)
{
}

#endif