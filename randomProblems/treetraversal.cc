#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

struct Node {
	Node* leftchild;
	Node* rightchild;
	int value;
	Node(int val) : leftchild(nullptr), rightchild(nullptr), value(val) {};
};

void MatrixMethod(Node* node, std::vector<std::vector<int>*> &matrix, unsigned int row) {
	// Using postorder tree traversal
	if (node->leftchild != nullptr)
		MatrixMethod(node->leftchild, matrix, row + 1);
	if (node->rightchild != nullptr)
		MatrixMethod(node->rightchild, matrix, row + 1);

	// Self
	while (row + 1 > matrix.size()) {
		matrix.push_back(nullptr);
	}
	if (matrix[row] == nullptr) {
		std::vector<int> *matrixrow = new std::vector<int>();
		matrix[row] = matrixrow;
	}

	matrix[row]->push_back(node->value);
}

void PrintMatrix(const std::vector<std::vector<int>*> &treematrix) {
	for (int index = treematrix.size() - 1; index >= 0; index--) {
		auto matrixrow = treematrix[index];
		if (index%2 == 0) {
			for (std::vector<int>::iterator it = matrixrow->end() - 1; it >= matrixrow->begin(); it--)
				cout << *it << " ";
		} else {
			for (std::vector<int>::iterator it = matrixrow->begin(); it < matrixrow->end(); it++)
				cout << *it << " ";
		}
	}
	cout << endl;
}

void PrintStack(std::stack<Node*> &st) {
	while (!st.empty()) {
		Node* node = st.top();
		cout << node->value << " ";
		st.pop();
	}
	cout << endl;
}

int main(int argc, char* argv[]) {
	Node* root = new Node(15);
	// Tree Makeup
	{
		root->leftchild = new Node(13);
		root->rightchild = new Node(14);
		root->leftchild->leftchild = new Node(12);
		root->leftchild->rightchild = new Node(11);
		root->rightchild->leftchild = new Node(10);
		root->rightchild->rightchild = new Node(9);

		Node* node1 = root->leftchild->leftchild;
		Node* node2 = root->leftchild->rightchild;
		Node* node3 = root->rightchild->leftchild;
		Node* node4 = root->rightchild->rightchild;

		node4->rightchild = new Node(8);
		node4->leftchild = new Node(7);
		node3->rightchild = new Node(6);
		node3->leftchild = new Node(5);
		node2->rightchild = new Node(4);
		node2->leftchild = new Node(3);
		node1->rightchild = new Node(2);
		node1->leftchild = new Node(1);

		node2->leftchild->leftchild = new Node(0);
		node2->leftchild->rightchild = new Node(-1);
	}

	// First way ( use matrix )
	std::vector<std::vector<int>*> treematrix;
	MatrixMethod(root, treematrix, 0);	

	// Printing
	PrintMatrix(treematrix);

	// Second way ( use priority_queue with FILO )
	auto NodeCompare = [] (std::pair<Node*, unsigned int> oldnode,
																	std::pair<Node*, unsigned int> newnode) {
		if (oldnode.second >= newnode.second)
			return true;
		return false;
	};
	
	std::stack<Node*> st;
	std::priority_queue<std::pair<Node*, int>,
											std::vector<std::pair<Node*, int>>,
											decltype(NodeCompare)> pst(NodeCompare);
	st.push(root);
	pst.push(std::make_pair(root, 0));

	while (!pst.empty()) {
		std::pair<Node*, int> element = pst.top();
		Node* node = element.first;
		unsigned int height = element.second;
		pst.pop();

		if (height % 2 == 0) {
			if (node->rightchild != nullptr) {
				pst.push(std::make_pair(node->rightchild, height + 1));
				st.push(node->rightchild);
			}
			if (node->leftchild != nullptr) {
				pst.push(std::make_pair(node->leftchild, height + 1));
				st.push(node->leftchild);
			}
		} else {
			if (node->leftchild != nullptr) {
				pst.push(std::make_pair(node->leftchild, height + 1));
				st.push(node->leftchild);
			}
			if (node->rightchild != nullptr) {
				pst.push(std::make_pair(node->rightchild, height + 1));
				st.push(node->rightchild);
			}
		}
	}
	PrintStack(st);

	// Third way (BFS using a queue and a stack)
	std::queue<std::pair<Node*, int>> quebfs;
	std::stack<std::pair<Node*, int>> stackbfs;
	std::stack<Node*> outstack;

	outstack.push(root);
	quebfs.push(std::make_pair(root, 0));

	while (!quebfs.empty()) {
		Node* node = quebfs.front().first;
		int height = quebfs.front().second;
		quebfs.pop();
		if (height % 2 == 0) {
			if (node->rightchild != nullptr) {
				stackbfs.push(std::make_pair(node->rightchild, height + 1));
				outstack.push(node->rightchild);
			}
			if (node->leftchild != nullptr) {
				stackbfs.push(std::make_pair(node->leftchild, height + 1));
				outstack.push(node->leftchild);
			}
		} else {
			if (node->leftchild != nullptr) {
				stackbfs.push(std::make_pair(node->leftchild, height + 1));
				outstack.push(node->leftchild);
			}
			if (node->rightchild != nullptr) {
				stackbfs.push(std::make_pair(node->rightchild, height + 1));
				outstack.push(node->rightchild);
			}
		}

		if (quebfs.empty()) {
			while (!stackbfs.empty()) {
				quebfs.push(stackbfs.top());
				stackbfs.pop();
			}
		}
	}
	PrintStack(outstack);
	return 0;
}
