#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>

#include <boost/property_tree/json_parser.hpp>

using namespace std;
using boost::property_tree::ptree;

int main(int argc, char* argv[]) {
  std::string line, object;

  time_t current;
  time ( &current );

  ifstream listFile ("list.txt", ios::in);
  if (!listFile.good()) {
    cerr << "list file cannot be openned" << endl;

    return 0;
  }
  
  while (getline(listFile, object)) {
    cout << "processing fileName : " << object << endl;

    ifstream fileToRead (object, ios::in);
    ofstream fileToWrite ("./new/" + object.substr(2, object.length()-1), ios::app);

    if (!fileToRead.good() || !fileToWrite.good()) {
      cerr << "Something went wrong to initiate a file" << endl;

      return 0;
    }

    stringstream ss;
    std::string body, date, crp, rcp, dcm, eleId, offset, len, dtd, url; 
    while (getline(fileToRead, line)) {
      ss << line;
    }

    fileToRead.close();

    ptree pt;
    read_json(ss, pt);
    cout << "read json done" << endl;
    ss.str(std::string());
    ss.clear();

    // Initial URL 
    url = "http://dart.fss.or.kr/report/viewer.do?";

    // Copying "body" -> "content"
    body = pt.get<string>("body");
    crp = pt.get<string>("crp_cd");
    rcp = pt.get<string>("rcpNo");
    dcm = pt.get<string>("dcmNo");
    eleId = pt.get<string>("eleId");
    offset = pt.get<string>("offset");
    len = pt.get<string>("length");
    dtd = pt.get<string>("dtd");

    // Creating the proper URL
    url += "rcpNo=" + rcp;
    url += "&dcmNo=" + dcm;
    url += "&eleId=" + eleId;
    url += "&offset=" + offset;
    url += "&length=" + len;
    url += "&dtd=" + dtd;

    // Converting the doc_date to be in Ctime format
    struct tm* timeSt = localtime(&current);
    timeSt->tm_year = stoi(rcp.substr(0,4)) - 1900;
    timeSt->tm_mon  = stoi(rcp.substr(4,2)) - 1;
    timeSt->tm_mday = stoi(rcp.substr(6,2));
    
    time_t ct = mktime(timeSt);
//    date = to_string(time_t);

    pt.put("url", url);
    pt.put("doc_date", ct);
    pt.put("section", crp);
    pt.put("title", rcp);
    pt.put("content", body);
    pt.put("tag", "");
    pt.put("author", "");
    pt.put("media", "Dart");
    pt.put("comment_num", 0);
    pt.put("comment_url", "");

    pt.erase("crp_cd");
    pt.erase("rcpNo");
    pt.erase("dcmNo");
    pt.erase("eleId");
    pt.erase("offset");
    pt.erase("length");
    pt.erase("dtd");
    pt.erase("body");

    write_json(fileToWrite, pt);
    fileToWrite.flush();
    fileToWrite.close();
  }

  listFile.close();

/*
  if (pt.get<string>("status") == "OK") {
    cout << "success" << endl;
  }

  cout << pt.get<string>("results..geometry.location.lat") << endl;
  cout << pt.get<string>("results..geometry.location.lng") << endl;

  string l = pt.get<string>("results..geometry.location.lat");
  int lat = static_cast<int>(l);
*/

  return 0;
}
