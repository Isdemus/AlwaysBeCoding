#include <iostream>
#include <vector>

using namespace std;

void expanding_matrices(vector<vector <int> > &E, vector<vector <int> > &V, int number_of_cities) {
	for (int i=0; i<number_of_cities; i++) {
		vector<int> vec(number_of_cities,0);
		vector<int> vec2(number_of_cities,0);
		E.push_back(vec);
		V.push_back(vec2);
	}
}

vector<int> making_matrices(vector<vector <int> > &E, vector<vector <int> > &V, int &number_of_cities) {
	int first_city, second_city, record;

	vector<int> number_vector(number_of_cities, 0);

	for (int m=1; m<number_of_cities; m++) {
		cin >> first_city;
		cin >> second_city;
		cin >> record;

		first_city -= 1;
		second_city -= 1;

		number_vector[first_city] += 1;
		number_vector[second_city] += 1;

		E[first_city][second_city] = 1;
		E[second_city][first_city] = 1;
		V[first_city][second_city] = record;
		V[second_city][first_city] = record;
	}

	return number_vector;
}

void deducting_process(vector<int>* path, vector<vector <int> > &V, int min_bicycle) {
	int path_size = path->size();
	for (int start=0; start<path_size-1; start++) {
		V[path->at(start)][path->at(start+1)] -= min_bicycle;
		V[path->at(start+1)][path->at(start)] -= min_bicycle;
	}
}

int find_min(vector<int>* path, vector<vector <int> > &V) {
	int SIZE = path->size();
	int min;
	for (int i=0; i<SIZE-1; i++) {
		int score = V[path->at(i)][path->at(i+1)];
		if (min < 0) { min = score; }
		else if(score < min) {
			min = score;
		}
	}

	return min;
}

void find_path_helper(int number_of_cities, vector<vector <int> > &V, int last, int count, int &max,
						vector<int> &longest_path, vector<int> &current_path, vector<int> &number_vector) {
	for (int i = 0; i < number_of_cities; i++) {
		int count_fake = count;
		int SIZE = current_path.size();
		int current = current_path[SIZE-1];

		if (i == last && number_vector[current] == 1) {
			if (count_fake > max || (count_fake == max && find_min(&longest_path, V) < find_min(&current_path, V))) {
				max = count_fake;
				longest_path = current_path;
				break;
			}
		}else if (i != last && V[current][i] > 0) {
			count_fake += 1;
			last = current;
			current_path.push_back(i);
			find_path_helper(number_of_cities, V, last, count_fake, max, longest_path, current_path, number_vector);
		}
	}
}

bool is_subpath(vector<int> &longest_path, int element) {
	int SIZE = longest_path.size();
	for (int i=0; i<SIZE; i++) {
		if (longest_path[i] == element) {
			return true;
		}
	}

	return false;
}

void show_path(vector<int> longest_path) {
	for (int i=0; i<longest_path.size(); i++) {
		cout << longest_path[i] << " ";
	}
}

void print_matrices(vector<vector <int> > &V, vector<vector <int> > &E, int number_of_cities) {
		cout << "E" << endl;
		for (int i=0; i<number_of_cities; i++) {
			for (int j=0; j<number_of_cities; j++) {
				cout << E[i][j] << "  ";
			}
			cout << endl;
		}		

		cout << endl;
		cout << "V" << endl;

		for (int i=0; i<number_of_cities; i++) {
			for (int j=0; j<number_of_cities; j++) {
				cout << V[i][j] << "  ";
			}
			cout << endl;
		}		
}

int find_longest_path(int number_of_cities, vector<vector <int> > &E,
						vector<vector <int> > &V, vector<int>* path, vector<int> &number_vector) {
	vector<int> longest_path;
	vector<int> current_path;

	int max = 0;

	for (int i = 0; i<number_of_cities; i++) {
			int last = i;
			int count = 0;

			current_path.clear();
			current_path.push_back(i);

	 		find_path_helper(number_of_cities, V, last, count, max, longest_path, current_path, number_vector);
	}
	
	if (longest_path.size() == 0) {
		return 0;
	}
	
	*path = longest_path;
	return find_min(path, V);
}

int main(int argc, char* argv[]) {
	int number_of_cases;	
	cin >> number_of_cases;

	for (int i=0; i<number_of_cases; i++) {
		int number_of_cities;
		cin >> number_of_cities;
		vector<vector <int> > E;
		vector<vector <int> > V;

		expanding_matrices(E, V, number_of_cities);
		vector<int> number_vector = making_matrices(E, V, number_of_cities);

		int number_of_bicyles = 0;
		bool finished = false;
		vector<int>* path = new vector<int>();

		do {
			path->clear();
			int min_bicycle = find_longest_path(number_of_cities, E, V, path, number_vector);
			//cout << "min_bicycle: " << min_bicycle << endl;


			if ( min_bicycle > 0 ) {
				deducting_process(path, V, min_bicycle);
				number_of_bicyles += min_bicycle;

			}else {
				finished = true;
			}

			//print_matrices(E, V, number_of_cities);
		} while ( !finished );

		cout << "Case #" << i+1 << ": " << number_of_bicyles << endl;

	}

	return 0;
}