#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include <pcre.h>
#include <pcrecpp.h>

typedef unsigned int ui;

using namespace std;

int main(int argc, char* argv[]) {

  std::string s;

  std::string namerule = "(\\s|^)((?:(가|간|갈|감|강|개|견|경|계|고|곡|공|곽|교|구|국|군|궁|궉|권|근|금|기|길|김|나|라|남|(?:남궁)|낭|랑|내|노|로|뇌|누|단|담|당|대|도|(?:독고)|돈|동|(?:동방)|두|라|류|마|만|망절|매|맹|명|모|묘|목|묵|문|미|민|박|반|방|배|백|범|변|복|봉|부|빈|빙|사|(?:사공)|삼|상|서|(?:서문)|석|선|(?:선우)|설|섭|성|소|(?:소봉)|손|송|수|순|숭|시|신|심|십|아|안|애|야|양|량|어|(:?어금)|엄|여|연|염|영|예|오|옥|온|옹|왕|요|용|우|운|원|위|유|육|윤|은|음|이|인|임|림|자|장|전|점|정|제|(?:제갈)|조|종|좌|주|준|즙|지|진|차|창|채|척|천|초|최|추|축|춘|탁|탄|태|판|팿|편|평|포|표|퐁|피|필|하|학|한|함|해|허|현|형|호|홍|화|환|황|(?:황보))\\s?[(가-힣)](\\s?[(가-힣)])))((?:이요)|(?:입니다)|\\s|요)";

  if (atoi(argv[1]) == 0) {
    ifstream filetoread (argv[2], ios::in);

    while (getline(filetoread, s)) {
      cout << "original s : " << s << endl;

      // Naming 
      //pcrecpp::RE(namerule, PCRE_UTF8).GlobalReplace("1: \\1 -- 2: \\2 -- 3: \\3 -- 5: \\5 -- 6: \\6", &s);
      pcrecpp::RE(namerule, PCRE_UTF8).GlobalReplace("\\3*\\5 \\6", &s);

      // Trimming
      pcrecpp::RE("\\s{2,}", PCRE_UTF8).GlobalReplace(" ", &s);
      cout << "new s : " << s << endl;
    }

    filetoread.close();
  } else {
    while (getline(std::cin, s)) {
      cout << "original s : " << s << endl;

      // Naming 
      //pcrecpp::RE(namerule, PCRE_UTF8).GlobalReplace("1: \\1 -- 2: \\2 -- 3: \\3 -- 5: \\5 -- 6: \\6", &s);
      pcrecpp::RE(namerule, PCRE_UTF8).GlobalReplace("\\3*\\5 \\6", &s);

      // Trimming
      pcrecpp::RE("\\s{2,}", PCRE_UTF8).GlobalReplace(" ", &s);
      cout << "new s : " << s << endl;
    }
  }

  return 0;
}
