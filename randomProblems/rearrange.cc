#include <unordered_map>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

typedef struct Key {
	int frequency;
	char     character;
	Key(int freq, char ch) : frequency(freq), character(ch) {};

	bool operator < (const struct Key &key) const {
		return frequency < key.frequency;
	}
} Key;

int RearrangeString(string &str)
{
	const int strleng = str.length();
	unordered_map<char, int> freq;
	bool rearrange_required = bool();

	// Pre-processing : Count the number of each letter that appear in str
	for (int index = 0; index < strleng; index++) {
		freq[str[index]] += 1;
		if (freq[str[index]] > strleng - 2) {
			break;
		} else if ((!rearrange_required) && (freq[str[index]] > 1)) {
			if (str[index - 1] == str[index]) {
				rearrange_required = true;
			}
		}
	}

	if (rearrange_required) {
		priority_queue<Key> que;

		unordered_map<char, int>::iterator it = freq.begin();

		// Adding the key (freq, character) into the priority queue
		for (; it != freq.end(); it++) {
			cout << "adding " << it->first << " : " << it->second << endl;
			que.push(Key(it->second, it->first));
		}

		Key prev_used_char = Key(-1, '#');
		int current_str_index = 0;
		cout << prev_used_char.frequency << endl;

		cout << que.size() << endl;
		while (!que.empty()) {
			Key high_freq_letter = que.top();
			que.pop();
			str[current_str_index++] = high_freq_letter.character;
			high_freq_letter.frequency -= 1;

			// Insert the previously used character into the queue
			if (prev_used_char.frequency > 0) {
				que.push(prev_used_char);
			}

			prev_used_char = high_freq_letter;
		}
	}

	return 0; // Returning 0 for a success
}

int main(int argc, char *argv[])
{
	string given_string;
	getline(cin, given_string);

	cout << "Received string : " << given_string << endl;
	if (RearrangeString(given_string)) {
		cout << "Impossible" << endl;
		return 1;
	}

	cout << "New string after rearranging is : " << given_string << endl;

	return 0;
}
