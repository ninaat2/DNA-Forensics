#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "functions.hpp"
#include "utilities.hpp"

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " [input_file] [dna_sequence]"
              << std::endl;
    return 1;
  }
  std::ifstream ifs{argv[1]};
  std::map<std::string, int> str_count;
  std::map<std::map<std::string, int>, std::string> people_maps;
  std::string to_analyze = argv[2];
  bool first_done = false;
  for (std::string line; std::getline(ifs, line); line = "") {
    if (!first_done) {
      std::vector<std::string> first_line = utilities::GetSubstrs(line, ',');
      for (unsigned int i = 1; i < first_line.size(); ++i) {
        str_count.insert(std::pair<std::string, int>(first_line.at(i), i));
      }
      first_done = true;
    } else {
      std::vector<std::string> this_line = utilities::GetSubstrs(line, ',');
      std::string name = this_line.at(0);
      std::map<std::string, int> person_map;
      for (auto& pair : str_count) {
        person_map.insert(std::pair<std::string, int>(
            pair.first, std::stoi(this_line.at(pair.second))));
      }
      people_maps.insert({person_map, name});
    }
  }
  for (auto& pair : str_count) {
    pair.second = 0;
    pair.second = CountStrs(to_analyze, pair.first);
  }
  std::vector<std::string> matches;
  matches.push_back(Compare(str_count, people_maps));
  std::string output = FinalAnswer(matches);
  std::cout << output << std::endl;
  return 0;
}