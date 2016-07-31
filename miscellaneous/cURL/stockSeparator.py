import os
import sys

def separate_directory_helper(path):
  newPath = path[0:6] + "_new";
  os.system("mkdir " + newPath);

  data = os.listdir("./stockData/" + path);
  for stockData in data:
      fileToRead = open("./stockData/" + path + "/" + stockData, "r");
      lines = fileToRead.read();
      lines = lines.replace("\n", " ").replace("\t", " ");

      fileToRead.close();

      lines = lines.split("}");
      lines.pop();
      for index in range(0, len(lines)):
        lines[index] = lines[index] + "}";

      fileIndex = 0;
      extIndex = stockData.rfind(".");
      fileExt   = stockData[:extIndex];

      for object in lines:
        newFileName = newPath + "/new_" + stockData[0:extIndex] + "_" +     str(fileIndex) + ".json";

        fileToWrite = open(newFileName, "w");
        fileToWrite.write(object);
        fileToWrite.flush();  
        fileToWrite.close();
        fileIndex += 1;

if __name__ == "__main__":
  files = os.listdir("./stockData");
  
  for index in range(1, len(files)):
    path = files[index];
    separate_directory_helper(path);   
  
