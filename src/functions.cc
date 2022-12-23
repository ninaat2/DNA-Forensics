#include "functions.hpp"

#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

int CountStrs(std::string to_analyze, std::string str) {
  int max = 0;
  int current_count = 0;
  for (unsigned int i = 0; i < to_analyze.size(); ++i) {
    bool possible = true;
    if (i + str.size() - 1 >= to_analyze.size()) {
      possible = false;
    } else {
      for (unsigned int j = 0; j < str.size(); ++j) {
        if (to_analyze.at(i + j) != str.at(j)) {
          possible = false;
        }
      }
    }
    if (possible) {
      current_count += 1;
      i += str.size() - 1;
    } else {
      current_count = 0;
    }
    if (current_count > max) {
      max = current_count;
    }
  }
  return max;
}

std::string Compare(
    const std::map<std::string, int> kStrCount,
    const std::map<std::map<std::string, int>, std::string> kPeopleMaps) {
  for (const auto& person : kPeopleMaps) {
    bool possible = true;
    for (const auto& person_str : person.first) {
      for (const auto& str_pair : kStrCount) {
        if (str_pair.first == person_str.first) {
          if (str_pair.second != person_str.second) {
            possible = false;
          }
        }
      }
    }
    if (possible) {
      return person.second;
    }
  }
  return "No match";
}

std::string FinalAnswer(std::vector<std::string> matches) {
  std::string output = " ";
  for (size_t i = 1; i < matches.size(); ++i) {
    if (matches.at(i) != matches.at(0)) {
      output = "No match";
    }
  }
  if (output != "No match") {
    output = matches.at(0);
  }
  return output;
}
