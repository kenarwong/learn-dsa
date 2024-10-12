#ifndef EXERCISES_H
#define EXERCISES_H

#include "headers.h"

bool isPal(const std::string str);

bool isAnBn(const std::string str);

int endPre(const std::string str, int first);
int evaluatePre(const std::map<char,int> values, const std::string str);

std::vector<std::string> generateWordsWithGrammarExercise2();

std::string generateWordWithGrammarExercise3(char c, int length); 

std::vector<std::string> generateWordsWithGrammarExercise4(int length); 

std::vector<std::string> generateWordsWithGrammarExercise5(int length); 

#endif