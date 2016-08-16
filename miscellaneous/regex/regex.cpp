#include <iostream>
#include <regex>
#include <vector>
#include <memory>

using namespace std;

int main(int argc, char* argv[]) {
  auto ptr1 = unique_ptr<vector<string>>(new vector<string>());
  auto ptr2 = unique_ptr<vector<string>>(new vector<string>());
//  std::regex music_regex3("play\\s+((some|any)\\s+)*(.+)(music|song)[a-z]*"); 
//  std::regex music_regex4(".*(let me listen to|play)\\s+(.+)\\s((music|song)\\s)*(played|sang|sung\\s)*by\\s+(.+)", std::regex::ECMAScript|std::regex::icase);

  std::regex music_regex3("play[:space:]+((some|any)[:space:]+)*(.+)(music|song)[a-z]*"); 
  std::regex music_regex4(".*(let me listen to|play)[:space:]+(.+)[:space:]((music|song)[:space:])*(played|sang|sung[:space:])*by[:space:]+(.+)", std::regex::ECMAScript|std::regex::icase);


  std::regex musicRegex1("play\\s+((some|any)\\s+)*(.+)(music|song)[a-z]*", std::regex::ECMAScript|std::regex::icase); 


  std::vector<std::regex> reg;
  reg.push_back(music_regex3);
  reg.push_back(music_regex4);
  
  std::smatch base_match;

  std::string test = "play Adele's Chasing";
//  test = "play music";
  test = "play some hip hop music";

  while (getline(cin, test)) {
    for (std::regex regexp : reg) {
      if (std::regex_match(test, base_match, regexp)) {;
        for (size_t i = 0; i < base_match.size(); ++i) {
          std::ssub_match sub_match = base_match[i];
          std::string piece = sub_match.str();
          std::cout << "  submatch " << i << ": " << piece << '\n';
        }     
      } else {
        cout << "cannot catch the sentence" << endl;
      }
    }
  }

  return 0;
}
