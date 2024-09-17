#ifndef MAP_H
#define MAP_H

#include "headers.h"
#include <unordered_map>

class Map {
  public:
    Map();
    ~Map();
    void insert(char key, int value);
    int get(char key) const;
    std::vector<char> keys() const;
    bool update(char key, int value);
    bool remove(char key);
    bool contains(char key) const;
    int size() const;
    bool empty() const;
    void clear();
    void display() const;

  private:
    std::unordered_map<char, int> m_map;
};

inline Map::Map()
{
}

inline Map::~Map()
{
}

inline void Map::insert(char key, int value)
{
  m_map[key] = value;
}

inline int Map::get(char key) const
{
  return m_map.at(key);
}

inline std::vector<char> Map::keys() const
{
  std::vector<char> keys;
  keys.reserve(m_map.size());
  for (const auto& pair : m_map) {
    keys.push_back(pair.first);
  }
  return keys;
}

inline bool Map::update(char key, int value)
{
  m_map[key] = value;
  return true;
}

inline bool Map::remove(char key)
{
  if (m_map.find(key) == m_map.end()) {
    return false;
  }

  m_map.erase(key);
  return true;
}

inline bool Map::contains(char key) const
{
  if (m_map.find(key) != m_map.end()) {
    //std::cout << "map contains key" << key << std::endl;

    return true;
  }
  return false;
}

inline int Map::size() const
{
  return m_map.size();
}

inline bool Map::empty() const
{
  return m_map.empty();
}

inline void Map::clear()
{
  m_map.clear();
}

inline void Map::display() const
{
  for (auto it = m_map.begin(); it != m_map.end(); ++it) {
    std::cout << it->first << " => " << it->second << std::endl;
  }
}

#endif