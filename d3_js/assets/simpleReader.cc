#include <fstream>
#include <exception>

#define open(fileName) if (fileName.is_open())
#define fa(a) for (int i=0; i<a; i++)
#define fi(a, b) for (a; a<b; a++)
using namespace std;

int main (int argc, char* argv[]) {
	int number;
	string name = "lottoNumbers.txt";
	string name2 = "lottoNumbers2.txt";
	ifstream fileToRead (name, ios::in);
	ofstream fileToWrite (name2, ios::app);

	open(fileToRead) {
		fa(691) {
			int index = 0;
			fileToWrite << "[";
			fi(index, 6) {
				fileToRead >> number;
				fileToWrite << number;
				if (index < 5)
					fileToWrite << ", ";
				else
					fileToWrite << "]\n";
			}
			fileToWrite.flush();
		}
	}else {
		throw("An error has been occured to read a file");
	}
	fileToRead.close();
	fileToWrite.close();

	return 0;
}


