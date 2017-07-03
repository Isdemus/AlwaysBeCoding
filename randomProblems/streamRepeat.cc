#include <iostream>
#include <list>
#include <unordered_map>

#define FIRST 1

using namespace std;

typedef struct Entry {
	int freq;
	int value;
	bool in; // int can be better for memory alignment

	Entry(int val) : freq(FIRST), value(val), in(false) {}
} Entry;


void InsertToWindow(Entry *entry, list<Entry *> &window)
{
	auto it = window.begin();
	for (it; it != window.end(); it++) {
		Entry *entry_in = *it;

		if (entry_in->freq >= entry->freq) {
			if (entry_in->freq > entry->freq) continue;
			else if (entry_in->value < entry->value) continue;
		}

		break;
	}

	window.insert(it, entry);
}

void PrintTheWindow(list<Entry *> &window)
{
	for (Entry *ent : window) {
		cout << ent->value << " ";
	}
}

int main(int argc, char *argv[])
{
	int cases, input_size, window_size, input;
	cin >> cases;
	
	for (int c = 1; c <= cases; c++) {
		cin >> input_size >> window_size;

		int curr_size = int();
		int min_freq  = int();

		// Table: input(int) -> freq(int)
		list<Entry *>         window;
		unordered_map<int, Entry *> table;

		for (int num = 0; num < input_size; num++) {
			cin >> input;

			// Record first
			Entry *entry = table[input];
			if (entry == nullptr) {
				Entry *new_entry = new Entry(input);
				table[input] = new_entry;
				entry = new_entry;
			} else {
				entry->freq += 1;
			}

			if (entry->in) {
				// Check the order of the window
				auto it_begin = window.begin();
				auto it_end   = window.end();
				for (it_begin; it_begin != it_end; it_begin++) {
					if ((*it_begin)->value == input) break;
				}

				window.erase(it_begin);
				InsertToWindow(entry, window);
			} else if ((entry->freq >= min_freq) && (curr_size >= window_size)) { // Replace one element in the window
				InsertToWindow(entry, window);
				entry->in = true;
				window.back()->in = false;
				window.pop_back();
			} else if (entry->freq >= min_freq) { // Adding into the window
				InsertToWindow(entry, window);
				entry->in = true;
				curr_size += 1;
			}

			// Update the min_freq
			min_freq = window.back()->freq;
			PrintTheWindow(window);
		}
		cout << endl;

		while (!window.empty()) {
			window.pop_front();
		}

		for (auto table_entry : table) {
			free(table_entry.second);
			table[table_entry.first] = nullptr;
		}
	}

	return 0;
}
