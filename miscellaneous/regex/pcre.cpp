#include <pcre.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  pcre *reCompiled;
  pcre_extra *pcreExtra;
  int pcreExecRet;
  int subStrVec[30];
  const char *pcreErrorStr;
  int pcreErrorOffset;
  char *aStrRegex;
  char **aLineToMatch;
  const char *psubStrMatchStr;
  int j;
/*
  char *testStrings[] = { "This should match... hello. Second sentence is also match hello@abchelloabc",
                          "This could match... hello!",
                          "More than one hello.. hello",
                          "No chance of a match...",
                          NULL};
*/
  char *testStrings[] = { "나는 팔공일 일 공 이요 입니다.",
                          "팔십 일년 해주세요",
                          "구십이 년이 월 이십육일네",
                          "팔 칠 공 오일 칠네",
                          NULL};


  aStrRegex = "(.*)(Hello)+(.*)";
  aStrRegex = "
  printf("Regex to use: %s\n", aStrRegex);

  // First, the regex string must be compiled.
  reCompiled = pcre_compile(aStrRegex, PCRE_UTF8, &pcreErrorStr, &pcreErrorOffset, NULL);

  /* OPTIONS (second argument) (||'ed together) can be:
       PCRE_ANCHORED       -- Like adding ^ at start of pattern.
       PCRE_CASELESS       -- Like m//i
       PCRE_DOLLAR_ENDONLY -- Make $ match end of string regardless of \n's
                              No Perl equivalent.
       PCRE_DOTALL         -- Makes . match newlins too.  Like m//s
       PCRE_EXTENDED       -- Like m//x
       PCRE_EXTRA          -- 
       PCRE_MULTILINE      -- Like m//m
       PCRE_UNGREEDY       -- Set quantifiers to be ungreedy.  Individual quantifiers
                              may be set to be greedy if they are followed by "?".
       PCRE_UTF8           -- Work with UTF8 strings.
  */

  // pcre_compile returns NULL on error, and sets pcreErrorOffset & pcreErrorStr
  if(reCompiled == NULL) {
    printf("ERROR: Could not compile '%s': %s\n", aStrRegex, pcreErrorStr);
    exit(1);
  } /* end if */

  // Optimize the regex
  pcreExtra = pcre_study(reCompiled, 0, &pcreErrorStr);

  /* pcre_study() returns NULL for both errors and when it can not optimize the regex.  The last argument is how one checks for
     errors (it is NULL if everything works, and points to an error string otherwise. */
  if(pcreErrorStr != NULL) {
    printf("ERROR: Could not study '%s': %s\n", aStrRegex, pcreErrorStr);
    exit(1);
  } /* end if */

  for(aLineToMatch=testStrings; *aLineToMatch != NULL; aLineToMatch++) {
    printf("String: %s\n", *aLineToMatch);
    printf("        %s\n", "0123456789012345678901234567890123456789");
    printf("        %s\n", "0         1         2         3");

    /* Try to find the regex in aLineToMatch, and report results. */
    pcreExecRet = pcre_exec(reCompiled,
                            pcreExtra,
                            *aLineToMatch, 
                            strlen(*aLineToMatch),  // length of string
                            0,                      // Start looking at this point
                            PCRE_NOTEOL,                      // OPTIONS
                            subStrVec,
                            30);                    // Length of subStrVec

    /* pcre_exec OPTIONS (||'ed together) can be:
       PCRE_ANCHORED -- can be turned on at this time.
       PCRE_NOTBOL
       PCRE_NOTEOL
       PCRE_NOTEMPTY */

    // Report what happened in the pcre_exec call..
    //printf("pcre_exec return: %d\n", pcreExecRet);
    if(pcreExecRet < 0) { // Something bad happened..
      switch(pcreExecRet) {
      case PCRE_ERROR_NOMATCH      : printf("String did not match the pattern\n");        break;
      case PCRE_ERROR_NULL         : printf("Something was null\n");                      break;
      case PCRE_ERROR_BADOPTION    : printf("A bad option was passed\n");                 break;
      case PCRE_ERROR_BADMAGIC     : printf("Magic number bad (compiled re corrupt?)\n"); break;
      case PCRE_ERROR_UNKNOWN_NODE : printf("Something kooky in the compiled re\n");      break;
      case PCRE_ERROR_NOMEMORY     : printf("Ran out of memory\n");                       break;
      default                      : printf("Unknown error\n");                           break;
      } /* end switch */
    } else {
      printf("Result: We have a match!\n");
        
      // At this point, rc contains the number of substring matches found...
      if(pcreExecRet == 0) {
        printf("But too many substrings were found to fit in subStrVec!\n");
        // Set rc to the max number of substring matches possible.
        pcreExecRet = 30 / 3;
      } /* end if */

      // Do it yourself way to get the first substring match (whole pattern):
      // char subStrMatchStr[1024];
      // int i, j
      // for(j=0,i=subStrVec[0];i<subStrVec[1];i++,j++) 
      //   subStrMatchStr[j] = (*aLineToMatch)[i];
      // subStrMatchStr[subStrVec[1]-subStrVec[0]] = 0;
      //printf("MATCHED SUBSTRING: '%s'\n", subStrMatchStr);
        
      // PCRE contains a handy function to do the above for you:
      for(j=0; j<pcreExecRet; j++) {
        pcre_get_substring(*aLineToMatch, subStrVec, pcreExecRet, j, &(psubStrMatchStr));
        printf("Match(%2d/%2d): (%2d,%2d): '%s'\n", j, pcreExecRet-1, subStrVec[j*2], subStrVec[j*2+1], psubStrMatchStr);
      } /* end for */
        
      // Free up the substring
      pcre_free_substring(psubStrMatchStr);
    }  /* end if/else */
    printf("\n");
      
  } /* end for */
  
  // Free up the regular expression.
  pcre_free(reCompiled);
      
  // Free up the EXTRA PCRE value (may be NULL at this point)
  if(pcreExtra != NULL) {
#ifdef PCRE_CONFIG_JIT
    pcre_free_study(pcreExtra);
#else
    pcre_free(pcreExtra);
#endif
  }

  return 0;
}
