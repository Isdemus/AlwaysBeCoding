#include <list>
#include <unordered_set>
#include <unordered_map>

#include <iostream>
#include <cassert>
#include <sstream>

#define MP(a, b) (std::make_pair(a, b))

using namespace std;

// Struct for an edge information
typedef struct NodeInfo {
	int parent; // Child has only one parent for a valid tree
	int length; // Max path length from the farthest leaf
} NodeInfo;

// Recursive function to return a longest length from a leaf
int GetLongestLength(int child_index, unordered_map<int, NodeInfo *> &tree_info)
{
	NodeInfo *child_info = tree_info[child_index];
	assert(child_info != nullptr);
	int parent_index = child_info->parent;
	assert(parent_index >= 0); // Cannot be a negative value

	NodeInfo *parent_info = tree_info[parent_index];
	if (parent_info == nullptr) { // Stopping condition
		return (child_info->length + 1);
	} else if (parent_info->length >= (child_info->length + 1)) { // The other child ran through already
		return -1;
	}

	parent_info->length += 1;

	return GetLongestLength(parent_index, tree_info);
}

// Getting input data from stdin
list<pair<int, int>> GetDataFromStd(void)
{
	list<pair<int, int>> retval;
	int first, second;
	stringstream ss; // That will be used to split two numbers
	string line;

	// Assuming the input is in the right format
	while (getline(cin, line))
	{
		ss << line;
		ss >> first >> second;
		ss.clear();

		retval.push_front(MP(first, second));
	}
	
	return retval;
}

int main(int argc, char *argv[])
{
	// Input data
	list<pair<int, int>> _graph_info = GetDataFromStd();

	// Set for nodes that do not have a child (i.e., leaf)
	unordered_set<int> leaf_set;

	// Set for nodes that has at least one child
	unordered_set<int> parent_set;

	// Map for the relationship between the node and its parents
	unordered_map<int, NodeInfo *> tree_info;

	// Storing the necessary data
	for (const auto &pair : _graph_info)
	{
		assert(tree_info[pair.second] == nullptr);

		// Info for the child
		tree_info[pair.second] = new NodeInfo {pair.first, 0};

		// If the child node is in parent_set, do not add it to leaf_set
		if (parent_set.find(pair.second) == parent_set.end())
		{
			leaf_set.insert(pair.second);
		}

		// If the parent node is in the leaf_set, erase it and insert it to the parent_set
		if (leaf_set.find(pair.first) != leaf_set.end())
		{
			leaf_set.erase(pair.first);
			parent_set.insert(pair.first);
		}
	}

	// 4 Bytes integer can handle for the max length (i.e., 99,999)
	int _longest_length = -1;

	// Begin from the leaf nodes
	for (const auto &leaf : leaf_set)
	{
		int leng = GetLongestLength(leaf, tree_info);
		_longest_length = (_longest_length >= leng ? _longest_length : leng);
	}

	// Freeing every dynamically allocated NodeInfo's
	for (auto info : tree_info)
	{
		free(tree_info[info.first]);
	}

	cout << "The longest path has a length : " << _longest_length << endl;

	return 0;
}
