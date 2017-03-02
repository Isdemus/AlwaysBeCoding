#include <iostream>
#include <stack>

#define ARRSIZE(arr) (sizeof(arr) / sizeof(*arr))

enum Kind {OPENING, CLOSING, THEREST};

Kind CharKind(char ch)
{
	switch(ch) {
		case '[':
		case '{':
		case '(':
		case '<':
			return Kind::OPENING;
		case ']':
		case '}':
		case ')':
		case '>':
			return Kind::CLOSING;
		default:
			return Kind::THEREST;
	}
}

bool CheckParentheses(const std::string &str)
{
	std::stack<char> opened_breakets;

	for (char ch : str) {
		if (CharKind(ch) == Kind::OPENING) {
			opened_breakets.push(ch);
		} else if (CharKind(ch) == Kind::CLOSING) {
			if (opened_breakets.empty()) {
				return false;
			}
			// Get an open breaket opened the most recently
			char opened_breaket = opened_breakets.top();
			opened_breakets.pop();

			if ((ch == ')') && (opened_breaket != '(')) {
				return false;
			} else if (opened_breaket - ch == 2) {
				return false;
			}
		}
	}
	return true;
}

void CheckAndPrintResult(const std::string &str)
{
	std::string result = "False";
	result = (CheckParentheses(str) ? "True" : result);
	std::cout << "Given string : " << ((str != "") ? str : "[empty string]")
	          << " and result : "  << result
	          << std::endl;
}

int main(int argc, char *argv[])
{
	std::string given_strings[] = {"AbC[{(<dE>f)}G]", "AbC{(<dE>f)}G]", "abCdE", ""};

	for (int index = 0; index < ARRSIZE(given_strings); index++) {
		CheckAndPrintResult(given_strings[index]);
	}

	return 0;
}
