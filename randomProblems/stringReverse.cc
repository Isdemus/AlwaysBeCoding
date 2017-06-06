#include <iostream>

void string_reverse1(char *string)
{
	if (string == NULL) { return; }

	const int leng = std::strlen(string);
	for (int index = 0; index < (leng / 2); index++)
	{
		*(string + index)            ^= *(string + leng - 1 - index);
		*(string + leng - 1 - index) ^= *(string + index);
		*(string + index)            ^= *(string + leng - 1 - index);
	}
}

char * string_reverse2(const char *string)
{
	if (string == NULL) { return NULL; }

	const int leng = strlen(string);
	char *new_string = new char[leng + 1];
	for (int index = 0; index < leng; index++)
	{
		new_string[index] = string[leng - 1 - index];
	}

	return new_string;
}

int main(int argc, char *argv[])
{
	char str_1[5] = {'a', 'b', 'c', 'd', '\0'};
	char str_2[6] = {'a', 'b', 'c', 'd', 'e', '\0'};

	std::cout << str_1 << std::endl;
	string_reverse1(&str_1[0]);
	std::cout << str_1 << std::endl;

	std::cout << str_2 << std::endl;
	char *result = string_reverse2(&str_2[0]);
	std::cout << result << std::endl;

	return 0;
}
