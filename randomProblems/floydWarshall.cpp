#include <iostream>
#include <vector>

#define INFINITY 1000
#define NIL -1

using namespace std;

//global variables that we will use
int num_vertices = 0;
int num_edges = 0;

//initializing w[][] first with diagonal zero and the others infinity
void initializing_w(int** w) {
	for(int i=0; i<num_vertices; i++) {
		for(int j=0; j<num_vertices; j++) {
			if(i==j) { w[i][j] = 0; }
			else { w[i][j] = INFINITY; }
		}
	}
}

void read_edges(int** w, int& dept, int& dest) {
	int input, v1, v2, weight;
	for(int i=0; i<num_edges; i++) {
		cin >> v1;
		cin >> v2;
		cin >> weight;

		w[v1-1][v2-1] = weight;
	}

	cin >> input;
	dept = input - 1;
	cin >> input;
	dest = input - 1;
}

//Initializing Pi(P)
void initializing_pi(int** p, int** w) {
	for(int i=0; i<num_vertices; i++) {
		for(int j=0; j<num_vertices; j++) {
			if(i == j || w[i][j] == INFINITY) { p[i][j] = NIL; }
			else { p[i][j] = i; }
		}
	}
}


void find_sPath(int** p, int** w) {
	for(int m=0; m<num_vertices; m++) {
		for(int i=0; i<num_vertices; i++) {
			for(int j=0; j<num_vertices; j++) {
				if(w[i][j] > w[i][m] + w[m][j]) {
					w[i][j] = w[i][m] + w[m][j];
					p[i][j] = m;
				}
			}
		}
	}
}

void print_sPath(vector <int> path, int** p, int** w, int dept, int dest) {
	int v = p[dept][dest];

	while(v != dept && v>=0) {
		path.push_back(v);
		v = p[dept][v];
	}

	cout << dept+1 << endl;
	for(int i=path.size()-1; i>=0; i--) {
		cout << path[i] + 1 << endl;
	}
	cout << dest+1 << endl;
	cout << w[dept][dest] << endl;
}

int main(int argc, char *argv[]) {
	int input, dept, dest;

	cin >> input;
	num_vertices = input;
	cin >> input;
	num_edges = input;

	int** w = new int*[num_vertices];
	int** p = new int*[num_vertices];
	vector <int> path;

	//allocating memories for w and p
	for(int i=0; i<num_vertices; i++) {
		w[i] = new int[num_vertices];
		p[i] = new int[num_vertices];
	}

	initializing_w(w);
	read_edges(w, dept, dest);
	initializing_pi(p, w);
	find_sPath(p, w);
	
	if(w[dept][dest] == INFINITY) { cout << -1 << endl; }
	else { print_sPath(path, p, w, dept, dest); }
	
	return 0;
}