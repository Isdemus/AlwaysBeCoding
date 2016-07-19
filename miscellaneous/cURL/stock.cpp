#include <curl/curl.h>
#include <iostream>
#include <string>
#include <memory>
#include <fstream>

typedef unsigned int ui;

uint TimeWriteCb(char *in, uint size, uint nmemb, void *out) {
  std::string *body = reinterpret_cast<std::string *>(out);
  body->append(std::string(in, size * nmemb));

  return size * nmemb;
}

bool CurlPerform(std::string& body, const std::string& api) {
  CURL *curl;
  char err_buf[CURL_ERROR_SIZE];

  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, api.c_str());
    curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, err_buf);
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, TimeWriteCb);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &body);
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    return false;
  } else {
    return true;
  }
}

int main(int argc, char* argv[]) {
  std::string url, key;
  std::string stockLists[9] = {"005930", "000660", "005380", "015760", "001300", "018260", "090430", "032830", "012330"};
  ui pages[9] = {5, 3, 6, 2, 1, 4, 2, 3, 3};
  curl_global_init(CURL_GLOBAL_DEFAULT);
/*
  key = "4915c05033d0ee063c53aa925081f02b7ae8ace6";

  url = "http://dart.fss.or.kr/api/search.json?auth=";
  url += key;
  url += "&start_dt=20140101";
  url += "&end_dt=20160630";
  url += "&page_set=100";
  for (ui index=0; index<9; index++) {
    std::ofstream fileToWrite (stockLists[index] + ".txt", std::ios::app);
    if (fileToWrite.good()) { 
      for (ui page=1; page<=pages[index]; page++) {
        std::string new_url = url, body;
        new_url += "&page_no=";
        new_url += std::to_string(page);
        new_url += "&crp_cd=";
        new_url += stockLists[index];

        if (!CurlPerform(body, new_url)) {
          fileToWrite << body << std::endl;
          fileToWrite.flush();
        } else {
          std::cerr << "cURL failed to perform" << std::endl;
          return 0;
        }
      }

      fileToWrite.close();
    } else {
      std::cerr << "Cannot open a file with a name : " + stockLists[index] << std::endl;
    }
  }
*/
  std::string body;
  url = "view-source:http://dart.fss.or.kr/dsaf001/main.do?rcpNo=20160714800061";
  if (!CurlPerform(body, url)) {
    std::cout << body << std::endl;
  } else {
    std::cerr << "Something went wrong" << std::endl;
  }

  curl_global_cleanup();

  return 0;
}
