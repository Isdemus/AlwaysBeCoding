import os
import sys

def combining(objects):
  for object in objects:
    realName = object[2:object.rfind("_")];
    print(realName);
    fileToRead = open(object[:-1], "r");
    objectLines = fileToRead.read();
    objectLines = objectLines.replace('"comment_num": "0"', '"comment_num": 0').replace('\/', '/').replace("\n", "").replace("    ", "").replace(": ", ":");

    fileToWrite = open("./final/" + realName + ".json", "a");
    fileToWrite.write(objectLines + "\n");

    fileToRead.close();
    fileToWrite.flush();
    fileToWrite.close();
  

if __name__ == "__main__":
  fileList = open("list.txt", "r");
  objects = fileList.readlines();
  fileList.close();
  os.system("mkdir final");

  combining(objects);
