#include <helpers.h>

void printMapListPair(const std::map<int, std::list<std::pair<int,int>>>& mapList) {
  for (const auto& pair : mapList) {
    std::cout << "Vertex " << pair.first << ":" << "\t";
    std::list<std::pair<int,int>> list = pair.second;

    for(auto it = list.begin(); it != list.end(); ++it) {
      std::cout << "(" << (*it).first << "," << (*it).second << ")" << "\t";
    }

    std::cout << std::endl;
  }
}

void printMapList(const std::map<char, std::list<char>>& mapList) {
  for (const auto& pair : mapList) {
    std::cout << "Vertex " << pair.first << ":" << "\t";
    std::list<char> list = pair.second;

    for(auto it = list.begin(); it != list.end(); ++it) {
      std::cout << "(" << (*it) << ")" << "\t";
    }

    std::cout << std::endl;
  }
}