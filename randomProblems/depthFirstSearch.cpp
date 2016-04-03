#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

/*
Question:
Create an efficient program, a4.cpp, that given an adjacency-list representation of a directed graph prints out the root and the tree edges that would be generated if a DFS is started at vertex one and vertices were always considered in ascending order.

Input Specification
A sample input would look like the following.

6
1 : 2 4
2 : 5
3 : 5 6
4 : 2
5 : 4
6 : 6

 The input will come from cin.
 The input will consist of the number of vertices on a single line, followed by adjacency lists.
 If there are n vertices, they will always be labelled 1, 2, 3, . . . n.
 For a graph with n vertices, the input file will always consist of n+1 lines: one line for the header, which specifies the number of vertices, and then n lines, one for each vertex.
 The vertices in the input file will alway be listed in ascending order, i.e. vertex 1 on line 2, vertex 2 on line 3, etc.
 The vertices in each adjacency list, (i.e the part that occurs after the colon) will be listed in ascending order.
 The format for an adjacency list will be the tail vertex, followed by a space, followed by a colon, followed by a space, and then followed by a (possibly empty) list of adjacent vertices. I.e. there is a single blank space between any two vertices and between a vertex and the colon.
 If a vertex, say 4, had no adjacent vertices, it would appear in the list as "4 : ", i.e. 4 followed by a space, followed by a colon, followed by a space.
 There are at most 10; 000 vertices in any input file.
 The graph may or may not be connected.
 The input will always consist of at least one vertex.
 There will be no errors in the input.

Output Specification
The output for the sample input given above would look like the following.
1 root
1 2
2 5
5 4
3 root
3 6
 The output should be directed to cout.
 Each line of the output will either specify a root vertex (i.e., a vertex x that is an initial call to DFSvisit) or an edge.
 When outputting a tree, first output the vertex corresponding to the root, then specify each edge in the tree.
 A root will be specified by the root vertex, followed by a space, followed by the word
root.
 The vertices and edges in the output should be listed in the order they would occur
when doing a DFS search starting at vertex 1, as described above. The sample output
indicates that the tree edges are found in the order 12; 25; 54; 36. The two initial calls to DFSvisit are DFSvisit(1) and DFSvisit(3).
 On a line that species an edge, there is one vertex (the tail), followed by a single space, followed by another vertex (the head), followed by a newline.
*/

//global variable(data structure):
vector<vector<int>> dag;

void readinput(int number) {
    string input;
    getline(cin, input);
    for(int i=0; i<number; i++) {
        getline(cin, input);
        vector<int> vec;
        bool isStart = false;
        int num = 0;
        for(int k=0; k<=input.size(); k++) {
            char c = input[k];
            if (c == ':' ) {
                isStart = true;
            }
            else if (isspace(c)) {
                // space
                if (num) {
                    vec.push_back(num);
                    num = 0;
                }
            }
            else if (isdigit(c) && isStart) {
                num *= 10;
                int digit = 0;
                stringstream ss;
                ss << c;
                ss >> digit;
                num += digit;
                
                if(k==input.size()-1) {
                    vec.push_back(num);
                }
            }
        }
        
        dag.push_back(vec);
    }
}

void dfsvisit(int i, int& Time, int *track, int *color, int *discover, int *finish) {
    color[i] = 1; // 1 means grey
    Time = Time + 1;
    discover[i] = Time;
    
    vector<int> a = dag[i];
    for(int k=0; k<a.size(); k++) {
        int t = a.at(k);
        if(color[t-1] == 0) {
            track[t-1] = i;
            cout << i+1 << " " << t << endl;
            dfsvisit(t-1, Time, track, color, discover, finish);
        }
    }
    
    color[i] = 2;
    Time = Time + 1;
    finish[i] = Time;
}

void dfs(int *track, int *color, int *discover, int *finish, int SIZE) {
    for(int i=0; i<SIZE; i++) {
        color[i] = 0; //0 means white
        if( track == NULL ) {cout << "Track is Null\n";}
    }
    
    int Time = 0;
    for (int i=0; i<SIZE; i++) {
        if(color[i] == 0) {
            cout << i+1 << " root" << endl;
            dfsvisit(i, Time, track, color, discover, finish);
        }
    }
}

int main() {
    int number, input;
    cin >> input;
    number = input;
    
    readinput(number);
    
    int *track    = new int[number];
    int *color    = new int[number];
    int *discover = new int[number];
    int *finish   = new int[number];

    dfs(track, color, discover, finish, number);
    
    return 0;
}