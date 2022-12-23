#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "utilities.hpp"

int CountStrs(std::string to_analyze, std::string str);

std::string Compare(
    std::map<std::string, int> kStrCount,
    std::map<std::map<std::string, int>, std::string> kPeopleMaps);

std::string FinalAnswer(std::vector<std::string> matches);
#endif