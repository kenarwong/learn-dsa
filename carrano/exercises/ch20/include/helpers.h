#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <string>
#include <map>
#include <list>

const uint INT_MAX = 0xffffffff;

template <size_t rows, size_t cols>
void printWeightMatrix(uint (&matrix)[rows][cols]) {
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      uint val = matrix[i][j];
      std::string s;
      if (val == INT_MAX) {
        s = "inf";
      } else {
        s = std::to_string(val);
      }

      std::cout << "\t" << s;
    }
    std::cout << std::endl;
  }
}

template <size_t rows, size_t cols>
void printNonWeightedMatrix(bool (&matrix)[rows][cols]) {
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      bool val = matrix[i][j];
      std::string s;
      if (val) {
        s = "1";
      } else {
        s = "0";
      }

      std::cout << "\t" << s;
    }
    std::cout << std::endl;
  }
}

void printMapListPair(const std::map<int, std::list<std::pair<int, int>>>& map);
void printMapList(const std::map<char, std::list<char>>& map);

template <typename LabelType>
void graphTraversalVisit(LabelType& vertex) {
  std::cout << "Visiting: " << vertex << std::endl;
}

#endif