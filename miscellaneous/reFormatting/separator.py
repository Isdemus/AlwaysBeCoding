import os
import sys

def separate(files):
  for file_ in files:
    fileName = file_[2:-6];
    print(fileName);
  
    objects = open(file_[:-1], "r");
#   os.system("mkdir ./new/" + fileName);
  
    lines = objects.read();
    objects.close();

    jsonObjects = lines.split('"\n}');
    jsonObjects.pop();

    for index in range(0, len(jsonObjects)):
      object = jsonObjects[index].split('"body" :');
      content = object[1].replace('"', '').replace("'", "").replace("\n", "").replace("\t", "");
      mergedContent = object[0] + '"body" : "' + content + '"\n}';
      mergedContent = mergedContent.replace("\n", "").replace("\t", "").replace("\\", "");
 
      fileToWrite = open("./new/" + "/" + fileName + "_" + str(index) + ".json", "w");
      fileToWrite.write(mergedContent);
      fileToWrite.flush();
      fileToWrite.close();

if __name__ == "__main__":
  fileList = open("list.txt", "r");
  files = fileList.readlines();
  fileList.close();
  os.system("mkdir new");

  separate(files);
