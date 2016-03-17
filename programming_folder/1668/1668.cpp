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

void deducting_process(vector<int>* path, vector< vector <int>* >* V, int min_bicycle) {
	int path_size = path->size();
	for (int start=0; start<path_size-1; start++) {
		V[start][start+1] -= min_bicycle;
	}
}

void find_path_helper(int number_of_cities, vector< vector <int>* >* E, vector< vector <int>* >* V, vector <int>& second_path, int last, int count, int min_bicycle) {

}


int find_longest_path(int number_of_cities, vector< vector <int>* >* E, vector< vector <int>* >* V, vector <int>* path) {
	vector <int> longest_path;
	vector <int>  second_path;
	int max = 0;
	int min_bicycle = -1;


	for (int i = 0; i<number_of_cities; i++) {
		int last = i;
		second_path.clear();

		for (int j = 0; j<number_of_cities; j++) {
			int count = 0;
			if (j != last && E[i][j] > 0 && V[i][j] > 0) {
				count += 1;
				last = j;
				min_bicycle = V[i][j];
				second_path.push_back(i);
				second_path.push_back(j);
				count = find_path_helper(number_of_cities, E, V, second_path, last, count, min_bicycle);

				if (count > max) {
					longest_path = second_path; //Shallow copy
				}
			}
		}
	}

	path = &longest_path;

	return min_bicycle;
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
			vector<int>* path = new vector<int>*();
			int min_bicycle = find_longest_path(number_of_cities, E, V, path);

			if (path->size() > 1 /* check later */) {
				deducting_process(path, V, min_bicycle);
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