#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>

#include <boost/property_tree/json_parser.hpp>

using namespace std;
using boost::property_tree::ptree;

int main(int argc, char* argv[]) {
  time_t current;
  time ( &current );

  ifstream fileToRead ("test.txt", ios::in);
  if (!fileToRead.good()) {
    cerr << "Something went wrong to open a file to read" << endl;

    return 0;
  }

  stringstream ss;
  std::string line;
  while (getline(fileToRead, line)) {
    ss << line;
  }

  ptree pt;
  read_json(ss, pt);

  if (pt.get<string>("status") == "OK") {
    cout << "success" << endl;
  }

  cout << pt.get<string>("results..geometry.location.lat") << endl;
  cout << pt.get<string>("results..geometry.location.lng") << endl;

  string l = pt.get<string>("results..geometry.location.lat");
  int lat = static_cast<int>(l);

  return 0;
}
