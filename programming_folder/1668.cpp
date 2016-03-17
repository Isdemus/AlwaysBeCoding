#include <iostream>
#include <vector>

using namespace std;

int making_matrices(vector< vector <int>* >* E, vector< vector <int>* >* V) {
	int number_of_cities;
	int first_city, second_city, record;

	cin >> number_of_cities;

	for (int m=1; m<number_of_cities; m++) {
		cin >> first_city - 1;
		cin >> second_city - 1;
		cin >> record;

		E[first_city][second_city] = 1;
		E[second_city][first_city] = 1;
		V[first_city][second_city] = record;
		V[second_city][first_city] = record;
	}

	return number_of_cities;
}

void deducting_process(vector<int>* path, vector< vector <int>* >* E, vector< vector <int>* >* V) {

}



vector <int>* find_longest_path(int number_of_cities, vector< vector <int>* >* E, vector< vector <int>* >* V) {
	vector <int> longest_path;
	vector <int>  second_path;
	int max = 0;

	for (int i = 0; i<number_of_cities; i++) {
		for 
	}

	return &longest_path;
}

int main(int argc, char* argv[]) {

	int number_of_cases;	
	

	cin >> number_of_cases;
	for (int i=0; i<number_of_cases; i++) {
		vector< vector <int>* >* E = new vector< vector <int>* >();
		vector< vector <int>* >* V = new vector< vector <int>* >();
		
		int number_of_cities = making_matrices(E, V);
		int number_of_bicyles = 0;

		do {
			bool finished = false;
			vector<int>* path = find_longest_path(number_of_cities, E, V);

			if (path->size() > 1 /* check later */) {
				deducting_process(path, E, V);
			}else {
				finished = true;
			}
		} while ( !finished );

		cout << "Case #" << i+1 << ": " << number_of_bicyles << endl;

		delete E;
		delete V;
	}

	return 0;
}