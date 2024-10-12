#include "exercises.h"
#include "headers.h"
#include "helpers.h"
#include <set>
#include <queue>
#include <algorithm>
#include <locale>

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

int endPre(const std::string str, int first) {
  int last = str.length() - 1;

  if (first > last) {
    return -1;
  }

  char ch = str[first];
  if (islower(ch)) {
    return first; // End of prefix expression
  } else if(isoperator(ch)) {
    // Find end of first prefix expression after operator
    int firstEnd = endPre(str, first+1);

    // If first prefix expression found, find end of second prefix expression
    // Starts after first expression
    if (firstEnd > 0) {
      return endPre(str, firstEnd + 1);
    } else {
      return -1;
    }
  } else {
    return -1;
  }
}

int evaluatePre(const std::map<char,int> values, const std::string str) {
  int length = str.length();

  if (length == 1) {
    auto it = values.find(str[0]);
    if (it != values.end()) {
        return it->second; // convert to value
    } else {
        throw std::invalid_argument("Character not found in values map");
    }
  } else {
    char op = str[0]; // Get opcode

    // Get end of first prefix expression
    int end1 = endPre(str, 1);
    int operand1 = evaluatePre(values, str.substr(1, end1));

    int end2 = length - end1;
    int operand2 = evaluatePre(values, str.substr(end1+1, end2));

    return evaluateOperation(op, operand1, operand2);
  }
}

// Function to generate all possible <W> strings up to a maximum length
std::vector<std::string> generate_W(int max_length) {
    std::vector<std::string> W_list;
    std::queue<std::string> q;

    // Base case
    q.push("abb");
    W_list.push_back("abb");

    while (!q.empty()) {
        std::string current = q.front();
        q.pop();

        // Apply the recursive rule: a + <W> + bb
        std::string new_W = "a" + current + "bb";

        if (new_W.length() <= max_length) {
            W_list.push_back(new_W);
            q.push(new_W); // Enqueue for further derivations if needed
        }
    }

    return W_list;
}

std::vector<std::string> generateWordsWithGrammarExercise2() {
    const int MAX_LENGTH = 7;

    // Step 1: Generate all <W> strings
    std::vector<std::string> W_list = generate_W(MAX_LENGTH);

    // Step 2: Generate all <S> strings using BFS
    std::set<std::string> S_set;

    // Initialize S_set with base cases: "$" and all <W> strings
    S_set.insert("$");
    for (const auto& w : W_list) {
        S_set.insert(w);
    }

    // Initialize the queue with all current S strings to allow prepending '$'
    std::queue<std::string> q;

    // Enqueue "$" and all <W> strings
    q.push("$");
    for (const auto& w : W_list) {
        q.push(w);
    }

    while (!q.empty()) {
        std::string current = q.front();
        q.pop();

        // Apply the recursive rule: prepend '$' to the current string
        std::string new_S = "$" + current;

        // Check if the new string exceeds the maximum length
        if (new_S.length() > MAX_LENGTH) {
            continue; // Skip if it does
        }

        // Check if the new string is already generated
        if (S_set.find(new_S) == S_set.end()) {
            S_set.insert(new_S);
            q.push(new_S); // Enqueue for further derivations
        }
    }

    // Step 3: Sort the results by length and lexicographically
    std::vector<std::string> S_list(S_set.begin(), S_set.end());

    std::sort(S_list.begin(), S_list.end(), [&](const std::string &a, const std::string &b) -> bool {
        if (a.length() != b.length())
            return a.length() < b.length();
        return a < b;
    });

    return S_list;
}

std::string generateWordWithGrammarRecursionExercise3(std::string word, int max_length, char upper, char lower) {
  if (word.length() == max_length) {
    return word;
  }

  if (word.length() == 0) {
    word += upper;
    return generateWordWithGrammarRecursionExercise3(word, max_length, upper, lower);
  } else {
    word += lower;
    return generateWordWithGrammarRecursionExercise3(word, max_length, upper, lower);
  }
}

std::string generateWordWithGrammarExercise3(char c, int length)  {
    if (length <= 0) {
      return "";
    }

    char upper, lower;

    if (isupper(c)) {
      upper = c;
      lower = std::tolower(c, std::locale());
    } else if(islower(c)) {
      upper = std::toupper(c, std::locale());
      lower = c;
    } else {
      throw std::invalid_argument("Character is not a letter");
    }

    return generateWordWithGrammarRecursionExercise3("", length, upper, lower);
}

void generateWordWithGrammarRecursionExercise4(std::vector<std::string> &S_list, std::string word, int length) {
  if (word.length() == length) {
    S_list.push_back(word);
    return;
  }

  if (word.length() == 0) {
    std::string word1 = "..";
    generateWordWithGrammarRecursionExercise4(S_list, word1, length);
    std::string word2 = "--";
    generateWordWithGrammarRecursionExercise4(S_list, word2, length);
  } else if (word.length() == 3) {
    if (word[0] == '.') {
      word += '-';
      generateWordWithGrammarRecursionExercise4(S_list, word, length);
    } else {
      word += '.';
      generateWordWithGrammarRecursionExercise4(S_list, word, length);
    }
  } else {
    std::string word1 = word + ".";
    generateWordWithGrammarRecursionExercise4(S_list, word1, length);
    std::string word2 = word + "-";
    generateWordWithGrammarRecursionExercise4(S_list, word2, length);
  }

}

std::vector<std::string> generateWordsWithGrammarExercise4(int length) {
  if (length <= 0) {
    throw std::invalid_argument("Length must be greater than 0");
  }

  std::vector<std::string> S_list;
  generateWordWithGrammarRecursionExercise4(S_list, "", length);

  return S_list;
}

void generateWordWithGrammarRecursionExercise5(std::vector<std::string> &S_list, std::string word, int length, bool hasY) {
  if (word.length() == length) {
    S_list.push_back(word);
    return;
  }

  if (word.length() == length-1 && hasY) {
    word += "Y";
    S_list.push_back(word);
    return;
  }

  if (word.length() == 0) {
    generateWordWithGrammarRecursionExercise5(S_list, word + "X", length, false);
  } else {
    generateWordWithGrammarRecursionExercise5(S_list, word + "X", length, hasY);
    generateWordWithGrammarRecursionExercise5(S_list, word + "Y", length, true);
    generateWordWithGrammarRecursionExercise5(S_list, word + "Z", length, hasY);
  }
}

std::vector<std::string> generateWordsWithGrammarExercise5(int length) {
  if (length <= 0) {
    throw std::invalid_argument("Length must be greater than 0");
  }

  std::vector<std::string> S_list;
  generateWordWithGrammarRecursionExercise5(S_list, "", length, 0);

  return S_list;
}