# Google Code Jam Entrance Test 
# (Alien Language: https://code.google.com/codejam/contest/90101/dashboard)

# Used Algorithm Method: Knowledge of vector, hashmap, and string parsing
# Coded by isdemus (May 09 2016)

import sys

def main(wordLength, wordSize, possibleDictionary):
    print("wordLength: " + wordLength + " wordSize: " + wordSize + " possibleDictionary: " + possibleDictionary);

    

if __name__ == "__main__":
    raw_input = input();
    indicator = 0;
    wordLength = wordSIze = possibleDictionary = 0;

    # parsing the given input
    for character in raw_input:
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
