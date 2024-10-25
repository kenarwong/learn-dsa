#include "headers.h"
#include "helpers.h"

bool iswhitespace(std::string str) {
  for (auto it = str.begin(); it != str.end(); ++it) {
    if(*it != ' ') {
      return false;
    }
  }

  return true;
}