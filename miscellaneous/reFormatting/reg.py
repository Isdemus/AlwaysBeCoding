import re
import os

if __name__ == "__main__":
  fileList = open("list.txt", "r");

  for file_ in fileList:
    fileToRead = open(file_[:-1], "r");
    content = fileToRead.readlines();
    fileToRead.close();

    for line in content:
      doc_date = re.match(r'.*"doc_date":"([0-9]+)".*', line, re.M|re.I);
      print(doc_date.group(1));
      doc_dt = doc_date.group(1);

      newContent = re.sub(r'"doc_date":"[0-9]+"', '"doc_date":' + doc_dt, line);
      fileToWrite = open("./new/" + file_[2:-1], "a");
      fileToWrite.write(newContent);
      fileToWrite.close();


