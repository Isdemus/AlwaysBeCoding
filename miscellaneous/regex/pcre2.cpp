#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>

#define PCRE2_CODE_UNIT_WIDTH 8
#include "pcre2.h"
using namespace std;

int main(int argc, char* argv[]) {
  pcre2_code *re;
  pcre2_match_data *match_data;

  PCRE2_SIZE erroffset, *ovector;
  int errorcode;
  int rc;

  std::string pattern2 = "공일일(이|삼|사|오|육|칠|팔|구|십)";
//  pattern2 = "\\d+";
  std::string value2 = "abc0cba0";
  const char* pattern = pattern2.c_str();
  const char* value = value2.c_str();

  re = pcre2_compile((PCRE2_SPTR)pattern, -1, PCRE2_UTF, &errorcode, &erroffset, NULL);
  if (re == NULL) {
    PCRE2_UCHAR8 buffer[120];
    (void)pcre2_get_error_message(errorcode, buffer, 120);
    /* Handle error */
    return 0;
  }
  std::string line;

  while (getline(cin, line)) {
  value = line.c_str();

  match_data = pcre2_match_data_create(20, NULL);
  rc = pcre2_match(re, (PCRE2_SPTR)value, -1, 0, 0, match_data, NULL);
  if (rc <= 0)
    printf("No matchx\n");
  else {
    ovector = pcre2_get_ovector_pointer(match_data);
    printf( "Match succeeded at offset %zu\n", ovector[0] );
    /* Use ovector to get matched strings */
/*    PCRE2_SIZE i;

    for(i = 0; i < rc; i++) {
      PCRE2_SPTR start = value + ovector[2*i];
      PCRE2_SIZE slen = ovector[2*i+1] - ovector[2*i];
//      printf( "%2d: %.*s\n", i, (int)slen, (char *)start );
      break;
    }
*/
  }
  }
  pcre2_match_data_free(match_data);
  pcre2_code_free(re);

  return 0;
}
