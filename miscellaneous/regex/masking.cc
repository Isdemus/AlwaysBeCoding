#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <exception>
#include <vector>

#include <pcrecpp.h>

#define Maxapply 3
#define VectorSize 10000

typedef enum State {
	notension,
	birth,
	phone,
	email,
	address,
	name,
	general
} Standby;

bool StrContains(const std::string &sent, const std::string &keyword) {
	size_t found = sent.find(keyword);

	if (found != std::string::npos) {
		return true;
	}

	return false;
}

int main(int argc, char* argv[]) {
	if (argc < 4) {
		std::cerr << "Usage : ./progName sourcePath fileFormat encoding" << std::endl;
		std::cerr << "e.g., ./progName ../stt_result result utf-8" << std::endl;

		exit(1);
	}

	std::string directory, format, encoding, list;
	directory = argv[1];
	format = argv[2];
	encoding = argv[3];
	list = directory + "/list.txt";
	std::vector<string> failedfiles, succfiles;
	succfiles.reserve(VectorSize);

	// Making a list
	std::string cmd = "rm -rf " + list + "; for file in " + directory + "/*." + format +
	 "; do echo ${file##*/} >> " + list + "; done";
	try {
		system(cmd.c_str());
	} catch (std::exception &ex) {
		std::cerr << "Can not make the list.txt file! -- quitting" << std::endl;
		exit(1);
	}

	std::ifstream listfile (list, std::ios::in);
	if (!listfile.good()) {
		std::cerr << "Can not open the list.txt file -- please check if the file exists" << std::endl;
		exit(1);
	}

	std::string filename, sent, newsent;
	std::string generalrule, birthrule, emailrule, addressrule, namerule, phonerule;

	std::string mkdircommand = "mkdir -p tmp_convert_folder";

	try {
		system(mkdircommand.c_str());
	} catch (std::exception &ex) {
		std::cerr << "Can not make the directory! -- quitting" << std::endl;
		exit(1);
	}

	if (std::strncmp(encoding.c_str(), "utf-8", 5) && std::strncmp(encoding.c_str(), "UTF-8", 5)) {
		// converting the documents to be UTF-8 format

		std::cout << "Converting to UTF-8 format! Please wait" << std::endl;
		while (getline(listfile, filename)) {
			std::string command = "iconv -c -f euc-kr -t utf-8 " + directory + "/" + filename + " >> tmp_convert_folder" + filename;
			try {
				system(command.c_str());
			} catch (std::exception &ex) {
				std::cerr << "Can not convert the file! -- quitting" << std::endl;
				exit(1);
			}
		}
	} else {
		std::string copycommand = "cp " + directory + "/*." + format + " tmp_convert_folder";
		
		try {
			system(copycommand.c_str());
		} catch (std::exception &ex) {
			std::cerr << "Can not copy the original files! -- quitting" << std::endl;
			exit(1);
		}
	}

	generalrule = "(((일|(?:하나)|이|둘|삼|사|오|육|륙|칠|팔|구|공|넷|빵|영)\\s?)([^일|^(?:하나)|^이|^둘|^삼|^사|^오|^육|^륙|^칠|^팔|^구|^공|^넷|^빵|^영])*\\s?){3,}";
	emailrule = "(.\\s?){4}((?:골\\s?뱅\\s?이)|엣|에|앳|애)(.+)((?:닷\\s?컴)|(?:다\\s?컴)|(?:닷\\s?넷)|(?:닷\\s?씨\\s?오\\s?점\\s?케\\s?이\\s?오\\s?알\\s?)|(?:다\\s?씨\\s?오\\s?점\\s?케\\s?이\\s?오\\s?알)|(?:메일))";
	addressrule = "(.+[시|도])(.+(시|군|구))*(.+(읍|면))?(.+(로|동|층|호|번|지|(?:번지)))*";
	namerule = "(\\s|^)((?:(가|간|갈|감|강|개|견|경|계|고|곡|공|곽|교|구|국|군|궁|궉|권|근|금|기|길|김|나|라|남|(?:남궁)|낭|랑|내|노|로|뇌|누|단|담|당|대|도|(?:독고)|돈|동|(?:동방)|두|라|류|마|만|망절|매|맹|명|모|묘|목|묵|문|미|민|박|반|방|배|백|범|변|복|봉|부|빈|빙|사|(?:사공)|삼|상|서|(?:서문)|석|선|(?:선우)|설|섭|성|소|(?:소봉)|손|송|수|순|숭|시|신|심|십|아|안|애|야|양|량|어|(:?어금)|엄|여|연|염|영|예|오|옥|온|옹|왕|요|용|우|운|원|위|유|육|윤|은|음|이|인|임|림|자|장|전|점|정|제|(?:제갈)|조|종|좌|주|준|즙|지|진|차|창|채|척|천|초|최|추|축|춘|탁|탄|태|판|팿|편|평|포|표|퐁|피|필|하|학|한|함|해|허|현|형|호|홍|화|환|황|(?:황보))\\s?[(가-힣)](\\s?[(가-힣)])))((?:이\\s?요)|(?:입\\s?니\\s?다)|요|(?:였\\s?습\\s?니\\s?다)|(?:엿\\s?습\\s?니\\s?다))";
	phonerule = "((?:공\\s?이)|(?:공\\s?오\\s?일)|(?:공\\s?오\\s?삼)|(?:공\\s?삼\\s?이)|(?:공\\s?육\\s?이)|(?:공\\s?륙\\s?이)|(?:공\\s?사\\s?이)|(?:공\\s?오\\s?이)|(?:공\\s?사\\s?사)|(?:공\\s?삼\\s?일)|(?:공\\s?삼\\s?삼)|(?:공\\s?사\\s?삼)|(?:공\\s?사\\s?일)|(?:공\\s?육\\s?삼)|(?:공\\s?륙\\s?삼)|(?:공\\s?육\\s?일)|(?:공\\s?륙\\s?일)|(?:공\\s?오\\s?사)|(?:공\\s?오\\s?오)|(?:공\\s?육\\s?사)|(?:공\\s?륙\\s?삼)|(?:공\\s?일\\s?공)|(?:공\\s?일\\s?일)|(?:공\\s?일\\s?이)|(?:공\\s?일\\s?육)|(?:공\\s?일\\s?륙)|(?:공\\s?일\\s?칠)|(?:공\\s?일\\s?팔)|(?:공\\s?일\\s?구))?(.+)?(\\s?(일|(?:(일|(?:하나)|둘|이|삼|사|오|육|륙|칠|팔|공|넷|구|빵|영)\\s?이)|(?:이\\s?(일|(?:하나)|둘|이|삼|사|오|육|륙|칠|팔|공|넷|구|빵|영))|(?:(일|(?:하나)|둘|이|삼|사|오|육|륙|칠|팔|공|넷|구|빵|영)\\s?이\\s?(일|(?:하나)|둘|이|삼|사|오|육|륙|칠|팔|공|넷|구|빵|영))|삼|사|오|육|륙|칠|팔|공|넷|구|빵|영)){3,4}에?(.+)?(\\s?(일|(?:하나)|(?:(일|(?:하나)|이|둘|삼|사|오|육|륙|칠|팔|공|넷|구|빵|영)\\s?이)|(?:이\\s?(일|(?:하나)|둘|이|삼|사|오|육|륙|칠|팔|공|넷|구|빵|영))|(?:(일|(?:하나)|둘|이|삼|사|오|육|륙|칠|팔|공|넷|구|빵|영)\\s?이\\s?(일|(?:하나)|둘|이|삼|사|오|육|륙|칠|팔|공|넷|구|빵|영))|삼|사|오|육|륙|칠|팔|공|넷|구|빵|영)){3,4}";
	birthrule = "(((?:이\\s?천)|천)?([^일|^(?:하나)|^이|^둘|^삼|^사|^오|^육|^륙|^칠|^팔|^구|^공|^영|^넷|^빵|^천]*)([(?:하나)|일|이|둘|삼|사|오|육|륙|칠|팔|구|공|넷|빵|영)\\s?백)?([^일|^(?:하나)|^이|^둘|^삼|^사|^오|^육|^륙|^칠|^팔|^구|^공|^넷|^빵|^천|^공]*)((일|(?:하나)|이|둘|삼|사|오|육|륙|칠|팔|구|공|넷|빵|영)\\s?십)?([^일|^(?:하나)|^둘|^삼|^사|^오|^육|^륙|^칠|^팔|^구|^공|^넷|^빵|^천|^백|^영]*)(일|(?:하나)|이|둘|삼|사|오|육|륙|칠|팔|구|공|넷|빵|영)\\s?년([^일|^(?:하나)|^이|^둘|^삼|^사|^오|^육|^륙|^칠|^팔|^구|^공|^넷|^빵|^천|^백|^영]*)(십?(일|(?:하나)|이|둘|삼|사|오|육|륙|칠|팔|구|공|넷|빵|영)\\s?월)?([^일|^(?:하나)|^이|^둘|^삼|^사|^오|^육|^륙|^칠|^팔|^구|^공|^넷|^빵|^천|^백|^영]*)((?:(일|(?:하나)|이|둘|삼|사|오|육|륙|칠|팔|구|공|넷|빵|영)십)?(일|(?:하나)|이|둘|삼|사|오|육|륙|칠|팔|구|공|넷|빵|영)\\s?일)?|(\\s?([^일|^(?:하나)|^이|^둘|^삼|^사|^오|^육|^륙|^칠|^팔|^구|^공|^넷|^빵|^천|^영])*(일|(?:하나)|이|둘|삼|사|오|육|륙|칠|팔|구|공|넷|빵|영)([^일|^(?:하나)|^이|^둘|^삼|^사|^오|^육|^륙|^칠|^팔|^구|^공|^넷|^빵|^천|^영])*){6,7})";

	std::ofstream changelog ("log.txt", std::ios::app);
	while (getline(listfile, filename)) {
		std::ifstream filetoapply ("tmp_convert_folder/" + filename, std::ios::in);
		std::ofstream filetowrite ("tmp_convert_folder/new_" + filename, std::ios::app);

		if (!changelog.good()) {
			std::cerr << "Can not open the file with the name : " << filename << std::endl;
			exit(1);
		}

		if (!filetoapply.good() || !filetowrite.good()) {
			std::cerr << "Can not open the file with the name : " << filename << std::endl;
			failedfiles.push_back(filename);
			
			continue;
		}
		
		Standby ready = notension;
		unsigned int sentcount = 0, sentappliedcount = 0;

		while (getline(filetoapply, sent)) {
			sentcount += 1;

			// Apply name rule
			if (sentcount == 1 || sentcount == 2 || StrContains(sent, "이름") || StrContains(sent, "성함")) {
 				ready = name;
 				sentappliedcount = 0;
			} else if (StrContains(sent, "생년월일") || StrContains(sent, "주민등록")) {
				ready = birth;
				sentappliedcount = 0;
			} else if (StrContains(sent, "번호")) {
				ready = phone;
				sentappliedcount = 0;
			} else if (StrContains(sent, "이메일")) {
				ready = email;
				sentappliedcount = 0;
			} else if (StrContains(sent, "주소")) {
				ready = address;
				sentappliedcount = 0;
			} else if (StrContains(sent, "카드") || StrContains(sent, "계좌") || StrContains(sent, "통장") || StrContains(sent, "유효") || StrContains(sent, "기간")) {
				ready = general;
				sentappliedcount = 0;
			}

			switch(ready) {
				case birth:
					changelog << "[birth]original : " + sent + "\n";
					pcrecpp::RE(phonerule, PCRE_UTF8).GlobalReplace("**년 **월 **일 \\3 \\7 \\8 \\(12) ", &sent);
					pcrecpp::RE(generalrule, PCRE_UTF8).GlobalReplace("**** \\1", &sent);
					sentappliedcount += 1;
					changelog << "[birth]new : " + sent + "\n";
					break;
				case phone:
					changelog << "[phone]original : " + sent + "\n";
					pcrecpp::RE(phonerule, PCRE_UTF8).GlobalReplace("\\2 \\5", &sent);
					pcrecpp::RE(generalrule, PCRE_UTF8).GlobalReplace("**** \\1", &sent);
					sentappliedcount += 1;
					changelog << "[phone]new : " + sent + "\n";
					break;
				case email:
					changelog << "[email]original : " + sent + "\n";
					pcrecpp::RE(emailrule, PCRE_UTF8).GlobalReplace("**** \\2 *** \\4", &sent);
					pcrecpp::RE(generalrule, PCRE_UTF8).GlobalReplace("**** \\1", &sent);
					sentappliedcount += 1;
					changelog << "[email]new : " + sent + "\n";
					break;
				case address:
					changelog << "[address]original : " + sent + "\n";
					pcrecpp::RE(addressrule, PCRE_UTF8).GlobalReplace("\\1 **\\3 **\\7 ", &sent);
					pcrecpp::RE(generalrule, PCRE_UTF8).GlobalReplace("**** \\1", &sent);
					sentappliedcount += 1;
					changelog << "[address]new : " + sent + "\n";
					break;
				case name:
					changelog << "[name]original : " + sent + "\n";
					pcrecpp::RE(namerule, PCRE_UTF8).GlobalReplace(" \\3*\\5 \\6", &sent);
					sentappliedcount += 1;
					changelog << "[name]new : " + sent + "\n";
					break;
				case general:
					changelog << "[general]original : " + sent + "\n";
					pcrecpp::RE(generalrule, PCRE_UTF8).GlobalReplace("**** \\1", &sent);
					sentappliedcount += 1;
					changelog << "[general]new : " + sent + "\n";
					break;
				default:
					break;
			}

			if (sentcount == 1 || sentappliedcount >= Maxapply) {
				ready = notension;
				sentappliedcount = 0;
			}

			pcrecpp::RE("\\s{2,}", PCRE_UTF8).GlobalReplace(" ", &sent);

			filetowrite << sent + "\n";
			filetowrite.flush();
			changelog.flush();
		}

		succfiles.push_back(filename);
		filetoapply.close();
		filetowrite.close();
	}

	// Converting back
	for (std::string filename : succfiles) {
		std::string convertcommand = "iconv -c -f utf-8 -t euc-kr tmp_convert_folder/new_" + filename + " > " + directory + "/" + filename;

		try {
			system(convertcommand.c_str());
		} catch (std::exception &ex) {
			std::cerr << "cannot convert the files back to euc-kr -- quitting" << std::endl;
			exit(1);
		}
	}

	try {
			std::string removecommand = "rm -rf tmp_convert_folder; rm -rf " + list;
			system(removecommand.c_str());
		} catch (std::exception &ex) {
			std::cerr << "cannot remove the tmp_convert_folder -- quitting" << std::endl;
	}

	for (std::string filename : failedfiles) {
		std::cout << "[ERROR]Failed filename : " << filename << std::endl;
	}

	changelog.close();
	listfile.close();

	return 0;
}