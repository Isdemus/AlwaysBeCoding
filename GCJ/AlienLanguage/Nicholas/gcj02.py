# Google Code Jam Entrance Test 
# (Alien Language: https://code.google.com/codejam/contest/90101/dashboard)

# Used Algorithm Method: Knowledge of vector, hashmap, and string parsing
# Coded by isdemus (May 09 2016)

import sys

# main function definition: it inserts words and possble dictionaries to calculate possible interpretations
def main(wordLength, wordSize, possibleDictionary):
    words = []; 
    for number in range(1, int(wordSize)+1):
	words.append(raw_input());

    for number in range(1, int(possibleDictionary)+1):
	dict = raw_input();
	dict_list = [];
	dictLetterPosition = 0;
	inProgress = False;
	for dict_letter in dict:
		if dict_letter == '(':
			inProgress = True;
			dict_list.append([]);
			pass;
		elif dict_letter == ')':
			inProgress = False;
			dictLetterPosition += 1;
		elif inProgress:
			dict_list[dictLetterPosition].append(dict_letter);
		else:
			dict_list.append(list(dict_letter));
			dictLetterPosition += 1;

	#dict_arr = dict.split(')');

	possibleCases = 0;
	#for number in range(0, len(dict_arr)):
	#	print(dict_arr[number]); 
	#	dict_arr[number] = list(dict_arr[number]);
	#print("dict_arr: ", dict_arr);
	for wordIndex in range(0, len(words)):
		word = words[wordIndex];
		for letterIndex in range(0, len(word)):
			if word[letterIndex] not in dict_list[letterIndex]:
				break;
			elif letterIndex == len(words[wordIndex])-1:
				possibleCases += 1;
	print("Case #number: %d" % possibleCases);	


if __name__ == "__main__":
    input = raw_input();
    indicator = 0;
    wordLength = wordSIze = possibleDictionary = 0;

    # why didn't I use split method?
    # parsing the given input
    for character in input:
        if character != ' ' and indicator == 0:
            wordLength = character;
        elif character != ' ' and indicator == 1:
            wordSize = character;
        elif character != ' ':
            possibleDictionary = character;
        else:
            indicator -= 1;
	indicator += 1;

    main(wordLength, wordSize, possibleDictionary);
