#creating folders

import sys
import os
import errno

def createNewFolderWithoutName(alphabetList, folderNameList):
    for folderName in folderNameList:
        createNewFolderWithName(alphabetList[folderNameList.index(folderName)] + ". " + folderName)

    print ("Done")

def createNewFolderWithName(newFolderName):
    try:
        os.makedirs(newFolderName)
    except OSError as exception:
        if exception.errno != errno.EEXIST:
            raise

def main(mode):
    terminated = False
    while not terminated:
        if mode=="Y":
            alphabetList = list("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
            folderNameList = []
            print("How many folders do you want to create today?")
            howManyFolders = int(sys.stdin.readline())
            
            print("Please enter the names of new folders to create")

            while howManyFolders > 0:
                howManyFolders -= 1
                folderNameList.append(input())
                    
            #alphabetList = alphabetList[0:alphabetList.index(stoppingAlphabet)]
            print (alphabetList)
            print (folderNameList)
            createNewFolderWithoutName(alphabetList, folderNameList)
        else:
            newFolderName = input("Please enter a new folder name\n")
            createNewFolderWithName(newFolderName)

        if input("Do you want to terminate the program? (Y/N)\n") == "Y":
            terminated = True
        elif input("Automatic folder creating tool (Y/N)\n") == "Y":
            mode = "Y"
        else:
            mode = "N"


if __name__ == "__main__":
    main(input("Automatic folder creating tool (Y/N)\n"))    

