#include "exercises.h"
#include "headers.h"
#include "helpers.h"

bool isPal(const char* c, int start, int end) {
  int length = end - start + 1;
  if (length == 0 || length == 1) {
    return true;
  }
  
  return (c[start] == c[end] && isPal(c, start + 1, end - 1));
}

bool isPal(const std::string str) {
  if(!iswhitespace(str)) {
    return isPal(str.c_str(), 0, str.size()-1);
  }

  return true;
}

bool isAnBn(const char* c, int start, int end) {
  if (start > end) {
    return true;
  }

  return (c[start] == 'A' && c[end] == 'B' && isAnBn(c, start + 1, end - 1));

}

bool isAnBn(const std::string str) {
  if(!iswhitespace(str)) {
    return isAnBn(str.c_str(), 0, str.size()-1);
  }

  return false;
}