#include <iostream>
#include <vector>

#define NULLMARKER -10

typedef struct Node {
	Node() : value(0), left(nullptr), right(nullptr) {}
	Node(int val) : value(val), left(nullptr), right(nullptr) {}
	int value;
	struct Node *left;
	struct Node *right;
} Node;

void SerializeHelper(std::vector<int> *vec, Node *node)
{
	if (node) {
		vec->push_back(node->value);
		SerializeHelper(vec, node->left);
		SerializeHelper(vec, node->right);
	} else {
		vec->push_back(NULLMARKER);
	}
}

std::vector<int> * Serialize(Node *node)
{
	std::vector<int> *vec = new std::vector<int>();
	vec->reserve(10);

	SerializeHelper(vec, node);
	return vec;
}

void DeserializeHelper(std::vector<int> *vec, int &pos, Node *node)
{
	if (pos >= vec->size()) {return;}
	node->value = vec->at(pos);
	if (node->value != NULLMARKER) {
		Node *left  = new Node();
		Node *right = new Node();
		node->left  = left;
		node->right = right;

		DeserializeHelper(vec, ++pos, left);
		DeserializeHelper(vec, ++pos, right);
		if (left->value == NULLMARKER) {
			free(left);
			node->left = nullptr;
		}
		if (right->value == NULLMARKER) {
			free(right);
			node->right = nullptr;
		}
	}
}

Node * Deserialize(std::vector<int> *vec)
{
	int pos = 0;
	Node *root = new Node();
	DeserializeHelper(vec, pos, root);

	return root;
}

void PrintingPreOrder(Node *node)
{
	if (node) {
		std::cout << node->value << "  ";
		PrintingPreOrder(node->left);
		PrintingPreOrder(node->right);
	}
}

void FreeTree(Node *node)
{
	if (node) {
		FreeTree(node->left);
		FreeTree(node->right);
		free(node);
	}
}

int main(int argc, char *argv[])
{
	Node *root = new Node(0);
	Node *firstnode  = new Node(1);
	Node *secondnode = new Node(2);
	Node *thirdnode  = new Node(3);
	Node *fourthnode = new Node(4);

	root->left = firstnode;
	root->right = fourthnode;
	firstnode->left = secondnode;
	firstnode->right = thirdnode;

	std::cout << "Printing the original tree that will be serialized" << std::endl;
	PrintingPreOrder(root);
	std::cout << std::endl;
	std::vector<int> *firsttree = Serialize(root);

	Node *newroot = Deserialize(firsttree);

	std::cout << "Printing a new tree created by deserializing the original tree" << std::endl;
	PrintingPreOrder(newroot);
	std::cout << std::endl;

	FreeTree(root);
	FreeTree(newroot);

	return 0;
}
